#pragma once
#include "Employee.h"
#include <memory>
#include <unordered_set>

namespace employees::common { class SubordinatesManager; }

namespace employees::accountant {
class Accountant : public employees::Employee {
public:
    Accountant(std::string name, double salary,
               std::unordered_set<std::shared_ptr<employees::Employee>> subs);
    double getSalary() const override;
    std::string getName() const override;
    void work() override;
private:
    void pay(const std::shared_ptr<employees::Employee>& e);
    std::string name;
    double salary;
    std::unique_ptr<employees::common::SubordinatesManager> subsMgr;
};
} // namespace employees::accountant
