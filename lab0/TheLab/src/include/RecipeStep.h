#pragma once

#include "AbstractIngredient.h"
#include "RecipeAction.h"
#include <memory>
#include <string>

namespace food::recipes::steps {

// Bring enum into scope for convenience
using enums::RecipeAction;

class RecipeStep {
public:
    virtual ~RecipeStep() = default;

    virtual std::shared_ptr<food::ingredients::AbstractIngredient> getIngredient() const = 0;
    virtual std::string getDescription() const = 0;  // Can be empty if "null"
    virtual RecipeAction getAction() const = 0;
};

} // namespace food::recipes::steps