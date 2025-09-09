#include "array.h"

int main ( )
{
    Array * array = new Array ( );

    for ( int i = 0; i <= 10; i ++ )
    {
        array -> addNewCell ( i );
    }

    array -> print ( );

    array -> modifyCapacity ( 11 );
    array -> addNewCell ( 10 );
    array -> print ( );
    array -> addNewCell ( 11 );

    int resetArrayFunction = array -> reset ( );

    std::cout << '\n' << "Return Method Array Reset : " << resetArrayFunction << '\n' << '\n';

    int allocArrayMethod = array -> alloc ( 10 );

    std::cout << '\n' << "Return Method Array Alloc : " << allocArrayMethod << '\n';
    
    int addAllValuesArrayMethod = array -> addAllValues ( );

    std::cout << '\n' << "Return Method Add All Values : " << addAllValuesArrayMethod << '\n';

    array -> print ( );
    array -> addNewCell ( 11 );

    int reallocArrayMethodArray = array -> realloc ( 20 );

    std::cout << '\n' << "Return Method Array Realloc : " << reallocArrayMethodArray << '\n';
    array -> print ( );
    addAllValuesArrayMethod =array -> addAllValues ( );
    array -> print ( );

    int freeArrayReturn = array -> freeArray ( );

    std::cout << '\n' << "Return Method Array Free : " << freeArrayReturn << '\n';

    delete array;

    return 0;
}