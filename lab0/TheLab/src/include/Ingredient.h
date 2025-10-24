#pragma once

#include <string>

namespace food::ingredients {

class Ingredient {
public:
    virtual ~Ingredient() = default;

    virtual std::string getName() const = 0;
    virtual std::string getDescription() const = 0;
};

} // namespace food::ingredients