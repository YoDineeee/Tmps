#pragma once

#include <unordered_set>
#include <memory>
#include <vector>

// Forward declaration
namespace employees {
    class Employee;
}

namespace employees::common {

class SubordinatesManager {
public:
    // Constructor: accepts a set of shared_ptr<Employee>
    explicit SubordinatesManager(
        std::unordered_set<std::shared_ptr<employees::Employee>> subordinates = {}
    );

    // Get a const reference to subordinates (avoid unnecessary copy)
    const std::unordered_set<std::shared_ptr<employees::Employee>>& getSubordinates() const;

    // Set new subordinates
    void setSubordinates(std::unordered_set<std::shared_ptr<employees::Employee>> subordinates);

    // Add/remove
    void addSubordinate(const std::shared_ptr<employees::Employee>& employee);
    void removeSubordinate(const std::shared_ptr<employees::Employee>& employee);

private:
    std::unordered_set<std::shared_ptr<employees::Employee>> subordinates;
};

} 