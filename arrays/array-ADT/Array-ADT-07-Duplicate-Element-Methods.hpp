#include "Array-ADT-00-Class.hpp"
#pragma once

// ========================================================================== //
// Print Duplicate Elements
// ========================================================================== //

void ArrayADT::PrintDuplicatesBruteForce()
{
    for (int i = 0; i < this->size - 1; i++)
    {
        bool AlreadyPrinted = false;

        for (int k = 0; k < i; k++)
        {
            if (this->arr[i] == this->arr[k])
            {
                AlreadyPrinted = true;
                break;
            }
        }

        if (AlreadyPrinted)
        {
            continue;
        }

        for (int j = i + 1; j < this->size; j++)
        {
            if (this->arr[i] == this->arr[j])
            {
                cout << BLUE << "duplicate -> " << this->arr[i] << RESET << endl;
                break;
            }
        }
    }
}

void ArrayADT::PrintDuplicatesInSortedArray()
{
    // bool var to store if the array is sorted or not
    bool is_asc = this->IsSortedInAscendingOrder();
    bool is_desc = this->IsSortedInDescendingOrder();

    // CASE : the array is not sorted in either order, the array should be sorted
    // either in asc order or desc order, otherwise print a message and exit
    // the method
    if (!(is_asc || is_desc))
    {
        string error_message = "WARNING !!\nexit from method -> ArrayADT *ArrayADT::PrintDuplicatesCountInSortedArray()\nboth the arrays should either be in ascending order or descending order\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET;
        exit(SORTED_DIFFERENTLY);
    }

    int LastDuplicate = INFINITY;

    for (int i = 0; i < this->size - 1; i++)
    {
        if (this->arr[i] == this->arr[i + 1] && LastDuplicate != this->arr[i])
        {
            LastDuplicate = this->arr[i];
            cout << BLUE << "duplicate -> " << this->arr[i] << RESET << endl;
        }
    }
}

void ArrayADT::PrintDuplicatesInUnsortedArray()
{
    for (int i = 0; i < this->size - 1; i++)
    {
        bool AlreadyPrinted = false;

        for (int k = 0; k < i; k++)
        {
            if (this->arr[i] == this->arr[k])
            {
                AlreadyPrinted = true;
                break;
            }
        }

        if (AlreadyPrinted)
        {
            continue;
        }

        for (int j = i + 1; j < this->size; j++)
        {
            if (this->arr[i] == this->arr[j])
            {
                cout << BLUE << "duplicate -> " << this->arr[i] << RESET << endl;
                break;
            }
        }
    }
}

void ArrayADT::PrintDuplicatesUsingHashingArray()
{
    int max_element = this->GetMax();
    int min_element = this->GetMin();
    int hash_size = max_element - min_element + 1;

    int *HASH_ARRAY = new int[hash_size]{0};

    for (int i = 0; i < this->size; i++)
    {
        HASH_ARRAY[this->arr[i] - min_element]++;
    }

    for (int i = 0; i < hash_size; i++)
    {
        if (HASH_ARRAY[i] > 1)
        {
            cout << BLUE << "duplicate -> " << i + min_element << RESET << endl;
        }
    }

    delete[] HASH_ARRAY;
}

// count

// ========================================================================== //
// Print Duplicates And Their Frequencies
// ========================================================================== //

void ArrayADT::PrintDuplicateCountBruteForce()
{
    for (int i = 0; i < this->size - 1; i++)
    {
        bool IsCounted = false;

        for (int k = 0; k < i; k++)
        {
            if (this->arr[k] == this->arr[i])
            {
                IsCounted = true;
                break;
            }
        }

        if (IsCounted)
        {
            continue;
        }

        int count = 1;

        for (int j = i + 1; j < this->size; j++)
        {
            if (this->arr[i] == this->arr[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            cout << BLUE << "duplicate -> " << this->arr[i] << " occurrence -> " << count << RESET << endl;
        }
    }
}

void ArrayADT::PrintDuplicatesCountInSortedArray()
{
    // bool var to store if the array is sorted or not
    bool is_asc = this->IsSortedInAscendingOrder();
    bool is_desc = this->IsSortedInDescendingOrder();

    // CASE : the array is not sorted in either order, the array should be sorted
    // either in asc order or desc order, otherwise print a message and exit
    // the method
    if (!(is_asc || is_desc))
    {
        string error_message = "WARNING !!\nexit from method -> ArrayADT *ArrayADT::PrintDuplicatesCountInSortedArray()\nboth the arrays should either be in ascending order or descending order\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET;
        exit(SORTED_DIFFERENTLY);
    }

    // pointer to keep track of duplicates
    int j = 0;

    // loop to check for adjacent duplicates
    for (int i = 0; i < this->size - 1; i++)
    {
        // CASE : adjacent duplicates found
        if (this->arr[i] == this->arr[i + 1])
        {
            // move the pointer which tracks duplicates by 1
            j = i + 1;

            // loop to keep incrementing the pointer which keeps the track of
            // duplicates till more duplicates are found, as the array is sorted
            // no matter if its sorted in asc order or desc order
            while (this->arr[i] == this->arr[j])
            {
                // increment the pointer which keeps tracks if duplicates by 1
                j++;
            }

            // print the duplicate element and its frequency
            cout << BLUE << "duplicate found -> " << this->arr[i] << " occurrences : " << j - i << RESET << endl;

            // make the current i pointer point just one before the pointer which
            // keeps track of duplicate elements, as the loop will increment
            // the current array pointer, in the next iteration
            i = j - 1;
        }
    }
}

void ArrayADT::PrintDuplicatesCountInUnsortedArray()
{
    for (int i = 0; i < this->size - 1; i++)
    {
        int exists = false;

        for (int k = 0; k < i; k++)
        {
            if (this->arr[i] == this->arr[k])
            {
                exists = true;
                break;
            }
        }

        if (exists)
        {
            continue;
        }

        int count = 1;

        for (int j = i + 1; j < this->size; j++)
        {
            if (this->arr[i] == this->arr[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            cout << BLUE << "duplicate -> " << this->arr[i] << " occurrence : " << count << RESET << endl;
        }
    }
}

void ArrayADT::PrintDuplicateCountUsingHashingArray()
{
    int max_element = this->GetMax();
    int min_element = this->GetMin();
    int hash_size = max_element - min_element + 1;

    int *HASH_ARRAY = new int[hash_size]{0};

    for (int i = 0; i < this->size; i++)
    {
        HASH_ARRAY[this->arr[i] - min_element]++;
    }

    for (int i = 0; i < hash_size; i++)
    {
        if (HASH_ARRAY[i] > 1)
        {
            cout << BLUE << "duplicate -> " << i + min_element << " occurs " << HASH_ARRAY[i] << " times" << RESET << endl;
        }
    }

    delete[] HASH_ARRAY;
}

// ========================================================================== //
// Remove Duplicates From Array                                               //
// ========================================================================== //

void ArrayADT::RemoveDuplicatesBruteForce()
{
    int index = 0;
    int j = 0;

    for (int i = 0; i < this->size - 1; i++)
    {
        for (j = i + 1; j < this->size; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < this->size - 1; k++)
                {
                    this->arr[k] = this->arr[k + 1];
                }
                this->size--;
                j--;
            }
        }
    }

    if (this->size < this->capacity / 4 && this->capacity > DEFAULT_CAPACITY)
    {
        this->capacity = DEFAULT_CAPACITY;
        int *NewArray = new int[this->capacity]{0};
        copy(this->arr, this->arr + this->size, NewArray);
        delete[] this->arr;
        this->arr = NewArray;
    }
}


void ArrayADT::RemoveDuplicatesInSortedArray()
{
    // bool var to store if the array is sorted or not
    bool is_asc = this->IsSortedInAscendingOrder();
    bool is_desc = this->IsSortedInDescendingOrder();

    // CASE : the array is not sorted in either order, the array should be sorted
    // either in asc order or desc order, otherwise print a message and exit
    // the method
    if (!(is_asc || is_desc))
    {
        string error_message = "WARNING !!\nexit from method -> ArrayADT *ArrayADT::PrintDuplicatesCountInSortedArray()\nboth the arrays should either be in ascending order or descending order\n";
        cerr << BOLD << UNDERLINE<<RED << error_message << RESET;
        exit(SORTED_DIFFERENTLY);
    }

    for (int i = 1; i < this->size; i++)
    {
        if (this->arr[0] || this->arr[i - 1] != this->arr[i + 1])
        {
            this->PushBack(this->arr[i]);
        }
    }
}