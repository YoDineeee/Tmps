#pragma once
#include <memory>
#include <unordered_set>

namespace employees { class Employee; }

namespace employees::common {
class SubordinatesManager {
public:
    explicit SubordinatesManager(std::unordered_set<std::shared_ptr<employees::Employee>> subordinates = {});
    const std::unordered_set<std::shared_ptr<employees::Employee>>& getSubordinates() const;
    void addSubordinate(const std::shared_ptr<employees::Employee>& employee);
    void removeSubordinate(const std::shared_ptr<employees::Employee>& employee);
private:
    std::unordered_set<std::shared_ptr<employees::Employee>> subordinates;
};
} // namespace employees::common
