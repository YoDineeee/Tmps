// src/include/DrinkMenuItem.h
#pragma once
#include "MenuItem.h"
#include <string>

namespace food::items::drinks {
class DrinkMenuItem : public food::items::MenuItem {
public:
    explicit DrinkMenuItem(std::string name) : name_(std::move(name)) {}
    std::string getName() const override { return name_; }
private:
    std::string name_;
};
} // namespace food::items::drinks