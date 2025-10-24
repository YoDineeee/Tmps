#pragma once

#include "AbstractIngredient.h"

namespace food::ingredients {

class Vegetable : public AbstractIngredient {
public:
    Vegetable(std::string name, std::string description, bool isOrganic);

    bool isOrganic() const;

private:
    bool isOrganic_;
};

} // namespace food::ingredients