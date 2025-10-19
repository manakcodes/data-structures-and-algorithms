#include <iostream>
using namespace std;

void PrintArray(int *arr, int size);

void DeclaringArrayExample();
void DeclaringAndInitializingArrayExample();
void DeclaringAndInitializingArrayWithFewValues();
void DeclaringAndInitializingArrayWithZeroesExample();
void DeclaringAndInitializingArrayWithWithoutSizeExample();

int main()
{
    DeclaringArrayExample();
    DeclaringAndInitializingArrayExample();
    DeclaringAndInitializingArrayWithFewValues();
    DeclaringAndInitializingArrayWithZeroesExample();
    DeclaringAndInitializingArrayWithWithoutSizeExample();
    return 0;
}

void PrintArray(int *arr, int size)
{
    cout << endl
         << "[";
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

void DeclaringArrayExample()
{
    int arr[5];
    int size = 5;
    cout << "declared array : " << endl
         << endl;
    cout << "sizeof int : " << sizeof(int) << endl;
    cout << "sizeof array : " << size << endl;
    PrintArray(arr, size);
    cout << endl;
}

void DeclaringAndInitializingArrayExample()
{
    int arr[5] = {2, 4, 6, 8, 10};
    int size = 5;
    cout << "declared and initialized array : " << endl
         << endl;
    cout << "sizeof int : " << sizeof(int) << endl;
    cout << "sizeof array : " << size << endl;
    PrintArray(arr, size);
    cout << endl;
}

void DeclaringAndInitializingArrayWithFewValues()
{
    int arr[5] = {2, 4};
    int size = 5;
    cout << "declared and initialized array with few values : " << endl
         << endl;
    cout << "sizeof int : " << sizeof(int) << endl;
    cout << "sizeof array : " << size << endl;
    PrintArray(arr, size);
    cout << endl;
}

void DeclaringAndInitializingArrayWithZeroesExample()
{
    int arr[5] = {0};
    int size = 5;
    cout << "declared and initialized array with 0 : " << endl
         << endl;
    cout << "sizeof int : " << sizeof(int) << endl;
    cout << "sizeof array : " << size << endl;
    PrintArray(arr, size);
    cout << endl;
}

void DeclaringAndInitializingArrayWithWithoutSizeExample()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "declared and initialized array without size : " << endl
         << endl;
    cout << "sizeof int : " << sizeof(int) << endl;
    cout << "sizeof array : " << size << endl;
    PrintArray(arr, size);
    cout << endl;
}