#include "Sauce.h"

namespace food::ingredients {
Sauce::Sauce(std::string n,std::string d,bool spicy)
    : AbstractIngredient(std::move(n),std::move(d)), spicy_(spicy) {}
bool Sauce::isSpicy() const { return spicy_; }
} // namespace food::ingredients
