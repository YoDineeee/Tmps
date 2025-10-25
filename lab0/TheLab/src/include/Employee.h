#pragma once
#include <string>

namespace employees {
class Employee {
public:
    virtual ~Employee() = default;
    virtual std::string getName() const = 0;
    virtual double getSalary() const = 0;
    virtual void work() = 0;
};
} // namespace employees
