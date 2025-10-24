#include <iostream>
#include <memory>
#include <chrono>
#include "Cook.h"
#include "FoodMenuItem.h"        // food::items::food::FoodMenuItem
#include "Recipe.h"              // food::recipes::Recipe
#include "RecipeStep.h"          // food::recipes::steps::RecipeStep
#include "TimedRecipeStep.h"     // food::recipes::steps::TimedRecipeStep

namespace employees::producers {

Cook::Cook(
    std::string name,
    double salary,
    std::unordered_set<std::shared_ptr<food::items::food::FoodMenuItem>> cookableItems)
    : AbstractProducingEmployee(std::move(name), salary)
    , cookableItems(std::move(cookableItems)) {}

void Cook::giveRequest(const std::shared_ptr<food::items::MenuItem>& item) {
    if (!item) {
        std::cout << "Cannot add null item to the queue.\n";
        return;
    }

    auto foodItem = std::dynamic_pointer_cast<food::items::food::FoodMenuItem>(item);
    if (!foodItem) {
        std::cout << "Cannot add non-food item to the queue.\n";
        return;
    }

    std::cout << item->getName() << " has been added to " << getName() << "'s cooking queue.\n";
    cookingQueue.push(foodItem);
}

void Cook::cookNextItem() {
    if (cookingQueue.empty()) {
        std::cout << getName() << " has no items to cook.\n";
        return;
    }

    auto itemToCook = cookingQueue.front();
    cookingQueue.pop();

    if (!itemToCook) return;

    // Check if cookable
    bool canCook = false;
    for (const auto& menuItem : cookableItems) {
        // Note: In Java, .equals() is used. In C++, we need to define equality.
        // For now, we compare by name (or you can implement operator==)
        if (menuItem && menuItem->getName() == itemToCook->getName()) {
            canCook = true;
            break;
        }
    }

    if (!canCook) {
        std::cout << getName() << " cannot cook " << itemToCook->getName() << ".\n";
        return;
    }

    std::cout << getName() << " is cooking " << itemToCook->getName() << ".\n";

    auto recipe = itemToCook->getRecipe();
    if (!recipe) {
        std::cout << "No recipe found for " << itemToCook->getName() << ".\n";
        return;
    }

    auto steps = recipe->getSteps();
    for (size_t i = 0; i < steps.size(); ++i) {
        const auto& step = steps[i];
        if (!step) continue;

        auto timedStep = std::dynamic_pointer_cast<const food::recipes::steps::TimedRecipeStep>(step);
        if (timedStep) {
            auto durationSecs = std::chrono::duration_cast<std::chrono::seconds>(
                timedStep->getDuration()
            ).count();
            std::cout << "Step " << (i + 1) << ": " << step->getDescription()
                      << " for " << durationSecs << " seconds.\n";
        } else {
            std::cout << "Step " << (i + 1) << ": " << step->getDescription() << '\n';
        }
    }
}

void Cook::work() {
    while (!cookingQueue.empty()) {
        cookNextItem();
    }
}

} // namespace employees::pro
