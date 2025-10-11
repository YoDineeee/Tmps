// this example from chat ...looking around :)

#include <iostream>
#include <memory>
#include <vector>
#include <string>

// -----------------------------
// Domain objects
// -----------------------------
class Message {
    std::string title_;
    std::string body_;
public:
    Message(std::string title, std::string body)
      : title_(std::move(title)), body_(std::move(body)) {}

    const std::string& title() const { return title_; }
    const std::string& body()  const { return body_;  }
};

// -----------------------------
// Dependency Inversion: abstractions
// High-level modules depend on these interfaces, not concrete classes.
// -----------------------------
struct IFormatter {
    virtual ~IFormatter() = default;
    virtual std::string format(const Message& m) const = 0;
};

struct INotifier {
    virtual ~INotifier() = default;
    virtual void send(const std::string& formattedMessage) const = 0;
};

// -----------------------------
// Single Responsibility: concrete formatter only formats.
// -----------------------------
class SimpleFormatter : public IFormatter {
public:
    std::string format(const Message& m) const override {
        return "[" + m.title() + "] " + m.body();
    }
};

// Another formatter (shows Open/Closed: we can add new formatters without changing existing code)
class JsonFormatter : public IFormatter {
public:
    std::string format(const Message& m) const override {
        return "{ \"title\": \"" + m.title() + "\", \"body\": \"" + m.body() + "\" }";
    }
};

// -----------------------------
// Concrete notifiers: each has one responsibility: send via a specific channel.
// Adding a new notifier doesn't change existing code (Open/Closed).
// -----------------------------
class EmailNotifier : public INotifier {
    std::string emailAddress_;
public:
    EmailNotifier(std::string addr) : emailAddress_(std::move(addr)) {}
    void send(const std::string& formattedMessage) const override {
        std::cout << "Sending EMAIL to " << emailAddress_ << ": " << formattedMessage << "\n";
    }
};

class SmsNotifier : public INotifier {
    std::string phone_;
public:
    SmsNotifier(std::string phone) : phone_(std::move(phone)) {}
    void send(const std::string& formattedMessage) const override {
        std::cout << "Sending SMS to " << phone_ << ": " << formattedMessage << "\n";
    }
};

// New notifier can be added without touching NotificationService (Open/Closed).
class PushNotifier : public INotifier {
    std::string deviceId_;
public:
    PushNotifier(std::string id) : deviceId_(std::move(id)) {}
    void send(const std::string& formattedMessage) const override {
        std::cout << "Sending PUSH to device " << deviceId_ << ": " << formattedMessage << "\n";
    }
};

// -----------------------------
// NotificationService:
// - Depends on abstractions (IFormatter, INotifier) -> Dependency Inversion
// - Has one responsibility: coordinate formatting + notifying -> Single Responsibility
// - Closed for modification: to extend behavior add new INotifier implementations -> Open/Closed
// -----------------------------
class NotificationService {
    std::shared_ptr<IFormatter> formatter_;
    std::vector<std::shared_ptr<INotifier>> notifiers_;
public:
    // Dependency Injection via constructor
    NotificationService(std::shared_ptr<IFormatter> formatter,
                        std::vector<std::shared_ptr<INotifier>> notifiers)
      : formatter_(std::move(formatter)), notifiers_(std::move(notifiers)) {}

    void notify(const Message& m) const {
        const auto formatted = formatter_->format(m);
        for (const auto& notifier : notifiers_) {
            notifier->send(formatted);
        }
    }
};

// -----------------------------
// Demo (main)
// -----------------------------
int main() {
    // Create formatter (could swap to JsonFormatter without changing NotificationService)
    auto formatter = std::make_shared<SimpleFormatter>();

    // Create notifier implementations (concrete classes)
    std::vector<std::shared_ptr<INotifier>> notifiers;
    notifiers.push_back(std::make_shared<EmailNotifier>("alice@example.com"));
    notifiers.push_back(std::make_shared<SmsNotifier>("+123456789"));
    // Add a new notifier later (demonstrates Open/Closed)
    notifiers.push_back(std::make_shared<PushNotifier>("device-42"));

    // Inject dependencies into service
    NotificationService service(formatter, notifiers);

    // Create a message and send
    Message msg("ServerDown", "The web server is unreachable since 10:13 UTC.");
    service.notify(msg);

    // Swap formatter at runtime: still works because NotificationService depends on IFormatter.
    auto jsonFormatter = std::make_shared<JsonFormatter>();
    NotificationService serviceWithJson(jsonFormatter, notifiers);
    Message msg2("Deploy", "Version 1.2.3 was deployed successfully.");
    serviceWithJson.notify(msg2);

    return 0;
}
