#include "DrinkMenuItem.h"

namespace food::items::drinks {

DrinkMenuItem::DrinkMenuItem(
    std::string name,
    std::string description,
    double price,
    double volume)
    : MenuItem(std::move(name), std::move(description), price)
    , volume_(volume) {}

double DrinkMenuItem::getVolume() const {
    return volume_;
}

} // namespace food::items::drinks

