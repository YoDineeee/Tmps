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

namespace employees::director {

class Manager : public employees::Employee {
public:
    Manager(std::string name,
            double salary,
            std::unordered_set<std::shared_ptr<employees::Employee>> subordinates);

    double getSalary() const override;
    std::string getName() const override;
    void work() override;

private:
    std::string name;
    double salary;
    std::unique_ptr<employees::common::SubordinatesManager> subordinatesManager;
};

} 