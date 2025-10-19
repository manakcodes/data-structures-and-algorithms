#include "Array-ADT-00-Class.hpp"
#pragma once

int ArrayADT::PopBack()
{
    if (this->size == 0)
    {
        const char *error_message = "exit from method -> int ArrayADT::PopBack()\narray should have atleast 1 element in it for this operation\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET << endl;
        exit(EMPTY_ARRAY);
        return INFINITY;
    }
    int LastElement = this->arr[this->size--];

    if (this->size <= (this->capacity / SHRINKING_FACTOR) && this->size > DEFAULT_CAPACITY)
    {
        int NewCapacity = this->capacity / SHRINKING_FACTOR;
        int *NewArray = new int[NewCapacity]{0};
        copy(this->arr, this->arr + this->size, NewArray);
        delete[] this->arr;
        this->arr = NewArray;
        this->capacity = NewCapacity;
    }

    return LastElement;
}

int ArrayADT::PopFront()
{
    if (this->size == 0)
    {
        const char *error_message = "exit from method -> int ArrayADT::PopFront()\narray should have atleast 1 element in it for this operation\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET << endl;
        exit(EMPTY_ARRAY);
        return INFINITY;
    }

    int FirstElement = this->arr[0];

    int position = 0;

    for (int i = position; i < this->size - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }

    this->size--;

    if (this->size <= (this->capacity / SHRINKING_FACTOR) && this->size > DEFAULT_CAPACITY)
    {
        int NewCapacity = this->capacity / SHRINKING_FACTOR;
        int *NewArray = new int[NewCapacity]{0};
        copy(this->arr, this->arr + this->size, NewArray);
        delete[] this->arr;
        this->arr = NewArray;
        this->capacity = NewCapacity;
    }

    return FirstElement;
}

// Time Complexity : O(n)
int ArrayADT::DeleteByIndex(int index)
{
    if (index < 0 || index >= this->size)
    {
        cerr << RED << "exit from fn -> DeleteByIndex()\nINVALID INDEX !!\n\n"
             << RESET;
        exit(INVALID_INDEX);
    }

    int DeletedElement = this->arr[index];

    // LEFT SHIFT all the elements from the i-th element till the last element of
    // the array
    for (int i = index; i < this->size - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }

    this->size--;

    if (this->size > 0 && this->size < this->capacity / 4)
    {
        this->capacity /= SHRINKING_FACTOR;

        int *NewArray = new int[this->capacity]{0};
        copy(this->arr, this->arr + this->size, NewArray);

        delete[] this->arr;

        this->arr = NewArray;
    }

    return DeletedElement;
}

int ArrayADT::DeleteByValue(int element)
{
    if (this->size == 0)
    {
        const char *error_message = "ERROR MESSAGE ->\nexit from method -> DeleteByValue(int element)\nfor this operation the size of the array should be greater than 0\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET << endl;
        exit(EMPTY_ARRAY);
        return INFINITY;
    }

    int position = -1;

    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] == element)
        {
            position = i;
            break;
        }
    }

    if (position == -1)
    {
        string error_message = "WARNING MESSAGE ->\n" + to_string(element) + " is not present in the array\nno deletions performed\n";
        cerr << BOLD << UNDERLINE << error_message << RESET << endl;
        return INFINITY;
    }

    for (int i = position; i < this->size - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }

    this->size--;

    if (this->size <= (this->capacity / SHRINKING_FACTOR) && this->size > DEFAULT_CAPACITY)
    {
        int NewCapacity = this->capacity / SHRINKING_FACTOR;
        int *NewArray = new int[NewCapacity]{0};
        copy(this->arr, this->arr + this->size, NewArray);
        delete[] this->arr;
        this->arr = NewArray;
        this->capacity = NewCapacity;
    }

    return element;
}
