#pragma once
#include "OneTimeRecipeStep.h"
#include <chrono>

namespace food::recipes::steps {

class TimedRecipeStep : public OneTimeRecipeStep {
public:
    TimedRecipeStep(std::shared_ptr<food::ingredients::AbstractIngredient> ingredient,
                    std::string description,
                    enums::RecipeAction action,
                    std::chrono::seconds duration)
        : OneTimeRecipeStep(std::move(ingredient), std::move(description), action),
          duration_(duration) {}

    std::chrono::seconds getDuration() const { return duration_; }

private:
    std::chrono::seconds duration_;
};

} // namespace food::recipes::steps
