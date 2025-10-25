#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>
#include <chrono>

// Employees
#include "include/Accountant.h"
#include "include/Manager.h"
#include "include/Cook.h"
#include "include/Barman.h"

// Ingredients
#include "include/Meat.h"
#include "include/Vegetable.h"
#include "include/Lavash.h"

// Menu Items
#include "include/FoodMenuItem.h"
#include "include/DrinkMenuItem.h"

// Recipes
#include "include/Recipe.h"
#include "include/OneTimeRecipeStep.h"
#include "include/TimedRecipeStep.h"

// Enums
#include "include/MeatType.h"
#include "include/RecipeAction.h"

using namespace std::chrono_literals;

using food::ingredients::meat::Meat;
using food::ingredients::enums::MeatType;   // ✅ unified enums namespace
using food::ingredients::Vegetable;
using food::ingredients::Lavash;
using food::items::food::FoodMenuItem;
using food::items::drinks::DrinkMenuItem;
using food::recipes::Recipe;
using food::recipes::steps::OneTimeRecipeStep;
using food::recipes::steps::TimedRecipeStep;
using food::recipes::steps::enums::RecipeAction;

std::shared_ptr<Recipe> getKebabRecipe() {
    auto chicken     = std::make_shared<Meat>("Chicken Thighs", MeatType::CHICKEN);
    auto tomatoes    = std::make_shared<Vegetable>("Tomato", "Fresh Tomatoes", true);
    auto onions      = std::make_shared<Vegetable>("Onion", "Fresh Onions", true);
    auto bellPepper  = std::make_shared<Vegetable>("Bell Pepper", "Fresh Bell Pepper", true);
    auto lavash      = std::make_shared<Lavash>("Lavash", "Arabic lavash", false);

    auto grillChicken    = std::make_shared<TimedRecipeStep>(chicken, "Grill the chicken", RecipeAction::GRILL, 60s); // ✅ seconds
    auto cutTomatoes     = std::make_shared<OneTimeRecipeStep>(tomatoes, "Cut the tomatoes", RecipeAction::CUT);
    auto cutOnions       = std::make_shared<OneTimeRecipeStep>(onions,   "Cut the onions",   RecipeAction::CUT);
    auto unfoldLavash    = std::make_shared<OneTimeRecipeStep>(lavash,   "Unfold the lavash", RecipeAction::UNFOLD);
    auto mixIngredients  = std::make_shared<OneTimeRecipeStep>(lavash,   "Mix the ingredients", RecipeAction::MIX);
    auto wrapIngredients = std::make_shared<OneTimeRecipeStep>(lavash,   "Wrap the ingredients", RecipeAction::FOLD);

    std::vector<std::shared_ptr<food::ingredients::AbstractIngredient>> ingredients = {
        chicken, tomatoes, onions, bellPepper, lavash
    };
    std::vector<std::shared_ptr<food::recipes::steps::RecipeStep>> steps = {
        grillChicken, cutTomatoes, cutOnions, unfoldLavash, mixIngredients, wrapIngredients
    };

    return std::make_shared<Recipe>("Kebab Recipe", std::move(ingredients), std::move(steps));
}

std::shared_ptr<DrinkMenuItem> getJager() {
    return std::make_shared<DrinkMenuItem>("Jagermeister", "German herbal liqueur", 25.0, 0.7);
}

void simulateRestaurant() {
    auto kebabRecipe = getKebabRecipe();
    auto kebab = std::make_shared<FoodMenuItem>("Kebab", "Tender chicken kebab", 50.0, kebabRecipe, 0.420);

    // Cook’s cookable items type in your headers is set<FoodMenuItem>, keep it that way:
    std::unordered_set<std::shared_ptr<FoodMenuItem>> cookable = { kebab };

    auto cook = std::make_shared<employees::producers::Cook>("John", 1000.0, cookable);
    cook->giveRequest(kebab); // upcasts to MenuItem inside method body
    cook->giveRequest(kebab);

    auto barman = std::make_shared<employees::producers::Barman>("Nick", 1000.0);
    barman->giveRequest(kebab);          // expected to reject (not a drink)
    barman->giveRequest(getJager());     // OK

    std::unordered_set<std::shared_ptr<employees::Employee>> none;
    auto accountant = std::make_shared<employees::accountant::Accountant>("Jane", 2000.0, none);

    auto kitchenManager = std::make_shared<employees::director::Manager>("Jake", 1500.0, none);
    auto hrManager      = std::make_shared<employees::director::Manager>("Alice", 1500.0, none);

    kitchenManager->addSubordinate(cook);
    kitchenManager->addSubordinate(barman);
    hrManager->addSubordinate(accountant);

    kitchenManager->work();
    hrManager->work();
}

int main() {
    std::cout << "Hello World!\n";
    simulateRestaurant();
    return 0;
}
