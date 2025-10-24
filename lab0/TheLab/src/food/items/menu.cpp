#include "MenuItem.h"

namespace food::items {

MenuItem::MenuItem(
    std::string name,
    std::string description,
    double price)
    : name_(std::move(name))
    , description_(std::move(description))
    , price_(price) {}

const std::string& MenuItem::getName() const {
    return name_;
}

const std::string& MenuItem::getDescription() const {
    return description_;
}

double MenuItem::getPrice() const {
    return price_;
}

} // namespace food::items