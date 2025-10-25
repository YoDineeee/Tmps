#pragma once
#include "AbstractIngredient.h"
namespace food::ingredients {
class Sauce : public AbstractIngredient {
public:
    Sauce(std::string name,std::string desc,bool spicy);
    bool isSpicy() const;
private:
    bool spicy_;
};
}
