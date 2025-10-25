#include "Barman.h"
#include "drinkmenu.h"
#include <iostream>

namespace employees::producers {

Barman::Barman(std::string n,double s)
    : AbstractProducingEmployee(std::move(n),s) {}

void Barman::giveRequest(const std::shared_ptr<food::items::MenuItem>& menuItem) {
    auto drink = std::dynamic_pointer_cast<food::items::drinks::DrinkMenuItem>(menuItem);
    if(!drink){
        std::cout<<getName()<<": cannot prepare non-drink item '"<<menuItem->getName()<<"'.\n";
        return;
    }
    std::cout<<getName()<<": mixing "<<drink->getName()<<" ("<<drink->getVolume()<<" L)\n";
}

void Barman::work() {
    std::cout<<getName()<<" is serving customers.\n";
}

} // namespace employees::producers
