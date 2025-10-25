#include "SubordinatesManager.h"
#include "Employee.h"

namespace employees::common {

SubordinatesManager::SubordinatesManager(
    std::unordered_set<std::shared_ptr<employees::Employee>> subs)
    : subordinates(std::move(subs)) {}

const std::unordered_set<std::shared_ptr<employees::Employee>>&
SubordinatesManager::getSubordinates() const { return subordinates; }

void SubordinatesManager::addSubordinate(const std::shared_ptr<employees::Employee>& e) {
    subordinates.insert(e);
}
void SubordinatesManager::removeSubordinate(const std::shared_ptr<employees::Employee>& e) {
    subordinates.erase(e);
}

} // namespace employees::common
