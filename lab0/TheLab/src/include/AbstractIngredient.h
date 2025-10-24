#pragma once

#include "Ingredient.h"
#include <string>

namespace food::ingredients {

class AbstractIngredient : public virtual Ingredient {
public:
    AbstractIngredient(std::string name, std::string description);

    std::string getName() const override;
    std::string getDescription() const override;

protected:
    std::string name_;
    std::string description_;
};

} // namespace food::ingredients
