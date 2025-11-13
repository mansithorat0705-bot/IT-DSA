#include <iostream>   // ✅ added missing header
#include <stdlib.h>
#define max 5
using namespace std;

int main()
{
    int queue[max], front = 0, rear = -1;
    int ch = 0, data, temp, count = 0, count1, front1;

    do
    {
        cout << "\n1. Enqueue - Insert the element";
        cout << "\n2. Dequeue - Delete the element";
        cout << "\n3. Display the queue";
        cout << "\n4. Quit";
        cout << "\nEnter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1: // Enqueue
            if (count == max)
                cout << "Queue is full\n";
            else
            {
                cout << "Enter data: ";
                cin >> data;
                rear = (rear + 1) % max;
                queue[rear] = data;
                count++;
            }
            break;

        case 2: // Dequeue
            if (count == 0)
                cout << "Queue is empty\n";
            else
            {
                data = queue[front];
                cout << data << " is deleted\n";
                front = (front + 1) % max;
                count--;
            }
            break;

        case 3: // Display
            if (count == 0)
                cout << "Queue is empty\n";
            else
            {
                count1 = count;
                front1 = front;
                cout << "Queue elements are: ";
                while (count1 > 0)
                {
                    cout << queue[front1] << " ";
                    front1 = (front1 + 1) % max;
                    count1--;
                }
                cout << endl;
            }
            break;

        case 4:
            exit(0);

        default:
            cout << "Invalid choice!\n";
        }

        cout << "Continue [1/0]: ";
        cin >> ch;

    } while (ch == 1);

    return 0;
}
