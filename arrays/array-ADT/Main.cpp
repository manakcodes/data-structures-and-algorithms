#include "ArrayADT.hpp"

int main()
{

    // int ArrayOne[] = {-9, -9, -9, -9, -9, -9, -9, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 5,-9,-9};
    // // int ArrayTwo[] = {};

    // int SizeOne = sizeof(ArrayOne) / sizeof(ArrayOne[0]);
    // // int SizeTwo = sizeof(ArrayTwo) / sizeof(ArrayTwo[0]);

    // ArrayADT arr1 = ArrayADT(ArrayOne, SizeOne);
    // // ArrayADT arr2 = ArrayADT(ArrayTwo, SizeTwo);

    // // arr1.PrintArray();
    // // arr2.PrintArray();

    // arr1.PrintDuplicatesCountInUnsortedArray();
    // // ArrayADT::SetUnionSortedArrays(&arr1, &arr2)->PrintArray();

    // cout << endl
    //      << endl;

    // ============================

    ArrayADT *arr = new ArrayADT();

    //arr->PopFront();

    for (int i = 0; i < 5; i++)

    {
        arr->PushBack(i + 1);
    }

    arr->PrintArray();

    for (int i = 0; i < 6; i++)
    {
        arr->PopBack();
        arr->PrintArray();
    }

    return 0;
}