#pragma once
#include <string>
#include <vector>
#include <memory>
#include "Ingredient.h"

namespace food::recipes {

class Recipe {
public:
    Recipe(std::string name);
    void addIngredient(std::shared_ptr<food::ingredients::Ingredient> ingredient);
    const std::string& getName() const;
    const std::vector<std::shared_ptr<food::ingredients::Ingredient>>& getIngredients() const;

private:
    std::string name_;
    std::vector<std::shared_ptr<food::ingredients::Ingredient>> ingredients_;
};

} // namespace food::recipes
