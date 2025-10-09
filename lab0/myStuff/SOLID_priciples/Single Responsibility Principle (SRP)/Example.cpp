#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Violating SRP would mean having one class handle both
// employee data AND saving to a file. Instead, we separate them.

// 1. Class responsible ONLY for representing employee data
class Employee {
private:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}

    string getName() const { return name; }
    int getId() const { return id; }

    string toString() const {
        return "Employee: " + name + " (ID: " + to_string(id) + ")";
    }
};

// 2. Class responsible ONLY for saving employee data (separate responsibility)
class EmployeeFileManager {
public:
    static void saveToFile(const Employee& emp, const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << emp.toString() << endl;
            file.close();
            cout << "Saved successfully!" << endl;
        } else {
            cerr << "Error opening file!" << endl;
        }
    }
};

// Main program demonstrating SRP
int main() {
    Employee e("John Doe", 101);
    cout << e.toString() << endl;

    EmployeeFileManager::saveToFile(e, "employee.txt");
    return 0;
}
