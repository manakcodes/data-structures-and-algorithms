# Reverse, Rotate And Shift In Arrays

### Reversing An Array Using An Auxiliary Array

Creates a new array and copies elements from the original array in reverse order. Returns the reversed array. The original array remains unchanged.

```cpp
ArrayADT *ArrayADT::ReverseArrayUsingAuxiliaryArray()
{
    ArrayADT *auxiliary_arr = new ArrayADT(this->size);

    // copy the elements of the current array into the auxiliary array in the
    // reverse order

    int index = 0;
    for (int i = this->size - 1; i >= 0; i--)
    {
        auxiliary_arr->insert(index++, this->arr[i]);
    }

    // return the reverse array
    return auxiliary_arr;
}
```

### Reversing An Array in Place

Reverses the elements of the array within the same memory space, without using an auxiliary array.

```cpp
void ArrayADT::ReverseOriginalArray()
{
    if (this->size == 0)
    {
        return;
    }
    int left = 0;
    int right = this->size - 1;

    while (left < right)
    {
        swap(this->arr[left], this->arr[right]);
        left++;
        right--;
    }
}

```

---

## Rotating Array

### Left Rotation In Array

Performs a left rotation on the array. Each element moves one position to the left, and the first element is moved to the last position. If the array is empty, the method returns immediately.

```cpp
void ArrayADT::LeftRotateArray()
{
    if (this->size == 0)
    {
        return;
    }

    int FirstElement = this->arr[0];

    for (int i = 0; i < this->size - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }

    this->arr[this->size - 1] = FirstElement;
}
```

### Right Rotation In Array

Performs a right rotation on the array. Each element moves one position to the right, and the last element is moved to the first position. If the array is empty, the method returns immediately.

```cpp
void ArrayADT::RightRotateArray()
{
    if (this->size == 0)
    {
        return;
    }

    int LastElement = this->arr[this->size - 1];

    for (int i = this->size - 1; i >= 1; i--)
    {
        this->arr[i] = this->arr[i - 1];
    }

    this->arr[0] = LastElement;
}

```

---

### Left Shift In Array

Performs a left shift on the array. Each element moves one position to the left, and the last position is filled with the provided PlaceHolder value. If the array is empty, the method returns immediately.

```cpp
void ArrayADT::LeftShiftArray(int PlaceHolder)
{
    if (this->size == 0)
    {
        return;
    }

    for (int i = 0; i < this->size - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }

    this->arr[this->size - 1] = PlaceHolder;
}
```

### Right Shift On Array

Performs a right shift on the array. Each element moves one position to the right, and the first position is filled with the provided PlaceHolder value. If the array is empty, the method returns immediately.

```cpp
void ArrayADT::RightShiftArray(int PlaceHolder)
{
    if (this->size == 0)
    {
        return;
    }

    for (int i = this->size - 1; i >= 1; i--)
    {
        this->arr[i] = this->arr[i - 1];
    }

    this->arr[0] = PlaceHolder;
}
```

## Checking If An Array Is Sorted Or Not

```cpp
bool ArrayADT::IsSortedInAscendingOrder()
{
    if (this->size <= 1)
    {
        return true;
    }

    for (int i = 1; i < this->size; i++)
    {
        if (this->arr[i] < this->arr[i - 1])
        {
            return false;
        }
    }
    return true;
}
```

```cpp
bool ArrayADT::IsSortedInDescendingOrder()
{
    if (this->size <= 1)
    {
        return true;
    }

    for (int i = 1; i < this->size; i++)
    {
        if (this->arr[i] > this->arr[i - 1])
        {
            return false;
        }
    }
    return true;
}
```

```cpp
bool ArrayADT::IsSorted()
{
    if (this->size <= 1)
    {
        return true;
    }

    return this->IsSortedInAscendingOrder() || this->IsSortedInDescendingOrder();
}
```

---

## Inserting An Element In A Sorted Array

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
