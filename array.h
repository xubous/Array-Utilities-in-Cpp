#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdio>

class Cell
{
public:
    int value;
    Cell * next;
    Cell * previous;

    Cell ( );
    Cell ( int value );
    ~Cell ( );
};

class Array
{
private:
    int lenght;
    int capacity;
    Cell * head;
    Cell * last;

public:
    Array ( );
    ~Array ( );
    
    int addAllValues ( );
    int reset ( );
    int alloc ( int size );
    int realloc ( int size );
    void modifyCapacity ( int size );
    void addNewCell ( int value );
    int removeCell ( );
    int removeCell ( int position );
    void print ( );
    int freeArray ( );
};

#endif
