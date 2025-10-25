#pragma once
#include "RecipeStep.h"
#include <memory>

namespace food::recipes::steps {

class OneTimeRecipeStep : public RecipeStep {
public:
    OneTimeRecipeStep(std::shared_ptr<food::ingredients::AbstractIngredient> ingredient,
                      std::string description,
                      enums::RecipeAction action);

    enums::RecipeAction getAction() const override;
    std::string getDescription() const override;
    std::shared_ptr<food::ingredients::AbstractIngredient> getIngredient() const override;

private:
    std::shared_ptr<food::ingredients::AbstractIngredient> ingredient_;
    std::string description_;
    enums::RecipeAction action_;
};

} // namespace food::recipes::steps
