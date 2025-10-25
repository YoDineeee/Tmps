#include "Recipe.h"

namespace food::recipes {

Recipe::Recipe(std::string name) : name_(std::move(name)) {}

void Recipe::addIngredient(std::shared_ptr<food::ingredients::Ingredient> ingredient) {
    ingredients_.push_back(std::move(ingredient));
}

const std::string& Recipe::getName() const { return name_; }

const std::vector<std::shared_ptr<food::ingredients::Ingredient>>&
Recipe::getIngredients() const {
    return ingredients_;
}

} // namespace food::recipes
