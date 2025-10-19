#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int size = sizeof(arr) / sizeof(arr[0]);

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    cout << "sizeof int : " << sizeof(int) << endl;
    cout << "sizeof array : " << size << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "index : " << i << " -> element : " << arr[i] << " -> address : " << &arr[i] << endl;
    }
    return 0;
}