#include <iostream>
#include <random>
#include <ctime>

#pragma once
using namespace std;

const char *RESET = "\033[0m";
const char *BOLD = "\033[1m";
const char *UNDERLINE = "\033[4m";
const char *RED = "\033[31m";
const char *GREEN = "\033[32m";
const char *BLUE = "\033[34m";

const int DEFAULT_CAPACITY = 5;
const int GROWTH_FACTOR = 2;
const int SHRINKING_FACTOR = 4;
const int INVALID_INDEX = -1001;
const int EMPTY_ARRAY = -1002;
const int SORTED_DIFFERENTLY = -1003;

int ascending_comparator(const void *x, const void *y)
{
    const int a = *(const int *)(x);
    const int b = *(const int *)(y);

    return a - b;
}

class ArrayADT
{
private:
    int capacity;
    int size;
    int *arr;

public:
    ArrayADT();
    ArrayADT(int capacity);
    ArrayADT(int *arr, int size);
    ArrayADT(const ArrayADT &other);
    ~ArrayADT();

    inline const int GetSize();
    inline const int GetCapacity();

    int GetElement(int index);
    void SetElement(int index, int element);
    void PrintArray();

    // void append(int element);
    // void insert(int index, int element);
    // int DeleteByIndex(int index);

    // INSERTION METHODS //

    void PushFront(int element);
    void PushBack(int element);
    void InsertByIndex(int index, int element);
    void InsertInSortedArray(int element);

    // DELETION METHODS //

    int PopFront();
    int PopBack();
    int DeleteByIndex(int index);
    int DeleteByValue(int element);

    // MISCELLANEOUS METHODS //

    int GetMax();
    int GetMin();
    int GetSum();
    double GetAverage();
    bool IsSortedInAscendingOrder();
    bool IsSortedInDescendingOrder();
    bool IsSorted();

    bool IsEqual(ArrayADT *other);

    ArrayADT *ReverseArrayUsingAuxiliaryArray();
    void ReverseOriginalArray();
    void ReverseSubarray(int start, int stop);

    void LeftShiftArray(int PlaceHolder = INT_MAX);
    void RightShiftArray(int PlaceHolder = INT_MAX);

    void LeftRotateArray();
    void RightRotateArray();

    bool IsEmpty();
    bool IsFull();

    ArrayADT *slice(int start, int stop, int step);

    // searching methods
    int LinearSearchFirstOccurrence(int key);
    int LinearSearchLastOccurrence(int key);
    ArrayADT LinearSearchAllOccurrences(int key);
    int LinearSearchUsingTransposition(int key);
    int LinearSearchUsingMoveToFront(int key);

    int BinarySearchIterative(int key);
    int BinarySearchRecursive(int low, int high, int key);

    void SortIntegers();

    void RandomizeArray(int MinValue, int MaxValue);

    static ArrayADT *MergeSortedArrays(ArrayADT *A, ArrayADT *B);
    static ArrayADT *MergeArrays(ArrayADT *A, ArrayADT *B);

    static ArrayADT *SetUnionUnsortedArrays(ArrayADT *A, ArrayADT *B);
    static ArrayADT *SetUnionSortedArrays(ArrayADT *A, ArrayADT *B);
    static ArrayADT *SetIntersectionUnsortedArrays(ArrayADT *A, ArrayADT *B);
    static ArrayADT *SetIntersectionSortedArrays(ArrayADT *A, ArrayADT *B);
    static ArrayADT *SetDifferenceUnsortedArrays(ArrayADT *A, ArrayADT *B);
    static ArrayADT *SetDifferenceSortedArrays(ArrayADT *A, ArrayADT *B);
    static bool SetMembership(ArrayADT *A, int element);

    void PrintDuplicatesBruteForce();
    void PrintDuplicatesInUnsortedArray();
    void PrintDuplicatesInSortedArray();
    void PrintDuplicatesUsingHashingArray();

    void PrintDuplicateCountBruteForce();
    void PrintDuplicatesCountInSortedArray();
    void PrintDuplicatesCountInUnsortedArray();
    void PrintDuplicateCountUsingHashingArray();

    void sort();

    void RemoveDuplicatesBruteForce();
    void RemoveDuplicatesInUnsortedArray();
    void RemoveDuplicatesInSortedArray();
    void RemoveDuplicatesByHashingArray();
};

ArrayADT::ArrayADT() : capacity(DEFAULT_CAPACITY), size(0)
{
    this->arr = new int[capacity];
    memset(arr, 0, capacity);
}

ArrayADT::ArrayADT(int capacity) : capacity(capacity), size(0)
{
    this->arr = new int[capacity];
    memset(arr, 0, capacity * sizeof(int));
}

ArrayADT::ArrayADT(const ArrayADT &other) : capacity(other.capacity), size(other.size)
{
    arr = new int[capacity];
    memcpy(arr, other.arr, size * sizeof(int));
}

ArrayADT::ArrayADT(int *arr, int size)
{
    if (size < 0)
    {
        cerr << RED << "exit from constructor -> ArrayADT::ArrayADT(int *arr, int size)\nsize cannot be less than or equal to 0\n"
             << RESET;
        exit(INVALID_INDEX);
    }

    this->capacity = DEFAULT_CAPACITY < size ? size : DEFAULT_CAPACITY;
    this->arr = new int[this->capacity]{0};
    std::copy(arr, arr + size, this->arr);
    this->size = size;
}

ArrayADT::~ArrayADT()
{
    delete[] arr;
    arr = nullptr;
}

inline const int ArrayADT::GetSize()
{
    return this->size;
}

inline const int ArrayADT::GetCapacity()
{
    return this->capacity;
}

int ArrayADT::GetElement(int index)
{
    // CASE : if the user passes an INVALID index to the method, print a message
    // and exit the method
    if (index < 0 || index > size)
    {
        const char *error_msg = "exit from function -> GetElement(int index)\nINVALID INDEX\n(0 <= valid_index <= size)\n\n";

        exit(INVALID_INDEX);
    }

    // return the element present at the valid index
    return this->arr[index];
}

void ArrayADT::SetElement(int index, int element)
{
    // CASE : if the user passes an INVALID index to the method, print a message
    // and exit the method
    if (index < 0 || index >= size)
    {
        std::string error_msg = "exit from function -> SetElement(int index)\nINVALID INDEX\n(0 <= valid_index < size)\nuser passed " + to_string(index) + "\n\n";
        cerr << RED << error_msg << RESET;
        exit(INVALID_INDEX);
    }

    // set the element at the valid index of the current ArrayADT object
    this->arr[index] = element;
}
