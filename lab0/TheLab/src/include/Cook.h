#pragma once

#include "AbstractProducingEmployee.h"
#include <unordered_set>
#include <queue>
#include <memory>

// Forward declarations
namespace food::items {
    class MenuItem;
    namespace food {
        class FoodMenuItem;
    }
}

namespace employees::producers {

class Cook : public AbstractProducingEmployee {
public:
    Cook(
        std::string name,
        double salary,
        std::unordered_set<std::shared_ptr<food::items::food::FoodMenuItem>> cookableItems
    );

    void giveRequest(const std::shared_ptr<food::items::MenuItem>& item) override;
    void work() override;

private:
    void cookNextItem();

    std::unordered_set<std::shared_ptr<food::items::food::FoodMenuItem>> cookableItems;
    std::queue<std::shared_ptr<food::items::food::FoodMenuItem>> cookingQueue;
};

} // namespace employees::producers