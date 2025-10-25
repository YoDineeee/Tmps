#pragma once
#include <string_view>
namespace food::recipes::steps::enums {
enum class RecipeAction { CHOP,MIX,BOIL,FRY,BAKE,GRILL,CUT,FOLD,UNFOLD,MIX2 };
constexpr std::string_view toString(RecipeAction a) noexcept {
    switch(a){case RecipeAction::CHOP:return"Chop";case RecipeAction::MIX:return"Mix";
        case RecipeAction::GRILL:return"Grill";default:return"Act";}
}
}
