#pragma once

#include <string_view>

namespace food::recipes::steps::enums {

enum class RecipeAction {
    CHOP,
    MIX,
    BOIL,
    FRY,
    BAKE,
    GRILL,
    ADD,
    REMOVE,
    CUT,
    FOLD,
    UNFOLD,
    POUR,
    STIR,
    SHAKE,
    BLEND,
    WAIT
};

constexpr std::string_view toString(RecipeAction action) noexcept {
    switch (action) {
        case RecipeAction::CHOP:    return "Chop";
        case RecipeAction::MIX:     return "Mix";
        case RecipeAction::BOIL:    return "Boil";
        case RecipeAction::FRY:     return "Fry";
        case RecipeAction::BAKE:    return "Bake";
        case RecipeAction::GRILL:   return "Grill";
        case RecipeAction::ADD:     return "Add";
        case RecipeAction::REMOVE:  return "Remove";
        case RecipeAction::CUT:     return "Cut";
        case RecipeAction::FOLD:    return "Fold";
        case RecipeAction::UNFOLD:  return "Unfold";
        case RecipeAction::POUR:    return "Pour";
        case RecipeAction::STIR:    return "Stir";
        case RecipeAction::SHAKE:   return "Shake";
        case RecipeAction::BLEND:   return "Blend";
        case RecipeAction::WAIT:    return "Wait";
        default:                    return "Unknown";
    }
}

} // namespace food::recipes::steps::enums