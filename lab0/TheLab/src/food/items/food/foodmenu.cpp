#include "FoodMenuItem.h"
#include "Recipe.h" // Required for completeness (though not used in method bodies)

namespace food::items::food {

FoodMenuItem::FoodMenuItem(
    std::string name,
    std::string description,
    double price,
    std::shared_ptr<food::recipes::Recipe> recipe,
    double weight)
    : MenuItem(std::move(name), std::move(description), price)
    , recipe_(std::move(recipe))
    , weight_(weight) {}

const std::shared_ptr<food::recipes::Recipe>& FoodMenuItem::getRecipe() const {
    return recipe_;
}

double FoodMenuItem::getWeight() const {
    return weight_;
}

} // namespace food::items::food