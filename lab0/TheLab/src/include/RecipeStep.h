#pragma once
#include <memory>
#include <string>
#include "AbstractIngredient.h"
#include "RecipeAction.h"

namespace food::recipes::steps {

class RecipeStep {
public:
    virtual ~RecipeStep() = default;

    virtual std::shared_ptr<food::ingredients::AbstractIngredient> getIngredient() const = 0;
    virtual std::string getDescription() const = 0;
    virtual enums::RecipeAction getAction() const = 0;
};

} // namespace food::recipes::steps
