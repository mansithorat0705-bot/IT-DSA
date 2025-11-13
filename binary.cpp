#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct Student
{
    int roll;
    string name;
    float marks;
};

int main()
{
    Student s[100];   // ✅ Increased size to 100
    int n, i, lower = 0, higher, middle, searchRoll;
    bool found = false;

    cout << "Enter total number of students (max 100): ";
    cin >> n;

    cout << "\nEnter student details in ascending order of roll number:\n";
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

    higher = n - 1;

    // Binary Search logic
    while (lower <= higher)
    {
        middle = (lower + higher) / 2;

        if (s[middle].roll == searchRoll)
        {
            found = true;
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << s[middle].roll << endl;
            cout << "Name: " << s[middle].name << endl;
            cout << "Marks: " << s[middle].marks << endl;
            break;
        }
        else if (searchRoll < s[middle].roll)
        {
            higher = middle - 1;
        }
        else
        {
            lower = middle + 1;
        }
    }

    if (!found)
        cout << "\nStudent with Roll Number " << searchRoll << " not found.\n";

    return 0;
}
