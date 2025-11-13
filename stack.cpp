#include <iostream>
using namespace std;

// Node structure for stack
struct Node
{
    int data;
    Node* next;
};

int main()
{
    Node* top = NULL; // Points to the top of the stack
    Node* temp;
    int choice, value;

    do
    {
        cout << "\n--- Stack Menu ---";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Push
            temp = new Node;
            cout << "Enter value to push: ";
            cin >> value;
            temp->data = value;
            temp->next = top;
            top = temp;
            cout << value << " pushed onto the stack.";
            break;

        case 2: // Pop
            if (top == NULL)
                cout << "Stack Underflow! Nothing to pop.";
            else
            {
                cout << "Popped element: " << top->data;
                temp = top;
                top = top->next;
                delete temp;
            }
            break;

        case 3: // Display
            if (top == NULL)
                cout << "Stack is empty.";
            else
            {
                cout << "Stack elements (top to bottom): ";
                temp = top;
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
            break;

        case 4:
            cout << "Exiting program.";
            break;

        default:
            cout << "Invalid choice! Please try again.";
        }

    } while (choice != 4);

    return 0;
}
