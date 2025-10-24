#pragma once

#include "AbstractProducingEmployee.h"
#include <memory>

// Forward declarations
namespace food::items {
    class MenuItem;
    namespace drinks {
        class DrinkMenuItem;
    }
}

namespace employees::producers {

class Barman : public AbstractProducingEmployee {
public:
    Barman(std::string name, double salary);

    void giveRequest(const std::shared_ptr<food::items::MenuItem>& menuItem) override;
    void work() override;
};

} // namespace employees::producers