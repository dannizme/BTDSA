#include <iostream>
#include <string>

struct Employee
{
    std::string id;
    std::string firstName;
    std::string lastName;
    int gender; // 1 for men and 0 for women
    int seniority;
};

struct Department
{
    Employee employee[100];
    int quantity;
};

void inputEmployeeInfo(Employee &employee)
{
    std::cout << "Enter ID: ";
    std::cin >> employee.id;
    std::cout << "Enter First Name: ";
    std::cin >> employee.firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> employee.lastName;
    std::cout << "Enter gender: ";
    std::cin >> employee.gender;
    std::cout << "Enter seniority: ";
    std::cin >> employee.seniority;
}

void inputDepartment(Department &department)
{
    std::cout << "Enter the number of employees: ";
    std::cin >> department.quantity;
    for (int i = 0; i < department.quantity; i++)
    {
        std::cout << "Enter employee " << i + 1 << "\n";
        inputEmployeeInfo(department.employee[i]);
    }
}

void countGender(Department &department, int &quantityMen, int &quantityWomen)
{
    quantityMen = 0;
    quantityWomen = 0;
    for (int i = 0; i < department.quantity; i++)
    {
        if (department.employee[i].gender == 1)
        {
            quantityMen++;
        }
        else
        {
            quantityWomen++;
        }
    }
}

void sortBySeniority(Department &department)
{
    for (int i = 0; i < department.quantity - 1; i++)
    {
        for (int j = i + 1; j < department.quantity; j++)
        {
            if (department.employee[i].seniority > department.employee[j].seniority)
            {
                Employee temp = department.employee[i];
                department.employee[i] = department.employee[j];
                department.employee[j] = temp;
            }
        }
    }
}

int main()
{
    Department department;
    inputDepartment(department);

    // Count gender
    int quantityMen, quantityWomen;
    countGender(department, quantityMen, quantityWomen);
    std::cout << "Number of Men: " << quantityMen << "\n";
    std::cout << "Number of Women: " << quantityWomen << "\n";

    // Sort by seniority
    sortBySeniority(department);
    std::cout << "Employees sorted by seniority:\n";
    for (int i = 0; i < department.quantity; i++)
    {
        std::cout << "ID: " << department.employee[i].id
                  << ", Name: " << department.employee[i].firstName << " " << department.employee[i].lastName
                  << ", Gender: " << (department.employee[i].gender == 1 ? "Man" : "Woman")
                  << ", Seniority: " << department.employee[i].seniority << "\n";
    }

    return 0;
}
