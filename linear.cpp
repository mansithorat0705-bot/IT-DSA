#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int roll;
    string name;
    float marks;
};

int main()
{
    Student s[100];   // Array to store student records
    int n, i, searchRoll, flag = 0;

    cout << "Enter total number of students (at least 10): ";
    cin >> n;

    cout << "\nEnter details of " << n << " students:\n";
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter Roll Number: ";
        cin >> s[i].roll;
        cout << "Enter Name: ";
        cin >> s[i].name;
        cout << "Enter Marks: ";
        cin >> s[i].marks;
    }

    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    // Linear Search Logic
    for (i = 0; i < n; i++)
    {
        if (s[i].roll == searchRoll)
        {
            flag = 1;
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << s[i].roll << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "Marks: " << s[i].marks << endl;
            break;
        }
    }

    if (flag == 0)
        cout << "\nStudent with Roll Number " << searchRoll << " not found.\n";

    return 0;
}
