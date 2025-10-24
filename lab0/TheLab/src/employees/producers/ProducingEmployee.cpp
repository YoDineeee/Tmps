#include "ProducingEmployee.h"

// Explicitly define virtual destructor
employees::ProducingEmployee::~ProducingEmployee() = default;


// Employee (base)
class Employee { virtual ~Employee() = default; /* getName, getSalary, work */ };

// ProducingEmployee (adds giveRequest)
class ProducingEmployee : virtual public Employee {
    virtual void giveRequest(...) = 0;
};

// AbstractProducingEmployee (implements getName/getSalary)
class AbstractProducingEmployee : public virtual ProducingEmployee {
    // concrete getName/getSalary, pure giveRequest
};

// Cook, Barman, etc. (fully concrete)
class Cook : public AbstractProducingEmployee { ... };

