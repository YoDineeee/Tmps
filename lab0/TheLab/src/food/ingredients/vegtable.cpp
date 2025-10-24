#include "Vegetable.h"

namespace food::ingredients {

Vegetable::Vegetable(
    std::string name,
    std::string description,
    bool isOrganic)
    : AbstractIngredient(std::move(name), std::move(description))
    , isOrganic_(isOrganic) {}

bool Vegetable::isOrganic() const {
    return isOrganic_;
}

} // namespace food::ingredients