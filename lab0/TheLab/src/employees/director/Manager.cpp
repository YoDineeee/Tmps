#include "Manager.h"
#include "SubordinatesManager.h"
#include "Employee.h"
#include <iostream>

namespace employees::director {

Manager::Manager(std::string n, double s,
                 std::unordered_set<std::shared_ptr<employees::Employee>> subs)
    : name(std::move(n)), salary(s),
      subsMgr(std::make_unique<employees::common::SubordinatesManager>(std::move(subs))) {}

double Manager::getSalary() const { return salary; }
std::string Manager::getName() const { return name; }

void Manager::addSubordinate(const std::shared_ptr<employees::Employee>& e) {
    subsMgr->addSubordinate(e);
}
void Manager::removeSubordinate(const std::shared_ptr<employees::Employee>& e) {
    subsMgr->removeSubordinate(e);
}

void Manager::work() {
    std::cout << name << " (Manager) is managing " 
              << subsMgr->getSubordinates().size() << " subordinates.\n";
    for (auto& emp : subsMgr->getSubordinates())
        emp->work();
}

} // namespace employees::director
