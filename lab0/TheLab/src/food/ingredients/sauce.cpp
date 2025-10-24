#include "Sauce.h"

namespace food::ingredients {

Sauce::Sauce(
    std::string name,
    std::string description,
    bool isSpicy)
    : AbstractIngredient(std::move(name), std::move(description))
    , isSpicy_(isSpicy) {}

bool Sauce::isSpicy() const {
    return isSpicy_;
}

} // namespace food::ingredients