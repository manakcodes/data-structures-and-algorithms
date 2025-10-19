#include <iostream>
using namespace std;

void PrintArrayUsingIndex(int *arr, int size);
void PrintArrayUsingReverseIndexNotation(int *arr, int size);
void PrintArrayUsingPointerArithmetic(int *arr, int size);
void PrintArrayUsingComplexPointerArithmetic(int *arr, int size);

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << endl;
    cout << "sizeof int (in bytes): " << sizeof(int) << endl;
    cout << "sizeof array: " << size << endl
         << endl;

    PrintArrayUsingIndex(arr, size);
    PrintArrayUsingReverseIndexNotation(arr, size);
    PrintArrayUsingPointerArithmetic(arr, size);
    PrintArrayUsingComplexPointerArithmetic(arr, size);

    return 0;
}

void PrintArrayUsingIndex(int *arr, int size)
{
    cout << "printing array using ArrayName[index]" << endl
         << endl;
    cout << "index\telement\taddress" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << i << "\t" << arr[i] << "\t" << &arr[i] << endl;
    }

    cout << endl;
}

void PrintArrayUsingReverseIndexNotation(int *arr, int size)
{
    cout << "printing array using index[ArrayName]" << endl
         << endl;
    cout << "index\telement\taddress" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << i << "\t" << i[arr] << "\t" << &i[arr] << endl;
    }

    cout << endl;
}

void PrintArrayUsingPointerArithmetic(int *arr, int size)
{
    cout << "printing array using pointer arithmetic *(arr + i)" << endl
         << endl;
    cout << "index\telement\taddress" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << i << "\t" << *(arr + i) << "\t" << (arr + i) << endl;
    }

    cout << endl;
}

void PrintArrayUsingComplexPointerArithmetic(int *arr, int size)
{
    cout << "printing array using complex pointer arithmetic *(&(*(&(*(arr + i)))))" << endl
         << endl;
    cout << "index\telement\taddress" << endl;
    cout << "----------------------------------" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << i << "\t"
             << *(&(*(&(*(arr + i))))) << "\t"
             << &(*(&(*(arr + i)))) << endl;
    }

    cout << endl;
}