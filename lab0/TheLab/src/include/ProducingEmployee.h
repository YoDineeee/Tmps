#pragma once
#include "Employee.h"
#include <memory>

namespace food::items { class MenuItem; }

namespace employees {
class ProducingEmployee : virtual public Employee {
public:
    virtual ~ProducingEmployee() = default;
    virtual void giveRequest(const std::shared_ptr<food::items::MenuItem>& menuItem) = 0;
};
} // namespace employees
