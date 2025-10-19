# Array ADT Using `C++`

## 📦 Array ADT (Abstract Data Type)

### **Definition**

An **Array ADT (Abstract Data Type)** is a **collection of elements of the same data type**, stored in **contiguous memory locations**, and accessed using **indexing**.

It provides a way to represent and manipulate a sequence of fixed-size data items logically, **independent of implementation details** like memory layout or language-specific syntax.

---

### **Characteristics**

- **Homogeneous elements:** All elements are of the same data type.
- **Fixed size:** The size (number of elements) is defined at creation time and cannot be changed later.
- **Contiguous memory:** Elements are stored in continuous memory blocks.
- **Direct access:** Any element can be accessed in constant time using its index → `O(1)` access time.

---

### **Basic Operations**

| Operation   | Description                             | Time Complexity |
| ----------- | --------------------------------------- | --------------- |
| `Traversal` | Visit all elements in sequence          | O(n)            |
| `Insertion` | Add an element at a specific index      | O(n)            |
| `Deletion`  | Remove an element from a specific index | O(n)            |
| `Search`    | Find an element by value                | O(n)            |
| `Access`    | Retrieve an element using index         | O(1)            |

---

### **Representation**

If the base address of the array is `B` and the element size is `w` bytes,  
the address of the `i-th` element is given by:

`address(arr[i]) = B + i * w`

where
`B` = base address i.e the address of the arr[0]
`i` =

---

### **Example**

```cpp
int arr[5] = {10, 20, 30, 40, 50};

// Accessing elements
cout << arr[2];  // Output: 30
```

---

## Insertion In Array

- ### Insert At End Of The Array

- #### Method : `int ArrayADT::append(int element)`

inserts an element at the end of the array.
Time Complexity : `O(n)`
Space Complexity : `O(1)`

```cpp
void ArrayADT::append(int element)
{
    // CASE : if the array has space
    if (this->size < this->capacity)
    {
        // insert the element at the end of the array and increase the size
        this->arr[this->size++] = element;

        // return to exit the function
        return;
    }

    // CASE : if the array does not have any vacant space left

    // increase the current capacity by RESIZING_FACTOR
    this->capacity *= RESIZING_FACTOR;

    // allocate the memory for the new array to insert the element and set its
    // elements to 0
    int *NewArray = new int[this->capacity]{0};

    // copy the elements from the current array into the new array
    memcpy(NewArray, this->arr, this->size * sizeof(int));

    // deallocate the memory occupied by the current array
    delete[] this->arr;

    // make the pointer to the current array point to the new array
    this->arr = NewArray;

    // insert the element and increase the size
    this->arr[this->size++] = element;
}
```

- ### Insert Element At A Given Index

Method : `int ArrayADT::insert(int index, int element)`

Time Complexity : `O(n)`

Space Complexity : `O(1)`

```cpp
void ArrayADT::insert(int index, int element)
{
    // CASE : user enters invalid index, print a message and exit the function
    if (index < 0 || index > this->size)
    {
        // error message
        const char *error_msg = "exit from function -> insert(int index, int element)\nINVALID INDEX\n(0 <= valid_index <= size)\n\n";

        // print the error message
        cerr << START << error_msg << RESET;

        // exit to exit from the function
        exit(INVALID_INDEX);
    }

    // CASE : if the array is full, allocate the memory for the new array, copy
    // the elements from the current array and deallocate the memory of the
    // current array and make the new current array point to the new array
    if (this->size == this->capacity)
    {
        // increase the current capacity by the RESIZING_FACTOR
        this->capacity *= RESIZING_FACTOR;

        // allocate the memory for the new array of increased capacity with all
        // its elements set to 0
        int *NewArray = new int[this->capacity]{0};

        // copy the elements from the current array into new array
        memcpy(NewArray, this->arr, this->size * sizeof(int));

        // deallocate the memory of the current array
        delete[] this->arr;

        // make the current array point to the new array
        this->arr = NewArray;
    }

    // RIGHT SHIFT all the elements from the last element of the array till the
    // index-th element of the array by 1, to make space for the new element to
    // be inserted
    for (int i = this->size - 1; i >= index; i--)
    {
        this->arr[i + 1] = this->arr[i];
    }

    // now the index-th position of the array is vacant

    // insert the element at the index-th position
    this->arr[index] = element;

    // increase the size by 1, to mark the changes of insertion
    this->size++;
}
```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

## Linear Search (Sequential Search)

### Classic Linear Search

**Concept:**  
Linear Search (also known as Sequential Search) is the simplest searching technique.  
It checks each element of the array one by one until the target element is found or the end of the array is reached.

**Characteristics:**

- **Simple:** Easy to implement and understand.
- **Unsorted Data:** Works on both sorted and unsorted arrays.
- **Inefficient for Large Data:** Performance degrades linearly with array size.

**Complexity Analysis:**

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

```cpp
int ArrayADT::LinearSearchFirstOccurrence(int key)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
```

### Linear Search (Search for the Last Occurrence)

**Concept:**  
This variation of linear search scans the entire array and keeps updating the index each time the target element is found.  
By the end of the traversal, the index of the **last occurrence** of the element is returned.

**Characteristics:**

- **Exhaustive:** Continues searching even after finding a match.
- **Reliable:** Ensures the position of the last occurrence is correctly identified.
- **In-place:** Does not require additional memory.

**Complexity Analysis:**

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

```cpp
int ArrayADT::LinearSearchLastOccurrence(int key)
{
    for (int i = this->size - 1; i >= 0; i--)
    {
        if (this->arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
```

- ### Linear Search (Search For All Occurrences)

**Concept:**  
Instead of stopping after finding the first match, this version of linear search continues traversing the entire array to find **all indices** where the target element appears.  
The indices of occurrences are typically stored in another array or list.

**Characteristics:**

- **Exhaustive:** Finds every occurrence of the element.
- **Useful For:** Datasets where duplicate elements may exist.
- **In-place or Not:** Depends on implementation — may require an auxiliary array to store indices.

**Complexity Analysis:**

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

```cpp
ArrayADT ArrayADT::LinearSearchAllOccurrences(int key)
{
    ArrayADT indexes = ArrayADT();

    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] == key)
        {
            indexes.append(i);
        }
    }

    return indexes;
}
```

---

- ### Linear Search (Using Transposition)

- **Idea:**  
  In this variation of linear search, whenever the key element is found, it is swapped with the element just before it.  
  This gradually moves frequently accessed elements closer to the beginning of the array, improving average search time for non-uniform access patterns.

- **Advantages:**

  - Improves search performance for elements that are accessed repeatedly.
  - Simple to implement with minimal overhead.

- **Disadvantages:**

  - Still linear in the worst case.
  - Can slightly disturb the original order of elements.

- **Time Complexity:** `O(n)` — the element may be at the end in the worst case.
- **Space Complexity:** `O(1)` — only a few auxiliary variables are used.

```cpp
int ArrayADT::LinearSearchUsingTransposition(int key)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] == key)
        {
            if (i > 0)
            {
                swap(this->arr[i], this->arr[i - 1]);
            }
            return (i > 0) ? (i - 1) : (0);
        }
    }
    return -1;
}
```

---

- ### Linear Search (Using Move To Front Technique)

### Linear Search (Using Move-To-Front Technique)

**Concept:**  
This is an optimization over the standard linear search.  
When the target element is found, it is **moved directly to the front** of the array (`arr[i]` ↔ `arr[0]`).  
This ensures that frequently accessed elements stay near the beginning, significantly reducing the time for future searches involving the same element.

**Characteristics:**

- **Highly Adaptive:** Frequently searched elements quickly move to the front, improving average performance.
- **In-place:** No additional memory is required.
- **Unstable:** Changes the relative ordering of elements.
- **Best Use Case:** When certain elements are searched much more often than others.

**Complexity Analysis:**

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

```cpp
int ArrayADT::LinearSearchUsingMoveToFront(int key)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] == key)
        {
            swap(this->arr[0], this->arr[i]);
            return 0;
        }
    }

    return -1;
}
```

## `get`, `set`, `max`, `min`, `avg`

### `GetElement`

`RETURNS` an element present at the given index (0 based index) incase of invalid index i.e `if (index < 0 || index > size)` then `PRINTS` a message and exits from the method.

---

#### Method Name : `int ArrayADT::GetElement(int index)`

#### Time Complexity : `O(1)`

#### Space Complexity : `O(1)`

```cpp
int ArrayADT::GetElement(int index)
{
    // CASE : if the user pass an INVALID index to the method, print a message
    // exit the method
    if (index < 0 || index > size)
    {
        const char *error_msg = "exit from function -> GetElement(int index)\nINVALID INDEX\n(0 <= valid_index <= size)\n\n";
        cerr << START << error_msg << RESET;
        exit(INVALID_INDEX);
    }

    // return the element present at the valid index
    return this->arr[index];
}
```

---

### `int ArrayADT::SetElement(int index)`

#### Time Complexity : `O(1)`

#### Space Complexity : `O(1)`

```cpp
void ArrayADT::SetElement(int index, int element)
{
    // CASE : if the user passes an INVALID index to the method, print a message
    // and exit the method
    if (index < 0 || index > size)
    {
        const char *error_msg = "exit from function -> SetElement(int index)\nINVALID INDEX\n(0 <= valid_index <= size)\n\n";
        cerr << START << error_msg << RESET;
        exit(INVALID_INDEX);
    }

    // set the element at the valid index of the current ArrayADT object
    this->arr[index] = element;
}
```

---

### `int ArrayADT::GetMax()`

in case of empty array it `PRINTS` a message and exits from the method, otherwise it traverses the whole array to find the max element

#### Time Complexity : `O(n)`

#### Space Complexity : `O(1)`

```cpp
int ArrayADT::GetMax()
{
    // CASE : if the size of the array is 0, then print a message and exit the
    // method
    if (this->size == 0)
    {
        const char *error_msg = "exit from function -> GetMax()\nEMPTY ARRAY\n(0 < array_size)\n\n";
        cerr << START << error_msg << RESET;
        exit(EMPTY_ARRAY);
    }

    // assume that the first element of the element is the max element
    int max = arr[0];

    // traverse the array to find the max element of the array
    for (int i = 1; i < this->size; i++)
    {

        // if any element greater than the current max is found, then update
        // the max to that element
        if (max < arr[i])
        {

            // update the max to the current max element found
            max = arr[i];
        }
    }

    // return the max element of the array
    return max;
}
```

---

## `int ArrayADT::GetMin()`

in case of empty array it `PRINTS` a message and exits from the method, otherwise it traverses the whole array to find the `min` element

#### Time Complexity : `O(n)`

#### Space Complexity : `O(1)`

```cpp
int ArrayADT::GetMin()
{
    // CASE : if the size of the array is 0, then print a message and exit the
    // method
    if (this->size == 0)
    {
        const char *error_msg = "exit from method -> GetMin()\nEMPTY ARRAY\n(0 < array_size)\n\n";
        cerr << START << error_msg << RESET;
        exit(EMPTY_ARRAY);
    }

    // assume that the first element of the element is the min element
    int min = arr[0];

    // traverse the array to find the min element of the array
    for (int i = 1; i < this->size; i++)
    {

        // if any element less than the current min is found, then update
        // the current min to that element
        if (min > arr[i])
        {

            // update the min to the current min element found
            min = arr[i];
        }
    }

    // return the min element of the array
    return min;
}

```

---

## `int ArrayADT::GetSum()`

#### Time Complexity : `O(n)`

#### Space Complexity : `O(1)`

```cpp
int ArrayADT::GetSum()
{
    // CASE : if the array is empty, then print a message and exit the method
    if (this->size == 0)
    {
        const char *error_msg = "exit from method -> GetMin()\nEMPTY ARRAY\n(0 < array_size)\n\n";
        cerr << START << error_msg << RESET;
        exit(EMPTY_ARRAY);
    }

    // var to accumulate the sum of all the elements of the array
    int sum = 0;

    // loop to calculate the sum of all elements of array
    for (int i = 0; i < this->size; i++)
    {
        // compute the sum
        sum += this->arr[i];
    }

    // return the sum
    return sum;
}
```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---

```cpp

```

---
