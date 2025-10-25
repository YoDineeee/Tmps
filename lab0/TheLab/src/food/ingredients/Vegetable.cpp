#include "Vegetable.h"

namespace food::ingredients {
Vegetable::Vegetable(std::string n,std::string d,bool organic)
    : AbstractIngredient(std::move(n),std::move(d)), organic_(organic) {}
bool Vegetable::isOrganic() const { return organic_; }
} // namespace food::ingredients

