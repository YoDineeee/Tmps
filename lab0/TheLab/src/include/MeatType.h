#pragma once

#include <string>
#include <string_view>

namespace food::ingredients::meat::enums {

enum class MeatType {
    BEEF,
    CHICKEN,
    LAMB
};

// Helper function: equivalent to Java's toString()
constexpr std::string_view toString(MeatType type) noexcept {
    switch (type) {
        case MeatType::BEEF:    return "Beef";
        case MeatType::CHICKEN: return "Chicken";
        case MeatType::LAMB:    return "Lamb";
        default:                return "Unknown";
    }
}

} // namespace food::ingredients::meat::enums