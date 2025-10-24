#include <iostream>
#include <memory>
#include "Manager.h"
#include "Employee.h"
#include "SubordinatesManager.h"

namespace employees::director {

Manager::Manager(
    std::string name,
    double salary,
    std::unordered_set<std::shared_ptr<employees::Employee>> subordinates)
    : name(std::move(name))
    , salary(salary)
    , subordinatesManager(
          std::make_unique<employees::common::SubordinatesManager>(
              std::move(subordinates))) {}

double Manager::getSalary() const {
    return salary;
}

std::string Manager::getName() const {
    return name;
}

void Manager::work() {
    std::cout << "Manager " << name << " is managing the team\n";
    for (const auto& employee : subordinatesManager->getSubordinates()) {
        if (employee) {
            std::cout << "Manager " << name
                      << " is now managing " << employee->getName() << '\n';
            employee->work();
        }
    }
}

} 