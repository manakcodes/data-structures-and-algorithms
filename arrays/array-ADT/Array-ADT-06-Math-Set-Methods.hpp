#include "Array-ADT-00-Class.hpp"
#pragma once

// Time Complexity : O(m + m * n) = O(m * n) = O(n²)

/**
 * @brief `INPUTS` two `POINTERS` to `ArrayADT` objects and perfroms
 * `set UNION` on arrays of the `POINTER` to object passed to it and `RETURNS`
 * a `POINTER` to an object of type `ArrayADT`
 *
 * `ALGORITHM` :
 * INPUT 2 pointe
 *
 * @param A `POINTER` to object of type `ArrayADT` (datatype : `ArrayADT *`)
 * @param B `POINTER` to object of type `ArrayADT` (datatype : `ArrayADT *`)
 * @return `ArrayADT*` `POINTER` to an object of type `ArrayADT`
 * (datatype : `ArrayADT *`)
 */
ArrayADT *ArrayADT::SetUnionUnsortedArrays(ArrayADT *A, ArrayADT *B)
{
    // size of the first array
    int a_size = A->GetSize();

    // size of the second array
    int b_size = B->GetSize();

    // pointer to ArrayADT object to store the union of both the arrays
    ArrayADT *UnionArray = new ArrayADT();

    // copy the first array completely into the UnionArray
    for (int i = 0; i < a_size; i++)
    {
        UnionArray->PushBack(A->GetElement(i));
    }

    // from the second array copy only that elements into the UnionArray which
    // are already not in the UnionArray previously (use linear search to check)

    // loop to copy elements from second array into the UnionArray
    for (int i = 0; i < b_size; i++)
    {
        // var to store the i-th element of the second array
        int element = B->GetElement(i);

        // boolean flag to keep track if the element exists in UnionArray or not
        bool ElementExists = false;

        // linear search to check if the element is present in the UnionArray,
        // or not, if its present in the UnionArray do not copy it, otherwise
        //  copy it in the UnionArray

        // linear search loop
        for (int j = 0; j < UnionArray->GetSize(); j++)
        {
            // CASE : if the element is present in the UnionArray make the
            // boolean flag true and exit from the loop
            if (element == UnionArray->GetElement(j))
            {
                // make the boolean flag true to mark that the element is found in the
                // UnionArray
                ElementExists = true;

                // break out of the loop
                break;
            }
        }

        // CASE : if element does not exists in the UnionArray, insert it in the
        // UnionArray
        if (!ElementExists)
        {
            UnionArray->PushBack(element);
        }
    }

    // return the UnionArray
    return UnionArray;
}

// Time Complexity : O(m + n) = O(n + n) = O(2n) = O(n)
ArrayADT *ArrayADT::SetUnionSortedArrays(ArrayADT *A, ArrayADT *B)
{
    // bool var to store if both the arrays are sorted in asc order or not
    bool a_asc = A->IsSortedInAscendingOrder();
    bool b_asc = B->IsSortedInAscendingOrder();

    // bool var to store if both the arrays are in desc order or not
    bool a_desc = A->IsSortedInDescendingOrder();
    bool b_desc = B->IsSortedInDescendingOrder();

    // CASE : check if both the arrays should be either in asc order or in
    // desc order, if not print a message, and exit the method
    if (!((a_asc && b_asc) || (a_desc && b_desc)))
    {
        string error_message = "WARNING !!\nexit from method -> ArrayADT *ArrayADT::SetUnionSortedArrays(ArrayADT *A, ArrayADT *B)\nboth the arrays should either be in ascending order or descending order\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET;
        exit(SORTED_DIFFERENTLY);
        return new ArrayADT(nullptr, 0);
    }

    // store the sizes of both the arrays
    int a_size = A->GetSize();
    int b_size = B->GetSize();

    // pointer to ArrayADT object to store the union of both the arrays
    ArrayADT *UnionArray = new ArrayADT();

    // pointer to keep the track of the index of the first array
    int i = 0;

    // pointer to keep the track of the index of the second array
    int j = 0;

    // CASE : both the arrays are sorted in the ascending order
    if (a_asc && b_asc)
    {
        // loop to copy the elements of the first array and second array into
        // UnionArray
        while (i < a_size && j < b_size)
        {
            // store the current element of both the arrays
            int element_a = A->GetElement(i);
            int element_b = B->GetElement(j);

            // CASE : if the element of the first array is greater the element of
            // of second array, then add the smaller element to the UnionArray
            //  and increment thd pointer of first array by 1
            if (element_a < element_b)
            {
                UnionArray->PushBack(element_a);
                i++;
            }

            // CASE : if the element of the first array is greater than the element
            // of second array, then add the smaller element in the UnionArray
            // and increment the pointer of the second array by 1;
            else if (element_a > element_b)
            {
                UnionArray->PushBack(element_b);
                j++;
            }

            // CASE : the element is present in the both arrays (i.e in the first
            // array and in the second array), add the element to the UnionArray and
            // increment the pointers (i, j) of both arrays by 1
            else
            {
                UnionArray->PushBack(element_a);
                i++;
                j++;
            }
        }

        // copy the remaining elements from the first array into the UnionArray
        //  (if left any)
        while (i < a_size)
        {
            UnionArray->PushBack(A->GetElement(i++));
        }

        // copy the remaining elements from the second array into the UnionArray
        // (if left any)
        while (j < b_size)
        {
            UnionArray->PushBack(B->GetElement(j++));
        }
    }

    // CASE : both the arrays are sorted in descending order
    if (a_desc && b_desc)
    {
        while (i < a_size && j < b_size)
        {
            int element_a = A->GetElement(i);
            int element_b = B->GetElement(j);

            if (element_a > element_b)
            {
                UnionArray->PushBack(element_a);
                i++;
            }
            else if (element_a < element_b)
            {
                UnionArray->PushBack(element_b);
                j++;
            }
            else
            {
                UnionArray->PushBack(element_a);
                i++;
                j++;
            }
        }

        while (i < a_size)
        {
            UnionArray->PushBack(A->GetElement(i++));
        }
        while (j < b_size)
        {
            UnionArray->PushBack(B->GetElement(j++));
        }
    }

    // return the pointer to object of UnionArray
    return UnionArray;
}

// Time Complexity : O(m * n) = O(n * n) = O(n²)
ArrayADT *ArrayADT::SetIntersectionUnsortedArrays(ArrayADT *A, ArrayADT *B)
{
    // pointer to ArrayADT object to hold the intersection of both the arrays
    ArrayADT *IntersectionArray = new ArrayADT();

    int a_size = A->GetSize();
    int b_size = B->GetSize();

    // loop to copy the elements of the first array into the IntersectionArray
    for (int i = 0; i < a_size; i++)
    {
        int element = A->GetElement(i);

        // boolean flag to keep the track if the elements exists in the second
        // array or not
        int exists = false;

        // loop of linear search

        // linear search to check if the element is present in the second array
        // or not
        for (int j = 0; j < b_size; j++)
        {
            // CASE : element is present in the second array, make the boolean
            // flag = true and exit the loop
            if (element == B->GetElement(j))
            {
                //  make the boolean flag true
                exists = true;

                // exit the loop
                break;
            }
        }

        // if element is present in the second array, then add it to the
        // IntersectionArray
        if (exists)
        {
            IntersectionArray->PushBack(element);
        }
    }

    // return the pointer to the ArrayADT object which contains the Intersection
    // of two arrays
    return IntersectionArray;
}

// Time Complexity : O(m + n) = O(n + n) = O(n)
ArrayADT *ArrayADT::SetIntersectionSortedArrays(ArrayADT *A, ArrayADT *B)
{

    bool a_asc = A->IsSortedInAscendingOrder();
    bool b_asc = B->IsSortedInAscendingOrder();

    bool a_desc = A->IsSortedInDescendingOrder();
    bool b_desc = B->IsSortedInDescendingOrder();

    if (!((a_asc && b_asc) || (a_desc && b_desc)))
    {
        return new ArrayADT(nullptr, 0);
    }

    ArrayADT *IntersectionArray = new ArrayADT();

    int a_size = A->GetSize();
    int b_size = B->GetSize();

    int i = 0;
    int j = 0;

    if (a_asc && b_asc)
    {
        while (i < a_size && j < b_size)
        {

            int element_a = A->GetElement(i);
            int element_b = B->GetElement(j);

            if (element_a == element_b)
            {
                IntersectionArray->PushBack(element_a);
                i++;
                j++;
            }

            else if (element_a < element_b)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }

    else
    {
        while (i < a_size && j < b_size)
        {

            int element_a = A->GetElement(i);
            int element_b = B->GetElement(j);

            if (element_a == element_b)
            {
                IntersectionArray->PushBack(element_a);
                i++;
                j++;
            }

            else if (element_a > element_b)
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
    return IntersectionArray;
}
// O(n²)
ArrayADT *ArrayADT::SetDifferenceUnsortedArrays(ArrayADT *A, ArrayADT *B)
{

    int a_size = A->GetSize();
    int b_size = B->GetSize();

    ArrayADT *difference = new ArrayADT();

    for (int i = 0; i < a_size; i++)
    {
        int element = A->GetElement(i);
        bool exists = false;

        for (int j = 0; j < b_size; j++)
        {
            if (element == B->GetElement(j))
            {
                exists = true;
                break;
            }
        }

        if (!exists)
        {
            difference->PushBack(element);
        }
    }

    return difference;
}

ArrayADT *ArrayADT::SetDifferenceSortedArrays(ArrayADT *A, ArrayADT *B)
{

    bool a_asc = A->IsSortedInAscendingOrder();
    bool b_asc = B->IsSortedInAscendingOrder();

    bool a_desc = A->IsSortedInDescendingOrder();
    bool b_desc = B->IsSortedInDescendingOrder();

    if (!((a_asc && b_asc) || (a_desc && b_desc)))
    {
        return new ArrayADT(nullptr, 0);
    }

    int a_size = A->GetSize();
    int b_size = B->GetSize();

    ArrayADT *difference = new ArrayADT();

    int i = 0;
    int j = 0;

    if (a_asc && b_asc)
    {
        while (i < a_size && j < b_size)
        {
            int element_a = A->GetElement(i);
            int element_b = B->GetElement(j);

            if (element_a < element_b)
            {
                difference->PushBack(element_a);
                i++;
            }

            else if (element_a > element_b)
            {
                j++;
            }

            else
            {
                i++;
                j++;
            }
        }

        while (i < a_size)
        {
            difference->PushBack(A->GetElement(i++));
        }
    }

    else
    {
        while (i < a_size && j < b_size)
        {
            int element_a = A->GetElement(i);
            int element_b = B->GetElement(j);

            if (element_a > element_b)
            {
                difference->PushBack(element_a);
                i++;
            }

            else if (element_a < element_b)
            {
                j++;
            }

            else
            {
                i++;
                j++;
            }
        }

        while (i < a_size)
        {
            difference->PushBack(A->GetElement(i++));
        }
    }

    return difference;
}

bool ArrayADT::SetMembership(ArrayADT *A, int element)
{
    int size = A->GetSize();

    for (int i = 0; i < size; i++)
    {
        if (A->GetElement(i) == element)
        {
            return true;
        }
    }

    return false;
}