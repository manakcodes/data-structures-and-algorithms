#include "Array-ADT-00-Class.hpp"
#pragma once

int ArrayADT::GetMax()
{
    // CASE : if the size of the array is 0, then print a message and exit the
    // method
    if (this->size == 0)
    {
        const char *error_message = "exit from function -> GetMax()\nEMPTY ARRAY\n(0 < array_size)\n\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET;
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
int ArrayADT::GetMin()
{
    // CASE : if the size of the array is 0, then print a message and exit the
    // method
    if (this->size == 0)
    {
        const char *error_message = "exit from method -> GetMin()\nEMPTY ARRAY\n(0 < array_size)\n\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET;
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

int ArrayADT::GetSum()
{
    // CASE : if the array is empty, then print a message and exit the method
    if (this->size == 0)
    {
        const char *error_message = "exit from method -> GetMin()\nEMPTY ARRAY\n(0 < array_size)\n\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET;
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

double ArrayADT::GetAverage()
{

    // CASE : if the array is empty, then print a message and exit the method
    if (this->size == 0)
    {
        const char *error_message = "exit from method -> GetAverage()\nEMPTY ARRAY\n(0 < array_size)\n\n";
        cerr << BOLD << UNDERLINE << RED << error_message << RESET;
        exit(EMPTY_ARRAY);
    }

    // return the average
    return (this->GetSum() / this->size);
}

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

bool ArrayADT::IsSorted()
{
    if (this->size <= 1)
    {
        return true;
    }

    return this->IsSortedInAscendingOrder() || this->IsSortedInDescendingOrder();
}

void ArrayADT::sort()
{
    if (this->size == 0)
    {
        return;
    }

    qsort(this->arr, this->size, sizeof(int), ascending_comparator);
}
bool ArrayADT::IsEqual(ArrayADT *other)
{
    int other_size = other->GetSize();

    if (this->size != other->size)
    {
        return false;
    }

    for (int i = 0; i < this->size; i++)
    {
        if (this->arr[i] != other->GetElement(i))
        {
            return false;
        }
    }

    return true;
}

void ArrayADT::PrintArray()
{
    cout << GREEN;
    cout << "[";
    for (int i = 0; i < this->size; i++)
    {

        cout  << this->arr[i];

        if (i != this->size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << RESET;
}

void ArrayADT::RandomizeArray(int MinValue, int MaxValue)
{
    if (this->size == 0)
    {
        std::cerr << "⚠️ Array is empty — cannot randomize.\n";
        return;
    }

    if (MinValue > MaxValue)
    {
        std::swap(MinValue, MaxValue);
    }

    // Initialize random number generator with a time-based seed
    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<int> dist(MinValue, MaxValue);

    // Fill the array with random values
    for (int i = 0; i < this->size; i++)
    {
        this->arr[i] = dist(rng);
    }
}