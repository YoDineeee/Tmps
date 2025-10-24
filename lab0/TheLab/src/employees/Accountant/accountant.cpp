#include <iostream>
#include <memory>
#include <unordered_set>
#include "Accountant.h"
#include "Employee.h"                      // Assuming Employee interface is here
#include "SubordinatesManager.h"          // From employees/common/

namespace employees::accountant {

Accountant::Accountant(
    std::string name,
    double salary,
    std::unordered_set<std::shared_ptr<employees::Employee>> subordinates)
    : name(std::move(name))
    , salary(salary)
    , subordinates(std::make_unique<employees::common::SubordinatesManager>(
          std::move(subordinates))) {}

double Accountant::getSalary() const {
    return salary;
}

std::string Accountant::getName() const {
    return name;
}

void Accountant::paySalariesTo(const std::shared_ptr<employees::Employee>& employee) {
    std::cout << "Paying " << employee->getName()
              << " $" << employee->getSalary() << '\n';
}

void Accountant::work() {
    std::cout << "I'm an accountant, I'm working\n";
    for (const auto& emp : subordinates->getSubordinates()) {
        paySalariesTo(emp);
    }
    std::cout << "Paying myself, " << name << " $" << salary << '\n';
}

} 