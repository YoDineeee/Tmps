#pragma once
#include "AbstractIngredient.h"
namespace food::ingredients {
class Vegetable : public AbstractIngredient {
public:
    Vegetable(std::string name,std::string desc,bool organic);
    bool isOrganic() const;
private:
    bool organic_;
};
}
