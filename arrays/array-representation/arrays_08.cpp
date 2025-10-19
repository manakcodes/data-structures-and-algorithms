#include <iostream>
using namespace std;

int main()
{
    int rows = 0;
    cout << "enter the number of rows : ";
    cin >> rows;

    int cols = 0;
    cout << "enter the number of cols : ";
    cin >> cols;

    int base_address = 0;
    cout << "enter base address : ";
    cin >> base_address;

    int index_i = 0;
    cout << "enter the row index of the element : ";
    cin >> index_i;

    int index_j = 0;
    cout << "enter column index of the element : ";
    cin >> index_j;

    int datatype_size = 0;
    cout << "enter the size of the datatype : ";
    cin >> datatype_size;

    int RowMajorAddress_0 = base_address + ((index_i * cols) + index_j) * datatype_size;
    int ColumnMajorAddress_0 = base_address + ((index_j * rows) + index_i) * datatype_size;

    int RowMajorAddress_1 = base_address + (((index_i - 1) * cols) + (index_j - 1)) * datatype_size;
    int ColumnMajorAddress_1 = base_address + (((index_j - 1) * rows) + (index_i - 1)) * datatype_size;

    cout << "row major address (0 based compiler)     -> " << RowMajorAddress_0 << endl;
    cout << "column major address (0 based compiler)  -> " << ColumnMajorAddress_0 << endl;
    cout << "row major address (1 based compiler)     -> " << RowMajorAddress_1 << endl;
    cout << "column major address (1 based compiler)  -> " << ColumnMajorAddress_1 << endl;

    return 0;
}