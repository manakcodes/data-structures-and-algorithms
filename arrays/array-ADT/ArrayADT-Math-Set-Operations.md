# Set Operations On Array ADT

## union, intersection, set difference, set membership

### `union` oOf Two Unsorted Arrays

```cpp
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
        UnionArray->append(A->GetElement(i));
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
            UnionArray->append(element);
        }
    }

    // return the UnionArray
    return UnionArray;
}
```

---

``cpp

```

---
``cpp

```

---

``cpp

```

---
``cpp

```

---

``cpp

```

---
``cpp

```

---

``cpp

```

---
``cpp

```

---

``cpp

```

---
```
