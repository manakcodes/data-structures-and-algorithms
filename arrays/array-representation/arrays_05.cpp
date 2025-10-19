#include <iostream>
using namespace std;

void PrintArray(int *arr, int size);

int main()
{
    int OldSize = 5;
    int *p = new int[OldSize];

    cout << "enter the elements of the array (current capacity = " << OldSize << "):" << endl;
    for (int i = 0; i < OldSize; i++)
    {
        cout << "enter element arr[" << i << "] : ";
        cin >> p[i];
    }

    int NewSize = 0;
    cout << "enter the new size of the array: ";
    cin >> NewSize;

    int *q = new int[OldSize + NewSize];

    // copy old elements
    for (int i = 0; i < OldSize; i++)
    {
        q[i] = p[i];
    }

    // delete old array and point p to new array
    delete[] p;
    p = q;
    q = nullptr;

    cout << "enter elements of the new array (current capacity = " << NewSize << "):" << endl;
    for (int i = OldSize; i < OldSize + NewSize; i++)
    {
        cout << "Enter element arr[" << i << "] : ";
        cin >> p[i];
    }

    cout << endl
         << "old array:" << endl;
    PrintArray(p, OldSize);

    cout << endl
         << "new array:" << endl;
    PrintArray(p, OldSize + NewSize);

    // free memory
    delete[] p;

    return 0;
}

void PrintArray(int *arr, int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}