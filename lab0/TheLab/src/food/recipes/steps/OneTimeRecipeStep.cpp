#include "OneTimeRecipeStep.h"

namespace food::recipes::steps {

OneTimeRecipeStep::OneTimeRecipeStep(
    std::shared_ptr<food::ingredients::AbstractIngredient> ingredient,
    std::string description,
    enums::RecipeAction action)
    : ingredient_(std::move(ingredient)),
      description_(std::move(description)),
      action_(action) {}

enums::RecipeAction OneTimeRecipeStep::getAction() const { return action_; }
std::string OneTimeRecipeStep::getDescription() const { return description_; }
std::shared_ptr<food::ingredients::AbstractIngredient> OneTimeRecipeStep::getIngredient() const {
    return ingredient_;
}

} // namespace food::recipes::steps
