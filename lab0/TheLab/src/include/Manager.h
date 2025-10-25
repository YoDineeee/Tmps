#pragma once

#include <memory>
#include <unordered_set>
#include <string>

namespace employees { class Employee; }
namespace employees::common { class SubordinatesManager; }

namespace employees::director {
class Manager : public employees::Employee {
public:
    Manager(std::string name, double salary,
            std::unordered_set<std::shared_ptr<employees::Employee>> subs);
    double getSalary() const override;
    std::string getName() const override;
    void work() override;
    void addSubordinate(const std::shared_ptr<employees::Employee>& e);
    void removeSubordinate(const std::shared_ptr<employees::Employee>& e);
private:
    std::string name;
    double salary;
    std::unique_ptr<employees::common::SubordinatesManager> subsMgr;
};
} // namespace employees::director
