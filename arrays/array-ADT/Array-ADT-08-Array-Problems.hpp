#include "Array-ADT-00-Class.hpp"
#pragma once

void PrintMissingElements(ArrayADT *A)
{
    int size = A->GetSize();
    int low = A->GetElement(0);
    int high = A->GetElement(size - 1);
    int difference = low;

    for (int i = 0; i < size; i++)
    {
        int element = A->GetElement(i);
        if (element - i != difference)
        {
            cout << GREEN << "missing : " << element + i << endl
                 << RESET;
        }

        difference = element - i;
    }
}

void ArrayADT::SortIntegers()
{
    int left = 0;
    int right = this->size - 1;

    while (left < right)
    {

        while (this->arr[left] < 0)
        {
            left++;
        }

        while (this->arr[right] >= 0)
        {
            right--;
        }

        if (left < right)
        {
            swap(this->arr[left], this->arr[right]);
        }
    }
}