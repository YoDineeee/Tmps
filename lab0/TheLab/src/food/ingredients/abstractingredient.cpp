#include "AbstractIngredient.h"

namespace food::ingredients {

AbstractIngredient::AbstractIngredient(
    std::string name,
    std::string description)
    : name_(std::move(name))
    , description_(std::move(description)) {}

std::string AbstractIngredient::getName() const {
    return name_;
}

std::string AbstractIngredient::getDescription() const {
    return description_;
}

} // namespace food::ingredients