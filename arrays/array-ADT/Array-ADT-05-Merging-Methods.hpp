#include "Array-ADT-00-Class.hpp"
#pragma once

ArrayADT *ArrayADT::MergeArrays(ArrayADT *A, ArrayADT *B)
{
    int a_size = A->GetSize();
    int b_size = B->GetSize();

    if (a_size == 0 && b_size == 0)
    {
        return new ArrayADT(nullptr, 0);
    }

    int *merged = new int[a_size + b_size]{0};

    int k = 0;

    for (int i = 0; i < a_size; i++)
    {
        merged[k++] = A->GetElement(i);
    }

    for (int i = 0; i < b_size; i++)
    {
        merged[k++] = B->GetElement(i);
    }

    return new ArrayADT(merged, k);
}

ArrayADT *ArrayADT::MergeSortedArrays(ArrayADT *A, ArrayADT *B)
{

    int a_size = A->GetSize();
    int b_size = B->GetSize();

    if (a_size == 0 && b_size == 0)
    {
        return new ArrayADT(nullptr, 0);
    }

    int *merged = new int[a_size + b_size]{0};

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < a_size && j < b_size)
    {
        if (A->GetElement(i) < B->GetElement(j))
        {
            merged[k++] = A->GetElement(i);
            i++;
        }

        else
        {
            merged[k++] = B->GetElement(j);
            j++;
        }
    }

    while (i < a_size)
    {
        merged[k++] = A->GetElement(i++);
        i++;
    }

    while (j < b_size)
    {
        merged[k++] = B->GetElement(j++);
    }

    return new ArrayADT(merged, k);
}