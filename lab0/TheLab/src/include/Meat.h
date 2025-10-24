#include "Ingredient.h"

namespace food::ingredients::meat {

class Meat : public food::ingredients::Ingredient {
public:
    Meat(std::string name, enums::MeatType type);

    std::string getName() const override;
    std::string getDescription() const override;

private:
    std::string name_;
    enums::MeatType type_;
};

} // namespace food::ingredients::meat