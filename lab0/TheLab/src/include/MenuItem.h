// src/include/MenuItem.h
#pragma once
#include <string>

namespace food::items {
class MenuItem {
public:
    virtual ~MenuItem() = default;
    virtual std::string getName() const = 0;
};
} // namespace food::items