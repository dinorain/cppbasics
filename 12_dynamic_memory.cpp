/* Dinamic Memory __________________________________________________________________________________
In the programs in previous chapters, all memory needs were determined before program execution bu defining the variabless needed. But there may be cases where the memory needed depends on user input. On these cases, programns needed
to dynamically allocate memory, for which the C++ language integrates the operators new and delete*/

#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <new>
using namespace std;

#define NEWLINE '\n'

int main () {
    // Operators new and new[] ___________________________________________________________________
    /* Dynamic memory is allocated using operator new. new is folloed by a data specifier and, if a sequence of more than one element is requred, the numbers of these within brackets []. It retujrns a pointer to the beginning og the new block of memory allocated. Its syntax is : 
    
    pointer = new type
    pointer = new type [numbers_of_elements]
    */

    int * foo; // foo is a pointer 
    foo = new int [5]; // in this case, the system dynamically allocates space for five elements of type int and returns a pointer to the first element, which is assigned to foo (a pointer). Therefore, foo now points to a valid block of memory with spcae for five elements of type int.

    /* There is a szubstantial difference declaring a normal array and alloacating dynamic memeory for a block of memorly
    using new. The most important difference is taht the size pf a regular array needs to be a constant expression, and thus its size has to be dtermined at the moment of designing then program, before it is run, whereas the dynamic memory allocarion by new allows to assign memory during runtime using any variable value as size */

    /* The dynamic memrory requested byh our program is allocated by the system from the memory heap. However, computer memory is a limited resource, and it can be exhausted. Therefore, there are no guarantees that all requests to allocate memory using operator new are going to be granted by the system. */

    /* C++ provides two standard mechanisms to check if the allocation was succesfull: 
    
    One by handling exceptions. Using this methodm an exceptiokn of type bad_alloc isz throw when the allocation fails.
    Exceptiokns are powerful C++ featur explained later in these tutorials. But for now, you shuld know that if this exception is thrown and it is not handled by a specific handler, the program execution is terminated.
    
    This exception methos is the methos used by default by new, and is the one used in declaration like 
    
    foo = new int [5] // if allocation fails, aan exception is thrown. */

    /* The other method is  known as nothrow, and what happens when it us used is that a memory allocation failsz, instead of throwing bad_alloc exception pe terminating the program, the pointer returned by new is a null pointer, 
    and the program continues its excecution normally. */

    // This method can be specified by using a special object called nothrow
    int * boo;
    boo = new (nothrow) int [5];

    // in this case, ikf allocation of this block memory fails, the failure can be detected by checking if boo is a null pointer:

    if (boo = nullptr) {
        cout << "Null "; // error assaigning memory. Take measures. 
    }

    /* This nothrow methos id likely to produce less efficient code than exceptions, sinceit implies explicitly checking the pointer value returned after aeach and every allocation. Thereforem the exception mechanism is generally preferred, at least for critical allocations. */

    // Operators delete and delete[] ____________________________________________________________
    /* In most cases, memory allocated dynamically is only needed during specific perioss of time within a program, once is is no longer needed, it can be freed so that the memory becomes available again for other requests of dynamic memory. 
    
    delete pointer; // releases the memory pf a single element allocated using new
    delete[] pointer; / releases the memory allocated for arrays of elements using new ans a size in brackets */

    // rememb-o-matic
    int i, n;
    int * p;
    cout << "How many numbers would you like to type ? ";
    cin >> i;
    p = new (nothrow) int[i];
    if (p == nullptr) {
        cout << "Error: memory could not be allocated";
    }
    else {
        for (n=0; n<i; n++) {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n=0; n<i; n++) {
            cout << p[n] << ", ";
        }
        delete[] p;
    }

    /* C++ integrates the operatore new and delete for allocating dynamic memory. But these were not available in the C langugae; instead, it used a library solution, with the functions malloc, calloc, realloc and free, defined in the
    header <cstdlib> (known as <stdlib.h) in C. These functions are also availazble in C++ and can also be used to allocate and deallocte dynamic memory, */








    return 0;
}
