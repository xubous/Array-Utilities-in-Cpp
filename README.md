# Array-Utilities-C++
A C++ library implementing a dynamic array using a doubly-linked list structure. This implementation provides efficient memory management and various utility operations.
Array Utilities in C++

A C++ library implementing a dynamic array using a doubly-linked list structure. This implementation provides efficient memory management and various utility operations.
Features

    Dynamic memory allocation and reallocation

    Bidirectional traversal (forward and backward)

    Efficient insertion and deletion operations

    Memory management utilities

    Statistical calculations

API Reference / Core Methods :

    addAllValues() - Sums all values in the array

    reset() - Clears the array

    alloc(int size) - Allocates initial memory

    realloc(int size) - Resizes the array

    modifyCapacity(int size) - Changes array capacity

    addNewCell(int value) - Adds a new element

    print() - Displays array contents

    freeArray() - Releases allocated memory
    
Compilation : g++ -std=c++11 main.cpp array.cpp -o array_program
