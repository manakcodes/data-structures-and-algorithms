# Arrays In `C++`

## Basics Of Arrays

## Arrays

```cpp
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
```

```bash
sizeof int : 4
sizeof array : 5
index : 0 -> element : 10 -> address : 0x16fbeeee4
index : 1 -> element : 20 -> address : 0x16fbeeee8
index : 2 -> element : 30 -> address : 0x16fbeeeec
index : 3 -> element : 40 -> address : 0x16fbeeef0
index : 4 -> element : 50 -> address : 0x16fbeeef4
```

---

## Declaring And Initializing Array

```cpp
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
```

```bash
declared array :

sizeof int : 4
sizeof array : 5

[1, 1868476672, 1, 1, 0]

declared and initialized array :

sizeof int : 4
sizeof array : 5

[2, 4, 6, 8, 10]

declared and initialized array with few values :

sizeof int : 4
sizeof array : 5

[2, 4, 0, 0, 0]

declared and initialized array with 0 :

sizeof int : 4
sizeof array : 5

[0, 0, 0, 0, 0]

declared and initialized array without size :

sizeof int : 4
sizeof array : 10

[2, 4, 6, 8, 10, 12, 14, 16, 18, 20]

```

---

## Traversing Array

```cpp
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
    cout << "printing array using complex pointer arithmetic *(&(*(&(*(arr + i)))))" << endl << endl;
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
```

```bash

sizeof int (in bytes): 4
sizeof array: 5

printing array using ArrayName[index]

index   element address
----------------------------------
0       10      0x16b072ee0
1       20      0x16b072ee4
2       30      0x16b072ee8
3       40      0x16b072eec
4       50      0x16b072ef0

printing array using index[ArrayName]

index   element address
----------------------------------
0       10      0x16b072ee0
1       20      0x16b072ee4
2       30      0x16b072ee8
3       40      0x16b072eec
4       50      0x16b072ef0

printing array using pointer arithmetic *(arr + i)

index   element address
----------------------------------
0       10      0x16b072ee0
1       20      0x16b072ee4
2       30      0x16b072ee8
3       40      0x16b072eec
4       50      0x16b072ef0

printing array using complex pointer arithmetic *(&(*(&(*(arr + i)))))

index   element address
----------------------------------
0       10      0x16b072ee0
1       20      0x16b072ee4
2       30      0x16b072ee8
3       40      0x16b072eec
4       50      0x16b072ef0

```

---

## Static vs Dynamic Arrays

**ILLEGAL CODE IN C**

```c
#include <stdio.h>

int main()
{
    int size = 0;
    printf("enter the size of the array : ");
    scanf("%zu", &size);

    int arr[size];

    printf("array of size %zu created successfully\n", size);

    return 0;
}
```

```bash
ERROR
```

**NOTE** : The array created in the following code snippet is created in the **STACK** region of the memory.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    cout << "enter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << "array of size " << size << " created successfully" << endl;
    return 0;
}
```

```bash
enter the size of the array : 10
array of size 10 created successfully
```

---

**NOTE :** The array created in the following code snippet is created in the **HEAP** section of the memory, but we cannot directly access the **HEAP** memory so we need to create a **POINTER** to access it, the memory for the **POINTER** will be allocated in the **STACK** area of the memory.

> **NOTE:**  
> The array created in the following code snippet is allocated in the **HEAP** section of memory using **dynamic memory allocation** (e.g., using `new` or `malloc`).
>
> However, we cannot directly access the **HEAP** memory without a reference, so we use a **POINTER** variables to store the address of the heap-allocated array.
>
> The **POINTER** itself is stored in the **STACK** memory, while the actual array elements reside in the **HEAP**. (the **POINTER** acts as an the name of the array).
>
> **Explanation:**
>
> - **STACK :** Stores local variables, including the pointer itself.
> - **HEAP :** Stores dynamically allocated memory (e.g., arrays created with `new` or `malloc`).
> - You must **manually** free **HEAP** memory using `delete` or `free` to prevent **MEMORY LEAKS**.

```cpp
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
```

```bash
enter the size of the array : 10
array of size 10 created successfully
```

---

## Resizing Arrays

```cpp
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
```

```bash
enter the elements of the array (current capacity = 5):
enter element arr[0] : 10
enter element arr[1] : 20
enter element arr[2] : 30
enter element arr[3] : 40
enter element arr[4] : 50
enter the new size of the array: 3
enter elements of the new array (current capacity = 3):
Enter element arr[5] : 1
Enter element arr[6] : 2
Enter element arr[7] : 3

old array:
[10, 20, 30, 40, 50]

new array:
[10, 20, 30, 40, 50, 1, 2, 3]
```

---

# Why Array Size Cannot Grow Dynamically?

Arrays in most programming languages have a **fixed size** for the following reasons:

1. **Contiguous Memory Allocation**  
   Arrays are stored in **contiguous memory locations**, which means all elements are placed next to each other in memory.  
   This allows:

   - **Fast access** using indices (`O(1)` time complexity).
   - Efficient **pointer arithmetic** and memory traversal.

2. **Memory Availability Uncertainty**  
   When we try to increase the size of an array, we cannot guarantee that there is enough **free contiguous memory** right after the array in the memory.  
   If the memory is fragmented, resizing in-place is **impossible**.

3. **Performance Concerns**  
   Dynamically increasing array size would require:

   - Allocating a **new larger array** in a different memory block.
   - **Copying all existing elements** to the new array.
     This process is **time-consuming** and **inefficient**, especially for large arrays.

4. **Alternative Solutions**
   - **Dynamic arrays** or **vectors** in languages like C++ and Java internally handle resizing by creating a new larger array and copying elements.
   - They often allocate extra space in advance to reduce the frequency of resizing.

**Conclusion:**  
Due to the need for **contiguous memory**, uncertainty about free memory, and performance overhead, traditional arrays **cannot grow dynamically** after creation. Use dynamic array structures like **`std::vector`** in C++ for flexible resizing.

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

---
