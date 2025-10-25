#pragma once
#include "ProducingEmployee.h"
#include <string>

namespace employees::producers {
class AbstractProducingEmployee : public virtual employees::ProducingEmployee {
public:
    AbstractProducingEmployee(std::string name, double salary);
    std::string getName() const override;
    double getSalary() const override;
protected:
    std::string name;
    double salary;
};
} // namespace employees::producers
