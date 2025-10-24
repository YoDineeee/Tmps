#include "Meat.h"
#include <string>

namespace food::ingredients::meat {

Meat::Meat(std::string name, enums::MeatType type)
    : name_(std::move(name))
    , type_(type) {}

std::string Meat::getName() const {
    return name_;
}

std::string Meat::getDescription() const {
    return std::string("Meat: ") + std::string(enums::toString(type_));
}

} // namespace food::ingredients::meat