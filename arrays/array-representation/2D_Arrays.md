# 2-D Arrays (Matrix) In `C++`

## Creating 2D Arrays

- ### Creating 2D Array Inside The **STACK** Memory

- In this approach, the entire 2D array is allocated on the **STACK**.

- The size of the array must be known at compile-time.
- Both rows and columns are fixed and stored contiguously in stack memory.
- Suitable for small arrays because the stack has limited size.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int arr[3][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}};

    cout << arr[0][0] << endl;
    cout << arr[1][1] << endl;
    cout << arr[2][1] << endl;
    cout << arr[1][0] << endl;

    return 0;
}
```

```bash
10
60
100
50
```

---

### Creating 2D Array Partially in the **STACK** Memory & Partially in the **HEAP** Memory

We can create a 2D array by:

1. Creating an array of **POINTERS** in the **STACK**.
2. Allocating the actual rows (or columns) in the **HEAP** using `new` or `malloc`.

This approach allows:

- The array of pointers itself to be **fast-access stack memory**.
- Each row to have **dynamic size** and reside in the **heap**, allowing flexible memory usage.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int *arr[3];

    arr[0] = new int[4]{10, 20, 30, 40};
    arr[1] = new int[4]{50, 60, 70, 80};
    arr[2] = new int[4]{90, 100, 110, 120};

    cout << arr[0][0] << endl;
    cout << arr[1][1] << endl;
    cout << arr[2][1] << endl;
    cout << arr[1][0] << endl;

    delete[] arr[0];
    delete[] arr[1];
    delete[] arr[2];

    arr[0] = arr[1] = arr[2] = nullptr;

    return 0;
}

```

```bash
10
60
100
50
```

---

### Creating 2D Array Inside The **HEAP** Memory

In this approach, both the array of **POINTERS** and the individual rows are allocated in the **HEAP** memory. This allows dynamic sizing of both dimensions and avoids stack memory limitations.

- First, create an array of pointers in the **HEAP**.
- Then, allocate memory for each row dynamically in the **HEAP**.
- Always remember to `delete[]` each row first and then the array of pointers to avoid memory leaks.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int **arr;

    arr = new int *[3];

    arr[0] = new int[4]{10, 20, 30, 40};
    arr[1] = new int[4]{50, 60, 70, 80};
    arr[2] = new int[4]{90, 100, 110, 120};

    cout << arr[0][0] << endl;
    cout << arr[1][1] << endl;
    cout << arr[2][1] << endl;
    cout << arr[1][0] << endl;

    delete[] arr[0];
    delete[] arr[1];
    delete[] arr[2];
    delete[] arr;

    arr = nullptr;

    return 0;
}
```

```bash
10
60
100
50
```

---

## General Syntax To Create A 2D Array In the **HEAP**

```cpp
#include <iostream>
using namespace std;

int main()
{
    int rows = 3;
    int cols = 4;

    int **arr = new int *[rows];

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }

    int x = 10;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = (x += 10);
        }
    }

    cout << "rows : " << rows << endl;
    cout << "cols : " << cols << endl;
    cout << "2D array : " << endl
         << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

```bash
rows : 3
cols : 4
2D array :

20 30 40 50
60 70 80 90
100 110 120 130
```

---

## Accessing 2D Arrays

- ### Using Row And Column Indices `<ArrayName>[<RowIndex>][<ColumnIndex>]`

```cpp
#include <iostream>
using namespace std;

int main()
{
    int arr[3][4] =
        {
            {10, 20, 30, 40},
            {50, 60, 70, 80},
            {90, 100, 110, 120}
        };

    int rows = 3;
    int cols = 4;

    cout << "2D array using row and column indices" << endl
         << endl;

    cout << "rows : " << rows << endl;
    cout << "columns : " << cols << endl
         << endl;

    cout << "addresses" << endl
         << endl;


    // this block will print the memory address
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << &arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "elements" << endl
         << endl;

    // this block will print the elements of the 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

```bash
2D array using row and column indices

rows : 3
columns : 4

addresses

0x16fdaaec8 0x16fdaaecc 0x16fdaaed0 0x16fdaaed4
0x16fdaaed8 0x16fdaaedc 0x16fdaaee0 0x16fdaaee4
0x16fdaaee8 0x16fdaaeec 0x16fdaaef0 0x16fdaaef4

elements

10 20 30 40
50 60 70 80
90 100 110 120
```

- ### Using `POINTER` Arithmetic

```cpp
#include <iostream>
using namespace std;

int main()
{
    int arr[3][4] =
        {
            {10, 20, 30, 40},
            {50, 60, 70, 80},
            {90, 100, 110, 120}};

    int rows = 3;
    int cols = 4;

    cout << "2D array using pointer arithmetic" << endl
         << endl;

    cout << "rows : " << rows << endl;
    cout << "columns : " << cols << endl
         << endl;

    cout << "addresses" << endl
         << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << ((arr + i) + j) << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "elements" << endl
         << endl;

    // this block will print the elements of 2D array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }

    return 0;
}
```

```bash
2D array using pointer arithmetic

rows : 3
columns : 4

addresses

0x16d3d2ec8 0x16d3d2ed8 0x16d3d2ee8 0x16d3d2ef8
0x16d3d2ed8 0x16d3d2ee8 0x16d3d2ef8 0x16d3d2f08
0x16d3d2ee8 0x16d3d2ef8 0x16d3d2f08 0x16d3d2f18

elements

10 20 30 40
50 60 70 80
90 100 110 120
```

---

## Compiler Representation Of 1D Arrays

Compilers, under the hood, access array elements using the **base address**.  
They use the formula:

`address(arr[i]) = B + i * w`

Where:

- `B` = base address of the array, i.e., the address of the first element of the array i.e the address of`arr[0]`
- `i` = the `i-th` index that the compiler wants to access
- `w` = size of the data type of the array elements

Some languages allow array declarations starting from index 1, in which case they use:

`address(arr[i]) = B + (i - 1) * w`

In **C/C++**, arrays start strictly from index 0 to avoid the overhead of calculating `(i - 1)`.

```cpp
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
```

```bash
enter base address : 1000
enter the index of the location you want to access : 5
enter the sizeof the datatype of the array : 4
address of 5-th location (0 based compiler) -> : 1020
address of 5-th location (1 based compiler) -> : 1016
```

---

## Compiler Representation Of 2D Arrays

Some compilers internally **store a 2D array** as a **1D array** in memory.  
This storage can follow one of two conventions:

### **Row Major Form**

- Elements of the 2D array are stored **row by row** in contiguous memory.
- For a 2D array of size `m × n`,  
  the address of an element `arr[i][j]` is computed as:
  `address(arr[i][j]) = B + (i * n + j) * w`

  where:

- `B` → base address of the array (address of `arr[0][0]`)
- `i` → row index
- `j` → column index
- `n` → total number of columns
- `w` → size of each element (in bytes)

- **Used by:** C, C++, Python (NumPy by default)

### **Column Major Form**

- Elements of the 2D array are stored **column by column** in contiguous memory.
- For a 2D array of size `m × n`,  
  the address of an element `arr[i][j]` is computed as:

`address(arr[i][j]) = B + (j * m + i) * w`

where:

- `B` → base address of the array (address of `arr[0][0]`)
- `i` → row index
- `j` → column index
- `n` → total number of columns
- `w` → size of each element (in bytes)

- **Used by:** Fortran, MATLAB, R

### Additional Notes

- Both representations are **O(n²)** in memory layout.
- **Row-major** order works best for **left-to-right traversal** (typical in C/C++).
- **Column-major** order is efficient for **top-to-bottom traversal** (typical in MATLAB/Fortran).

```cpp
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
```

```bash
enter the number of rows : 3
enter the number of cols : 4
enter base address : 200
enter the row index of the element : 1
enter column index of the element : 3
enter the size of the datatype : 4
row major address (0 based compiler)     -> 228
column major address (0 based compiler)  -> 240
row major address (1 based compiler)     -> 208
column major address (1 based compiler)  -> 224
```

---

## `Row-Major` Mapping Program

#### Time Complexity : `O(n²)`

can be reduces to `O(n)` by using `Horner's Rule`

```cpp
#include <iostream>
using namespace std;

int main()
{
    int dims = 0;
    cout << "enter the number of dimensions of the array : ";
    cin >> dims;

    int *dimensions = new int[dims]{0};
    int *indexes = new int[dims]{0};

    cout << endl;

    for (int i = 0; i < dims; i++)
    {
        cout << "enter dimension[" << i << "] : ";
        cin >> dimensions[i];
    }

    cout << endl;

    for (int i = 0; i < dims; i++)
    {
        cout << "enter index[" << i << "] : ";
        cin >> indexes[i];
    }

    cout << endl;

    int base_address = 0;
    cout << "enter base address : ";
    cin >> base_address;

    int sizeof_datatype = 0;
    cout << "enter the size of the datatype : ";
    cin >> sizeof_datatype;

    int sum = 0;
    int prod = 1;

    for (int i = 0; i < dims; i++)
    {
        prod = indexes[i];
        for (int j = i + 1; j < dims; j++)
        {
            prod *= dimensions[j];
        }

        sum += prod;
    }

    cout << endl;

    cout << "row major address mapping : " << base_address + (sum * sizeof_datatype) << endl;
    return 0;
}
```

```bash
enter the number of dimensions of the array : 4

enter dimension[0] : 2
enter dimension[1] : 2
enter dimension[2] : 2
enter dimension[3] : 2

enter index[0] : 0
enter index[1] : 1
enter index[2] : 2
enter index[3] : 3

enter base address : 2000
enter the size of the datatype : 4

row major address mapping : 2044
```

---

## `Column-Major` Mapping Program

#### Time Complexity : `O(n²)`

can be reduces to `O(n)` by using `Horner's Rule`

```cpp
#include "ArrayADT.hpp"
#include <iostream>
using namespace std;

int main()
{
    int dims = 0;
    cout << "enter the number of dimensions of the array : ";
    cin >> dims;

    int *dimensions = new int[dims]{0};
    int *indexes = new int[dims]{0};

    cout << endl;

    for (int i = 0; i < dims; i++)
    {
        cout << "enter dimension[" << i << "] : ";
        cin >> dimensions[i];
    }

    cout << endl;

    for (int i = 0; i < dims; i++)
    {
        cout << "enter index[" << i << "] : ";
        cin >> indexes[i];
    }

    cout << endl;

    int base_address = 0;
    cout << "enter base address : ";
    cin >> base_address;

    int sizeof_datatype = 0;
    cout << "enter the size of the datatype : ";
    cin >> sizeof_datatype;

    int sum = 0;
    int prod = 1;

    for (int i = dims - 1; i >= 0; i--)
    {
        prod = indexes[i];

        for (int j = i - 1; j >= 0; j--)
        {
            prod *= dimensions[j];
        }

        sum += prod;
    }

    cout << endl;

    cout << "column major address mapping : " << base_address + (sum * sizeof_datatype) << endl;
    return 0;
}
```

```bash
enter the number of dimensions of the array : 4

enter dimension[0] : 2
enter dimension[1] : 2
enter dimension[2] : 2
enter dimension[3] : 2

enter index[0] : 0
enter index[1] : 1
enter index[2] : 2
enter index[3] : 3

enter base address : 2000
enter the size of the datatype : 4

column major address mapping : 2136
```

---

```cpp

```

```bash

```

---

```cpp

```

```bash

```

---

```cpp

```

```bash

```

---

```cpp

```

```bash

```
