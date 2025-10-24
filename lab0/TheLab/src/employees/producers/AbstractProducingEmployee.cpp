#include "AbstractProducingEmployee.h"
#include "MenuItem.h" // Assuming MenuItem is defined here

namespace employees::producers {

AbstractProducingEmployee::AbstractProducingEmployee(
    std::string name, double salary)
    : name(std::move(name))
    , salary(salary) {}

std::string AbstractProducingEmployee::getName() const {
    return name;
}

double AbstractProducingEmployee::getSalary() const {
    return salary;
}

// giveRequest is pure virtual → not implemented here

} // namespace employees::producers