#include "Array-ADT-00-Class.hpp"
#pragma once

ArrayADT *ArrayADT::ReverseArrayUsingAuxiliaryArray()
{
    ArrayADT *auxiliary_arr = new ArrayADT(this->size);

    // copy the elements of the current array into the auxiliary array in the
    // reverse order

    int index = 0;
    for (int i = this->size - 1; i >= 0; i--)
    {
        auxiliary_arr->InsertByIndex(index++, this->arr[i]);
    }

    // return the reverse array
    return auxiliary_arr;
}

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

