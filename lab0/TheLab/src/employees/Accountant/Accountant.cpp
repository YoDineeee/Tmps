#include "Accountant.h"
#include "SubordinatesManager.h"
#include "Employee.h"
#include <iostream>

namespace employees::accountant {

Accountant::Accountant(std::string n, double s,
    std::unordered_set<std::shared_ptr<employees::Employee>> subs)
    : name(std::move(n)), salary(s),
      subsMgr(std::make_unique<employees::common::SubordinatesManager>(std::move(subs))) {}

double Accountant::getSalary() const { return salary; }
std::string Accountant::getName() const { return name; }

void Accountant::work() {
    std::cout << name << " (Accountant) is calculating salaries...\n";
    for (auto& e : subsMgr->getSubordinates())
        pay(e);
}

void Accountant::pay(const std::shared_ptr<employees::Employee>& e) {
    if (!e) return;
    std::cout << "Paid " << e->getName()
              << " salary: " << e->getSalary() << " EUR\n";
}

} // namespace employees::accountant
