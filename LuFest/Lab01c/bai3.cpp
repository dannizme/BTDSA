#include <iostream>
#include <string>

struct Student
{
    std::string id;
    std::string firstName;
    std::string lastName;
    int sex; // Man = 1 and Woman = 0
    int yoB; // Year of Birth
};

struct Class
{
    Student student[50];
    int quantity;
};

void inputStudentInfo(Student &student)
{
    std::cout << "Enter ID: ";
    std::cin >> student.id;
    std::cout << "Enter First Name: ";
    std::cin >> student.firstName;
    std::cout << "Enter Last Name: ";
    std::cin >> student.lastName;
    std::cout << "Enter Sex: ";
    std::cin >> student.sex;
    std::cout << "Enter Year of Birth: ";
    std::cin >> student.yoB;
}

void inputClassStudent(Class &classStudent, int n)
{
    classStudent.quantity = n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter student " << i + 1 << "\n";
        inputStudentInfo(classStudent.student[i]);
    }
}

void countStudentBySex(Class &classStudent, int &quantityMan, int &quantityWoman)
{
    quantityMan = 0;
    quantityWoman = 0;
    for (int i = 0; i < classStudent.quantity; i++)
    {
        if (classStudent.student[i].sex == 1)
        {
            quantityMan++;
        }
        else
        {
            quantityWoman++;
        }
    }
}

void sortByYoB(Class &classStudent)
{
    for (int i = 0; i < classStudent.quantity - 1; i++)
    {
        for (int j = i + 1; j < classStudent.quantity; j++)
        {
            if (classStudent.student[i].yoB > classStudent.student[j].yoB)
            {
                Student temp = classStudent.student[i];
                classStudent.student[i] = classStudent.student[j];
                classStudent.student[j] = temp;
            }
        }
    }
}

int main()
{
    Class classStudent;
    int n;
    std::cout << "Enter the number of students: ";
    std::cin >> n;

    inputClassStudent(classStudent, n);

    // Count students by sex
    int quantityMan, quantityWoman;
    countStudentBySex(classStudent, quantityMan, quantityWoman);
    std::cout << "Number of Men: " << quantityMan << "\n";
    std::cout << "Number of Women: " << quantityWoman << "\n";

    // Sort by Year of Birth
    sortByYoB(classStudent);
    std::cout << "Sorted by Year of Birth: \n";
    for (int i = 0; i < classStudent.quantity; i++)
    {
        std::cout << "ID: " << classStudent.student[i].id << ", Name: "
                  << classStudent.student[i].firstName << " " << classStudent.student[i].lastName
                  << ", Year of Birth: " << classStudent.student[i].yoB << "\n";
    }

    return 0;
}