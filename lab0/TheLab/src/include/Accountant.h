#pragma once

#include <string>
#include <memory>
#include <unordered_set>

// Forward declarations
namespace employees {
    class Employee;
}

namespace employees::common {
    class SubordinatesManager;
}

namespace employees::accountant {

class Accountant : public employees::Employee {
public:
    Accountant(std::string name, double salary,
               std::unordered_set<std::shared_ptr<employees::Employee>> subordinates);

    double getSalary() const override;
    std::string getName() const override;
    void work() override;

private:
    void paySalariesTo(const std::shared_ptr<employees::Employee>& employee);

    std::string name;
    double salary;
    std::unique_ptr<employees::common::SubordinatesManager> subordinates;
};

} 