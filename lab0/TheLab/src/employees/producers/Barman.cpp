#include <iostream>
#include <memory>
#include "Barman.h"
#include "MenuItem.h"
#include "DrinkMenuItem.h" // Must define food::items::drinks::DrinkMenuItem

namespace employees::producers {

Barman::Barman(std::string name, double salary)
    : AbstractProducingEmployee(std::move(name), salary) {}

void Barman::giveRequest(const std::shared_ptr<food::items::MenuItem>& menuItem) {
    if (!menuItem) {
        std::cerr << "Menu item cannot be null\n";
        return;
    }

    // Equivalent of 'instanceof DrinkMenuItem'
    auto drinkItem = std::dynamic_pointer_cast<food::items::drinks::DrinkMenuItem>(menuItem);
    if (!drinkItem) {
        std::cerr << "Barman can only serve drinks\n";
        return;
    }

    std::cout << "I'm a barman, I'm giving you some " << menuItem->getName() << '\n';
}

void Barman::work() {
    std::cout << "I'm a barman, I'm working\n";
}

} // namespace employees::producers