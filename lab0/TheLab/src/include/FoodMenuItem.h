#pragma once

#include "MenuItem.h"
#include <memory>

// Forward declaration
namespace food::recipes {
    class Recipe;
}

namespace food::items::food {

class FoodMenuItem : public food::items::MenuItem {
public:
    FoodMenuItem(
        std::string name,
        std::string description,
        double price,
        std::shared_ptr<food::recipes::Recipe> recipe,
        double weight
    );

    const std::shared_ptr<food::recipes::Recipe>& getRecipe() const;
    double getWeight() const;

private:
    std::shared_ptr<food::recipes::Recipe> recipe_;
    double weight_;
};

} // namespace food::items::food