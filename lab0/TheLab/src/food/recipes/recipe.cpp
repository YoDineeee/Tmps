#include "Recipe.h"

namespace food::recipes {

Recipe::Recipe(
    std::string name,
    std::vector<std::shared_ptr<food::ingredients::AbstractIngredient>> ingredients,
    std::vector<std::shared_ptr<food::recipes::steps::RecipeStep>> steps)
    : name_(std::move(name))
    , ingredients_(std::move(ingredients))
    , steps_(std::move(steps)) {}

const std::string& Recipe::getName() const {
    return name_;
}

const std::vector<std::shared_ptr<food::ingredients::AbstractIngredient>>&
Recipe::getIngredients() const {
    return ingredients_;
}

const std::vector<std::shared_ptr<food::recipes::steps::RecipeStep>>&
Recipe::getSteps() const {
    return steps_;
}

} // namespace food::recipes