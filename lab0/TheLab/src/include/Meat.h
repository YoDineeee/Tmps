#pragma once
#include "AbstractIngredient.h"
#include "MeatType.h"
#include <string>

namespace food::ingredients::meat {

class Meat : public AbstractIngredient {
public:
    // Use the enums under food::ingredients::enums
    explicit Meat(std::string name, food::ingredients::enums::MeatType type);

    // Keep an explicit description implementation
    std::string getDescription() const override;

private:
    food::ingredients::enums::MeatType type_;
};

} // namespace food::ingredients::meat
