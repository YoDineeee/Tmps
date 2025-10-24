#pragma once

#include "AbstractIngredient.h"

namespace food::ingredients {

class Lavash : public AbstractIngredient {
public:
    Lavash(std::string name, std::string description, bool isCheesy);

    bool isCheesy() const;

private:
    bool isCheesy_;
};

} // namespace food::ingredients