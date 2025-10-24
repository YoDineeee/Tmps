#include "TimedRecipeStep.h"

namespace food::recipes::steps {

TimedRecipeStep::TimedRecipeStep(
    std::shared_ptr<food::ingredients::AbstractIngredient> ingredient,
    std::string description,
    enums::RecipeAction action,
    std::chrono::seconds duration)
    : OneTimeRecipeStep(std::move(ingredient), std::move(description), action)
    , duration_(duration) {}

std::chrono::seconds TimedRecipeStep::getDuration() const {
    return duration_;
}

} // namespace food::recipes::steps