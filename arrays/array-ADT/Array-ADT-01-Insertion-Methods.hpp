#include "Array-ADT-00-Class.hpp"
#pragma once

void ArrayADT::PushFront(int element)
{
    if (this->size == this->capacity)
    {
        int NewCapacity = this->capacity * GROWTH_FACTOR;
        int *NewArray = new int[NewCapacity]{0};
        copy(this->arr, this->arr + this->size, NewArray);
        delete[] this->arr;
        this->arr = NewArray;
        this->capacity = NewCapacity;
    }

    int position = 0;

    for (int i = this->size - 1; i >= position; i--)
    {
        this->arr[i + 1] = this->arr[i];
    }

    this->arr[position] = element;
    this->size++;
}

void ArrayADT::PushBack(int element)
{
    if (this->size == this->capacity)
    {
        int NewCapacity = this->capacity *GROWTH_FACTOR;
        int *NewArray = new int[NewCapacity]{0};
        copy(this->arr, this->arr + this->size, NewArray);
        delete[] this->arr;
        this->arr = NewArray;
        this->capacity = NewCapacity;
    }
    this->arr[this->size++] = element;
}


void ArrayADT::InsertByIndex(int index, int element)
{
    // CASE : user enters invalid index, print a message and exit the function
    if (index < 0 || index > this->size)
    {
        const char *error_message = "exit from function -> insert(int index, int element)\nINVALID INDEX\n(0 <= valid_index <= size)\n\n";
        cerr << BOLD << UNDERLINE   << error_message << RESET;
        exit(INVALID_INDEX);
    }

    // CASE : if the array is full, allocate the memory for the new array, copy
    // the elements from the current array and deallocate the memory of the
    // current array and make the new current array point to the new array
    if (this->size == this->capacity)
    {
        // increase the current capacity by the RESIZING_FACTOR
        this->capacity *= GROWTH_FACTOR;

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

void ArrayADT::InsertInSortedArray(int element)
{

    if (this->size == 0)
    {
        this->arr[0] = element;
        this->size++;
        return;
    }

    if (this->size == this->capacity)
    {
        this->capacity *= GROWTH_FACTOR;

        int *NewArray = new int[this->capacity]{0};

        memcpy(NewArray, this->arr, this->size * sizeof(int));

        delete[] this->arr;

        this->arr = NewArray;
    }

    // int pos = -1;

    // for (int i = 0; i < this->size; i++)
    // {
    //     if (arr[i] > element)
    //     {
    //         pos = i;
    //         break;
    //     }
    // }

    // if (pos == -1)
    // {
    //     pos = (this->arr[0] > element ? 0 : this->size);
    // }

    // this->insert(pos, element);

    int end = this->size - 1;

    if (this->IsSortedInAscendingOrder())
    {
        while (end >= 0 && element < this->arr[end])
        {
            this->arr[end + 1] = this->arr[end];
            end--;
        }
    }

    else
    {
        while (end >= 0 && element > this->arr[end])
        {
            this->arr[end + 1] = this->arr[end];
            end--;
        }
    }

    this->arr[end + 1] = element;
    this->size++;
}


/**
 * @brief 
 * void ArrayADT::append(int element)
{
    // if the array has space, insert the element and increase the size
    if (this->size < this->capacity)
    {
        this->arr[this->size++] = element;
        return;
    }

    // increase the current capacity
    this->capacity *= RESIZING_FACTOR;

    // allocate a new array to hold the elements and set its elements to 0
    int *NewArray = new int[this->capacity]{0};

    // copy the element of the current array into the new array
    memcpy(NewArray, this->arr, this->size * sizeof(int));

    // deallocate the memory occupied by the current array
    delete[] this->arr;

    // make the pointer to the current array point to the new array
    this->arr = NewArray;

    // insert the element and increase the size
    this->arr[this->size++] = element;
}

 * 
 */