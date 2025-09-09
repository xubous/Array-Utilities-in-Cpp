#include "array.h"
#include <iostream>
#include <cstdio>

Cell::Cell ( )
{
    this -> value = 0;
    this -> next = nullptr;
    this -> previous = nullptr;
}

Cell::Cell ( int value )
{
    this -> value = value;
    this -> next = nullptr;
    this -> previous = nullptr;
}

Cell:: ~ Cell ( ) { }

Array::Array ( )
{
    head = new Cell ( - 1 );
    last = head;
    this -> capacity = 10;
    this -> lenght = 0;
}

Array:: ~ Array ( ) 
{
    freeArray ( );
}

int Array::addAllValues ( )
{
    if ( head != nullptr )
    {
        Cell * current = head;
        int i = 0;

        while ( current != nullptr )
        {
            current -> value = i ++;
            current = current -> next;
        }

        return 0;
    } else
        {
            std::cout << "Error To Add ALl Values" << '\n';
            return 1;
        }
}

int Array::reset ( )
{
    if ( head != nullptr )
    {
        this -> freeArray ( );
        this -> head = new Cell ( - 1 );
        this -> last = head;
        this -> capacity = 10;
        this -> lenght = 0;

        return 0;
    } else
        {
            std::cout << "Error To Reset Array !" << '\n';
            return 1;
        }
}

int Array::alloc ( int size )
{
    if ( head != nullptr && size <= this -> capacity )
    {
        for ( int i = 0; i < size; i ++ )
        {
            this -> addNewCell ( 0 );
        }

        return 0;
    } else
        {
            std::cout << "Error To Alloc" << '\n';

            return 1;
        }
}

int Array::realloc ( int size )
{
    if ( head != nullptr && size > this -> capacity )
    {
        this -> modifyCapacity ( size );

        for ( int i = this -> lenght; i < this -> capacity; i ++ )
        {
            this -> addNewCell ( 0 );
        }

        return 0;
    } else
        {
            std::cout << "Error To Realloc" << '\n';

            return 1;
        }
}

void Array::modifyCapacity ( int size )
{
    if ( size > 0 )
    {
        this -> capacity = size;
        std::cout << '\n' << "Size Modified For : " << size << '\n';
        std::cout << '\n';
    } else
        {
            std::cout << '\n' << "Invalid Size !" << '\n';
        }
}

void Array::addNewCell ( int value )
{
     if ( head != nullptr && this -> lenght < this -> capacity )
    {
        Cell * cell = new Cell ( value );

        cell -> previous = last;
        last -> next = cell;
        last = cell;

        std::cout << "Added In Index : " << this -> lenght << " Value : " << value << '\n';
        this -> lenght = this -> lenght + 1;
        // std::cout << "Lenght = " << this -> lenght << ' ';
    } else
        {
            std::cout << '\n' << "Error To Add The New Cell With Value [ " << value << " ] " << '\n';
            std::cout << "The Lenght Is Bigger Than The Capacity ! " << '\n';
            std::cout << "Lenght -> " << this -> lenght << '\n';
            std::cout << "Capacity -> " << this -> capacity << '\n';
        }
}

void Array::print ( )
{
    if ( head != nullptr )
    {
        std::cout << '\n';
        Cell * current = head -> next;

        while ( current != nullptr )
        {                    
            std::cout << current -> value << ' ';
            current = current -> next;
        }

        std::cout << '\n';
    }
}

int Array::freeArray ( )
{
    if ( head != nullptr )
    {
        Cell * current = head;

        while ( current != nullptr )
        {
            Cell * next = current -> next;
            delete ( current );
            current = next;
        }

        head = nullptr;
        last = nullptr;
        this -> lenght = 0;

        return 0;
    } else
        {
            return - 1;
        }
}

// class Cell
// {
//     public :
//         int value;
//         Cell * next;
//         Cell * previous;

//         Cell ( )
//         {
//             this -> value = 0;
//             this -> next = nullptr;
//             this -> previous = nullptr;
//         }

//         Cell ( int value )
//         {
//             this -> value = value;
//             this -> next = nullptr;
//             this -> previous = nullptr;
//         }

//         ~ Cell ( ) { } 
// };

// class Array 
// {
//     private :
//         int lenght = 0;
//         int capacity = 0;

//     public :
//         Cell * head;
//         Cell * last;

//         Array ( )
//         {
//             head = new Cell ( - 1 );
//             last = head;
//             this -> capacity = 10;
//             this -> lenght = 0;
//         }

//         ~ Array ( )
//         {
//             freeArray ( );
//         }

//         int addAllValues ( )
//         {
//             if ( head != nullptr )
//             {
//                 Cell * current = head;
//                 int i = 0;

//                 while ( current != nullptr )
//                 {
//                     current -> value = i ++;
//                     current = current -> next;
//                 }

//                 return 0;
//             } else
//                 {
//                     std::cout << "Error To Add ALl Values" << '\n';
//                     return 1;
//                 }
//         }

//         int reset ( )
//         {
//             if ( head != nullptr )
//             {
//                 this -> freeArray ( );
//                 this -> head = new Cell ( - 1 );
//                 this -> last = head;
//                 this -> capacity = 10;
//                 this -> lenght = 0;

//                 return 0;
//             } else
//                 {
//                     std::cout << "Error To Reset Array !" << '\n';
//                     return 1;
//                 }
//         }

//         int alloc ( int size )
//         {
//             if ( head != nullptr && size <= this -> capacity )
//             {
//                 for ( int i = 0; i < size; i ++ )
//                 {
//                     this -> addNewCell ( 0 );
//                 }

//                 return 0;
//             } else
//                 {
//                     std::cout << "Error To Alloc" << '\n';

//                     return 1;
//                 }
//         }

//         int realloc ( int size )
//         {
//             if ( head != nullptr && size > this -> capacity )
//             {
//                 this -> modifyCapacity ( size );

//                 for ( int i = this -> lenght; i < this -> capacity; i ++ )
//                 {
//                     this -> addNewCell ( 0 );
//                 }

//                 return 0;
//             } else
//                 {
//                     std::cout << "Error To Realloc" << '\n';

//                     return 1;
//                 }
//         }

//         void modifyCapacity ( int size )
//         {
//             if ( size > 0 )
//             {
//                 this -> capacity = size;
//                 std::cout << '\n' << "Size Modified For : " << size << '\n';
//                 std::cout << '\n';
//             } else
//                 {
//                     std::cout << '\n' << "Invalid Size !" << '\n';
//                 }
//         }
    
//         void addNewCell ( int value )
//         {
//             if ( head != nullptr && this -> lenght < this -> capacity )
//             {
//                 Cell * cell = new Cell ( value );

//                 cell -> previous = last;
//                 last -> next = cell;
//                 last = cell;

//                 std::cout << "Added In Index : " << this -> lenght << " Value : " << value << '\n';
//                 this -> lenght = this -> lenght + 1;
//                 // std::cout << "Lenght = " << this -> lenght << ' ';
//             } else
//                 {
//                     std::cout << '\n' << "Error To Add The New Cell With Value [ " << value << " ] " << '\n';
//                     std::cout << "The Lenght Is Bigger Than The Capacity ! " << '\n';
//                     std::cout << "Lenght -> " << this -> lenght << '\n';
//                     std::cout << "Capacity -> " << this -> capacity << '\n';
//                 }
//         }

//         void print ( )
//         {
//             if ( head != nullptr )
//             {
//                 std::cout << '\n';
//                 Cell * current = head -> next;

//                 while ( current != nullptr )
//                 {                    
//                     std::cout << current -> value << ' ';
//                     current = current -> next;
//                 }

//                 std::cout << '\n';
//             }
//         }

//         int freeArray ( )
//         {
//             if ( head != nullptr )
//             {
//                 Cell * current = head;

//                 while ( current != nullptr )
//                 {
//                     Cell * next = current -> next;
//                     delete ( current );
//                     current = next;
//                 }

//                 head = nullptr;
//                 last = nullptr;
//                 this -> lenght = 0;

//                 return 0;
//             } else
//                 {
//                     return - 1;
//                 }
//         }
// };

// int main ( )
// {
    // Array * array = new Array ( );

    // for ( int i = 0; i <= 10; i ++ )
    // {
    //     array -> addNewCell ( i );
    // }

    // array -> print ( );

    // array -> modifyCapacity ( 11 );
    // array -> addNewCell ( 10 );
    // array -> print ( );
    // array -> addNewCell ( 11 );

    // int resetArrayFunction = array -> reset ( );

    // std::cout << '\n' << "Return Method Array Reset : " << resetArrayFunction << '\n' << '\n';

    // int allocArrayMethod = array -> alloc ( 10 );

    // std::cout << '\n' << "Return Method Array Alloc : " << allocArrayMethod << '\n';
    
    // int addAllValuesArrayMethod = array -> addAllValues ( );

    // std::cout << '\n' << "Return Method Add All Values : " << addAllValuesArrayMethod << '\n';

    // array -> print ( );
    // array -> addNewCell ( 11 );

    // int reallocArrayMethodArray = array -> realloc ( 20 );

    // std::cout << '\n' << "Return Method Array Realloc : " << reallocArrayMethodArray << '\n';
    // array -> print ( );
    // addAllValuesArrayMethod =array -> addAllValues ( );
    // array -> print ( );

    // int freeArrayReturn = array -> freeArray ( );

    // std::cout << '\n' << "Return Method Array Free : " << freeArrayReturn << '\n';

    // delete array;

    // return 0;
// }