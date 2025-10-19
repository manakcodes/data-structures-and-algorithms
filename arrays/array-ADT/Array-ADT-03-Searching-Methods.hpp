#include "Array-ADT-00-Class.hpp"
#pragma once

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

ArrayADT ArrayADT::LinearSearchAllOccurrences(int key)
{
    ArrayADT indexes = ArrayADT();

    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] == key)
        {
            indexes.PushBack(i);
        }
    }

    return indexes;
}

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

int ArrayADT::BinarySearchIterative(int key)
{
    int low = 0;
    int high = this->size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (this->arr[mid] == key)
        {
            return mid;
        }

        if (this->arr[mid] > key)
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int ArrayADT::BinarySearchRecursive(int low, int high, int key)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (this->arr[mid] == key)
    {
        return mid;
    }

    if (this->arr[mid] > key)
    {
        return this->BinarySearchRecursive(low, mid - 1, key);
    }

    else
    {
        return this->BinarySearchRecursive(mid + 1, high, key);
    }
}
