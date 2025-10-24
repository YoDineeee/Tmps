#pragma once

#include "OneTimeRecipeStep.h"
#include <chrono>

namespace food::recipes::steps {

class TimedRecipeStep : public OneTimeRecipeStep {
public:
    TimedRecipeStep(
        std::shared_ptr<food::ingredients::AbstractIngredient> ingredient,
        std::string description,
        enums::RecipeAction action,
        std::chrono::seconds duration  // Java's Duration → std::chrono::seconds
    );

    std::chrono::seconds getDuration() const;

private:
    std::chrono::seconds duration_;
};

} // namespace food::recipes::steps