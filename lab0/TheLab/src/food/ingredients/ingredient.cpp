#include "Ingredient.h"
#include <ostream>

namespace food::ingredients {

Ingredient::Ingredient(std::string name) : name_(std::move(name)) {}

const std::string& Ingredient::getName() const {
    return name_;
}

std::string Ingredient::toString() const {
    return "Ingredient{name=\"" + name_ + "\"}";
}

std::ostream& operator<<(std::ostream& os, const Ingredient& ingredient) {
    return os << ingredient.toString();
}

} // namespace food::ingredients