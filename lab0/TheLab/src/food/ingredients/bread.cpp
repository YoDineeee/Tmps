#include "Bread.h"

namespace food::ingredients {

Bread::Bread(
    std::string name,
    std::string description,
    bool isCheesy)
    : AbstractIngredient(std::move(name), std::move(description))
    , isCheesy_(isCheesy) {}

bool Bread::isCheesy() const {
    return isCheesy_;
}

} // namespace food::ingredients

