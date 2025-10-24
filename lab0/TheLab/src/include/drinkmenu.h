#pragma once

#include "MenuItem.h"

namespace food::items::drinks {

class DrinkMenuItem : public food::items::MenuItem {
public:
    DrinkMenuItem(
        std::string name,
        std::string description,
        double price,
        double volume
    );

    double getVolume() const;

private:
    double volume_;
};

} // namespace food::items::drinks