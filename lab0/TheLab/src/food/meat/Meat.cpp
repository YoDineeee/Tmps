#include "Meat.h"
#include "MeatType.h"

namespace food::ingredients::meat {

Meat::Meat(std::string n, food::ingredients::enums::MeatType t)
    : AbstractIngredient(std::move(n), std::string(food::ingredients::enums::toString(t)))
    , type_(t) {}

std::string Meat::getDescription() const {
    return "Meat: " + std::string(food::ingredients::enums::toString(type_));
}

} // namespace food::ingredients::meat
