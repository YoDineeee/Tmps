#pragma once

#include "AbstractIngredient.h"

namespace food::ingredients {

class Sauce : public AbstractIngredient {
public:
    Sauce(std::string name, std::string description, bool isSpicy);

    bool isSpicy() const;

private:
    bool isSpicy_;
};

} // namespace food::ingredients