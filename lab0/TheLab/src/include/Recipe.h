#pragma once

#include "AbstractIngredient.h"
#include "RecipeStep.h"
#include <string>
#include <vector>
#include <memory>

namespace food::recipes {

class Recipe {
public:
    Recipe(
        std::string name,
        std::vector<std::shared_ptr<food::ingredients::AbstractIngredient>> ingredients,
        std::vector<std::shared_ptr<food::recipes::steps::RecipeStep>> steps
    );

    const std::string& getName() const;
    const std::vector<std::shared_ptr<food::ingredients::AbstractIngredient>>& getIngredients() const;
    const std::vector<std::shared_ptr<food::recipes::steps::RecipeStep>>& getSteps() const;

private:
    std::string name_;
    std::vector<std::shared_ptr<food::ingredients::AbstractIngredient>> ingredients_;
    std::vector<std::shared_ptr<food::recipes::steps::RecipeStep>> steps_;
};

} // namespace food::recipes