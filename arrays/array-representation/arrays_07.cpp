#include <iostream>
using namespace std;

int main()
{
    int base_address = 0;
    cout << "enter base address : ";
    cin >> base_address;

    int i = 0;
    cout << "enter the index of the location you want to access : ";
    cin >> i;

    int w = 0;
    cout << "enter the sizeof the datatype of the array : ";
    cin >> w;

    int address_0i = base_address + i * w;
    cout << "address of " << i << "-th location (0 based compiler) -> : " << address_0i << endl;

    int address_1i = base_address + (i - 1) * w;
    cout << "address of " << i << "-th location (1 based compiler) -> : " << address_1i << endl;

    return 0;
}