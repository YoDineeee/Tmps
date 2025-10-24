#include "SubordinatesManager.h"
#include "Employee.h" // For completeness (though not strictly needed here)

namespace employees::common {

SubordinatesManager::SubordinatesManager(
    std::unordered_set<std::shared_ptr<employees::Employee>> subordinates)
    : subordinates(std::move(subordinates)) {
    // In C++, we don't get "null container" — empty set is default
    // So no need for null check like in Java
}

const std::unordered_set<std::shared_ptr<employees::Employee>>&
SubordinatesManager::getSubordinates() const {
    return subordinates;
}

void SubordinatesManager::setSubordinates(
    std::unordered_set<std::shared_ptr<employees::Employee>> newSubordinates) {
    subordinates = std::move(newSubordinates);
}

void SubordinatesManager::addSubordinate(
    const std::shared_ptr<employees::Employee>& employee) {
    if (employee) {
        subordinates.insert(employee);
    }
    // Optionally: ignore null (but shared_ptr should not be null if designed well)
}

void SubordinatesManager::removeSubordinate(
    const std::shared_ptr<employees::Employee>& employee) {
    if (employee) {
        subordinates.erase(employee);
    }
}

} 