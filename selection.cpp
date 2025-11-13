
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
    Student s[100], temp;
    int n, i, j, minIndex, choice;

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

    cout << "\nSort students based on:\n";
    cout << "1. Roll Number\n2. Name\n3. Marks\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            bool swapNeeded = false;

            if (choice == 1 && s[j].roll < s[minIndex].roll)
                swapNeeded = true;
            else if (choice == 2 && s[j].name < s[minIndex].name)
                swapNeeded = true;
            else if (choice == 3 && s[j].marks < s[minIndex].marks)
                swapNeeded = true;

            if (swapNeeded)
                minIndex = j;
        }

        if (minIndex != i)
        {
            temp = s[i];
            s[i] = s[minIndex];
            s[minIndex] = temp;
        }
    }

    cout << "\nStudents sorted successfully!\n";
    cout << "\nRoll No.\tName\tMarks\n";
    cout << "-----------------------------------\n";
    for (i = 0; i < n; i++)
    {
        cout << s[i].roll << "\t\t" << s[i].name << "\t" << s[i].marks << endl;
    }

    return 0;
}
