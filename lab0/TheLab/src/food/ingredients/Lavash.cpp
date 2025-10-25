

#include "Lavash.h"

namespace food::ingredients {

Lavash::Lavash(std::string name, std::string description, bool isCheesy)
    : AbstractIngredient(std::move(name), std::move(description))
    , isCheesy_(isCheesy) {}

bool Lavash::isCheesy() const { return isCheesy_; }

} // namespace food::ingredients
