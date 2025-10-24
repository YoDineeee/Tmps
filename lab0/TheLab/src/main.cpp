#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>
#include <chrono>

// Employees
#include "Accountant.h"
#include "Manager.h"
#include "Cook.h"
#include "Barman.h"

// Ingredients
#include "Meat.h"
#include "Vegetable.h"
#include "Lavash.h"

// Menu Items
#include "FoodMenuItem.h"
#include "DrinkMenuItem.h"

// Recipes
#include "Recipe.h"
#include "OneTimeRecipeStep.h"
#include "TimedRecipeStep.h"

// Enums
#include "MeatType.h"
#include "RecipeAction.h"

// Using declarations for cleaner code
using namespace std::chrono_literals;
using food::ingredients::meat::Meat;
using food::ingredients::meat::enums::MeatType;
using food::ingredients::Vegetable;
using food::ingredients::Lavash;
using food::items::food::FoodMenuItem;
using food::items::drinks::DrinkMenuItem;
using food::recipes::Recipe;
using food::recipes::steps::OneTimeRecipeStep;
using food::recipes::steps::TimedRecipeStep;
using food::recipes::steps::enums::RecipeAction;

// Forward declare if needed
namespace employees::accountant { class Accountant; }
namespace employees::director { class Manager; }
namespace employees::producers { class Cook; class Barman; }

// Helper: create kebab recipe
std::shared_ptr<Recipe> getKebabRecipe() {
    auto chicken = std::make_shared<Meat>("Chicken Thighs", "Tender chicken thighs", MeatType::CHICKEN);
    auto tomatoes = std::make_shared<Vegetable>("Tomato", "Fresh Tomatoes", true);
    auto onions = std::make_shared<Vegetable>("Onion", "Fresh Onions", true);
    auto bellPepper = std::make_shared<Vegetable>("Bell Pepper", "Fresh Bell Pepper", true);
    auto lavash = std::make_shared<Lavash>("Lavash", "Arabic lavash", false);

    auto grillChicken = std::make_shared<TimedRecipeStep>(
        chicken, "Grill the chicken", RecipeAction::GRILL, 1min
    );
    auto cutTomatoes = std::make_shared<OneTimeRecipeStep>(
        tomatoes, "Cut the tomatoes", RecipeAction::CUT  // 🔸 Fixed: was lavash!
    );
    auto cutOnions = std::make_shared<OneTimeRecipeStep>(
        onions, "Cut the onions", RecipeAction::CUT
    );
    auto unfoldLavash = std::make_shared<OneTimeRecipeStep>(
        lavash, "Unfold the lavash", RecipeAction::UNFOLD
    );
    auto mixIngredients = std::make_shared<OneTimeRecipeStep>(
        lavash, "Mix the ingredients", RecipeAction::MIX
    );
    auto wrapIngredients = std::make_shared<OneTimeRecipeStep>(
        lavash, "Wrap the ingredients", RecipeAction::FOLD
    );

    std::vector<std::shared_ptr<food::ingredients::AbstractIngredient>> ingredients = {
        chicken, tomatoes, onions, bellPepper, lavash
    };
    std::vector<std::shared_ptr<food::recipes::steps::RecipeStep>> steps = {
        grillChicken, cutTomatoes, cutOnions, unfoldLavash, mixIngredients, wrapIngredients
    };

    return std::make_shared<Recipe>("Kebab Recipe", std::move(ingredients), std::move(steps));
}

// Helper: create Jagermeister drink
std::shared_ptr<DrinkMenuItem> getJager() {
    // Since AlcoholicDrinkMenuItem isn't defined, use DrinkMenuItem
    return std::make_shared<DrinkMenuItem>("Jagermeister", "German herbal liqueur", 25.0, 0.7);
}

// Main simulation
void simulateRestaurant() {
    auto kebabRecipe = getKebabRecipe();
    auto kebab = std::make_shared<FoodMenuItem>("Kebab", "Tender chicken kebab", 50.0, kebabRecipe, 0.420);

    // Cookable items as unordered_set
    std::unordered_set<std::shared_ptr<FoodMenuItem>> cookableItems = {kebab};

    auto cook = std::make_shared<employees::producers::Cook>("John", 1000.0, cookableItems);
    cook->giveRequest(kebab);
    cook->giveRequest(kebab);

    auto barman = std::make_shared<employees::producers::Barman>("Nick", 1000.0);
    barman->giveRequest(kebab);  // Will fail (non-drink)
    barman->giveRequest(getJager());

    // Accountant with empty subordinates (null → empty set)
    std::unordered_set<std::shared_ptr<employees::Employee>> emptySet;
    auto accountant = std::make_shared<employees::accountant::Accountant>("Jane", 2000.0, emptySet);

    // Managers
    auto kitchenManager = std::make_shared<employees::director::Manager>("Jake", 1500.0, emptySet);
    auto hrManager = std::make_shared<employees::director::Manager>("Alice", 1500.0, emptySet);

    // Add subordinates
    kitchenManager->subordinatesManager->addSubordinate(cook);
    kitchenManager->subordinatesManager->addSubordinate(barman);
    hrManager->subordinatesManager->addSubordinate(accountant);

    kitchenManager->work();
    hrManager->work();
}

// Main function
int main() {
    std::cout << "Hello World!\n";
    getKebabRecipe(); // (unused, but called like Java)
    simulateRestaurant();
    return 0;
}