#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Employee {
    int id;
    string name;
    string department;
    double salary;
};
vector<Employee> employees;
bool isDuplicateID(int id) {
    for (const auto& emp : employees) {
        if (emp.id == id)
            return true;
    }
    return false;
}
void addEmployee() {
    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    if (isDuplicateID(emp.id)) {
        cout << "Error: Employee ID already exists!\n";
        return;
    }
    cin.ignore(); // clear newline
    cout << "Enter Employee Name: ";
    getline(cin, emp.name);
    cout << "Enter Department: ";
    getline(cin, emp.department);
    cout << "Enter Salary: ";
    cin >> emp.salary;
    employees.push_back(emp);
    cout << "Employee added successfully!\n";
}
void displayEmployees() {
    if (employees.empty()) {
        cout << "No employees to display.\n";
        return;
    }
    cout << "\nEmployee List:\n";
    for (const auto& emp : employees) {
        cout << "ID: " << emp.id << ", Name: " << emp.name
             << ", Department: " << emp.department
             << ", Salary: $" << emp.salary << endl;
    }
}
void searchEmployee() {
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;
    for (const auto& emp : employees) {
        if (emp.id == id) {
            cout << "Employee Found:\n";
            cout << "ID: " << emp.id << ", Name: " << emp.name
                 << ", Department: " << emp.department
                 << ", Salary: ₨" << emp.salary << endl;
            return;
        }
    }
    cout << "Employee not found.\n";
}
void updateEmployee() {
    int id;
    cout << "Enter Employee ID to update: ";
    cin >> id;
    for (auto& emp : employees) {
        if (emp.id == id) {
            cin.ignore();
            cout << "Enter new name (current: " << emp.name << "): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) emp.name = newName;
            cout << "Enter new department (current: " << emp.department << "): ";
            string newDept;
            getline(cin, newDept);
            if (!newDept.empty()) emp.department = newDept;
            cout << "Enter new salary (current: ₨'" << emp.salary << "): ";
            string newSalaryStr;
            getline(cin, newSalaryStr);
            if (!newSalaryStr.empty()) emp.salary = stod(newSalaryStr);
            cout << "Employee updated successfully.\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}
void deleteEmployee() {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->id == id) {
            employees.erase(it);
            cout << "Employee deleted successfully.\n";
            return;
        }
    }
    cout << "Employee not found.\n";
}
int main() {
    int choice;
    do {
        cout << "\n--- Employee Management System ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Display Employees\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";  // New Option
        cout << "5. Delete Employee\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break; // New Case
            case 5: deleteEmployee(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
