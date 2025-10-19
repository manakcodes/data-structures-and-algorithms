#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    cout << "enter the size of the array : ";
    cin >> size;

    int *p = new int[size];

    cout << "array of size " << size << " created successfully" << endl;

    delete[] p;
    return 0;
}