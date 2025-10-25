#pragma once
#include <string>

namespace food::items {

class MenuItem {
public:
    MenuItem(std::string name, std::string description, double price);
    virtual ~MenuItem() = default;

    const std::string& getName() const;
    const std::string& getDescription() const;
    double getPrice() const;

protected:
    std::string name_;
    std::string description_;
    double price_;
};

} // namespace food::items

