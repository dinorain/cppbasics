#include <iostream>
#include <string>
#include <sstream>
#include <array>
using namespace std;

#define NEWLINE '\n';

// pointers as arguments
void increment_all (int* start, int* stop) {
    int * current = start;
    while (current != stop) {
        ++(*current);   // increment value pointed
        ++current;      // increment pointer
    }
}

void print_all (const int* start, const int* stop) {
    int numbers[] = {10, 20, 30};
    increment_all (numbers, numbers+3);
}

// Void pointer : increaser
void increaser (void* data, int psize) {
    if (psize == sizeof(char)) {
        char* pchar; pchar=(char*)data; ++(*pchar);
    }
    else if (psize==sizeof(int)) {
        int* pint; pint=(int*)data; ++(*pint);
    }
}

// Pointers to functions
int addition (int a, int b) {
    return (a+b);
}

int substraction (int a, int b) {
    return (a-b);
}

int operation (int x, int y, int (*functioncall)(int, int)) {
    int g;
    g = (*functioncall)(x,y);
    return (g);
}

int main () {
    /*When a variable is declared, the memory needed to store its value is assigned a specific location memory 
    (its memory adress). Generally, C++ progrmas do not actively decide the exact memory adresses where its variables are stored. Fortunatley, that task is left to the environment where the program is run - generally, an operating system that decides the particular memory locations on runtime. However, it may be useful for a program to be able to obtain the address of a variable during runtime in order to access data cells that are at certain position. */

    // Address-of operator (&) --> ampersand sign_____________________________________________________________________
    // foo = &myvar;
    // This would assign the address of variable myvaar to foo; by preceeding the name of the variable myvar with the address-of operator(&), we are no longer assigning the conten of the varibale itself to foo, but its address

    // The actual address of a variable in mekmory cannot be known before runtime, but let's assume, in order to help clarify some concepts, that myvar is paced during runtime in the memory address 1776

    // In this case, colnsider the following fragment
    int myvar = 25;
    int* foo = &myvar;
    int bar = myvar;

    // The avriable that stores the address of another variable (like foo in the previous example) is what in C++ is called a pointer. Pointers are very powerful feature of the language that has amny uses in lower level programming. A bit later, we will see how to declare and use pointers

    // Dereference operator (*) _______________________________________________________________________________________
    // Pointers are said to "point to " the varibale whose address they store

    // The dereference operator itself can be reas as "value pointed to by"

    int baz = *foo; // baz equal to value pointed to by foo, will asign 25 to baz, since foo is 1776, and the value pointed to by 1776 would be 25

    int* bazi = foo; // bazi  equal to foo (1776)
    baz = *foo; // baz eaual to value pointed by foo (25), *foo == myvar 

    // An address obtained with & can be dereferenced with *

    // Declaring pointers _________________________________________________________________________________________
    /* The declaration of a pointer needs to include the data type the pointer is going to point to*/
    // type * name; 
    int firstvalue, secondvalue;
    int * mypointer;

    mypointer= &firstvalue;
    *mypointer = 10;
    mypointer = &secondvalue;
    *mypointer = 20;
    cout << "first value is " << firstvalue << endl;
    cout << "second value is " << secondvalue << endl;
    /* First, mypointer is assigned the addres of firstvalue using the address-of operator(&). Then, the value of pointed to by mypointer is assigned a value of 10. Because, at this moment, mypointer is pointing to the memory of firstvalue, this in fact the value of firstvalue.*/

    //more pointers
    int first = 5, second = 15;
    int * p1, * p2;

    p1 = &first;        // p1 = address of first
    p2 = &second;       // P2 = address of second
    *p1 = 10;           // value pointed to by p1 = 10
    *p2 = *p1;          // value pointed to by p2 = value pointed to by p1
    p1 = p2;            // p1 = p2 (value of the pointer is copied)
    *p1 = 20;           // value pointed to by p1 = 20
    
    cout << "first is " << first << endl;
    cout << "second is " << second << endl;

    // Pointers and Arrays_________________________________
    int myarray [20];
    int * mypointer1;

    mypointer1 = myarray; // this assignment operation is valid
    /* mypointer and myarray would be equivalent and would ahve very similar properties. The main differnece beign that mypointer can be assigned a diiferent address, whereas myarray can never be assigned anything, wand will always represent the same block of 20 elements of type int. Therefore, myarray = mypointer would not be valid. */

    int numbers[5];
    int * p;
    p = numbers; *p = 10;
    p++; *p = 20;
    p = &numbers[2]; *p = 30;
    p = numbers; *p = 40;
    p = numbers; *(p+4) = 50;
    for (int n =0; n<5; n++) {
        cout << numbers[n] << ",";
    }

    /* In the chapter about arrays, brackets ([]) were explained as specifying the index of an element of the array. Well, in fact these brackets are a dereferencing operator known as offset operator. They dereference the variable they follow just as * does, but they also add the number between brackets to the address being dereferenced. For example: */

    // a[5] = 0;       // a [offset of 5] = 0
    // *(a+5) = 0;     // pointed to by (a+5) = 0 
    
    // Pointer initialization ______________________________
    // pointers can be inirialized to point to specific locations at then very moment they are defined
    int myvar1;
    int * myptr = &myvar1;

    //Pointer arithmetics ___________________________________
    /* types have different sizes. For example: char always has a size of 1 byte, short is generally larger than that, and int and long are even larger; the exact size of these being dependent on the system. For example, let's imagine that in a given system, char takes 1 byte, short takes 2 bytes, and long takes 4. */

    char *mychar;
    short *myshort;
    long *mylong;

    ++mychar; ++myshort; ++mylong;

    /* 
    *p++   // same as *(p++): increment pointer, and dereference unincremented address
    *++p   // same as *(++p): increment pointer, and dereference incremented address
    ++*p   // same as ++(*p): dereference pointer, and increment the value it points to
    (*p)++ // dereference pointer, and post-increment the value it points to */

    // A typical -but not so simple- statement involving these operators is:

    // *p++ = *q++;
    
    /* Because ++ has a higher precedence than *, both p and q are incremented, but because both increment operators (++) are used as postfix and not prefix, the value assigned to *p is *q before both p and q are incremented. And then both are incremented. It would be roughly equivalent to: */
    // *p = *q;
    // ++p;
    // ++q;
    

    // Pointers and const __________________________________
    /* POinters can be used to access a variable by its address, and this access may include modifying the value pointed. But it is also possible to declare pointers that can access the pointed value to read ir, but not to modify it. For this, it is enough with qualifying the typle pointed to by the pointer as const. For example: */
    int x;
    int y = 10;
    const int * z = &y;
    x =  *p;        // ok: reading p
    // *z = x;         // error: modifying z, which is const-qualified

    /*  safety feature, pointers to const are not implicitly convertible to pointers to non-const.
    
    One of the use cases of pointers to const elements is as function parameters: a function that takes a pointer to non-const as parameter can modify the value passed as argument, while a function that takes a pointer to const as parameter cannot. */

    // pointers as arguments
    int numbers1[] = {10, 20, 30};
    increment_all (numbers1, numbers1+3);
    print_all (numbers1, numbers1+3);
    
    /* Note that print_all uses pointers that point to constant elements. These pointers point to constant content they cannot modify, but they are not constant themselves: i.e., the pointers can still be incremented or assigned different addresses, although they cannot modify the content they point to.
    
    And this is where a second dimension to constness is added to pointers: Pointers can also be themselves const. And this is specified by appending const to the pointed type (after the asterisk):*/

    int d;
    int *       z1 = &d;  // non-const pointer to non-const int
    const int *       z2 = &d;  // non-const pointer to const int
    int * const z3 = &d;  // const pointer to non-const int
    const int * const z4 = &d;  // const pointer to const int 

    /* The syntax with const and pointers is definitely tricky, and recognizing the cases that best suit each use tends to require some experience. In any case, it is important to get constness with pointers (and references) right sooner rather than later, but you should not worry too much about grasping everything if this is the first time you are exposed to the mix of const and pointers. More use cases will show up in coming chapters. */

    /* To add a little bit more confusion to the syntax of const with pointers, the const qualifier can either precede or follow the pointed type, with the exact same meaning: */
    const int * p2a = &x;  //      non-const pointer to const int
    int const * p2b = &x;  // also non-const pointer to const int 

    /* As with the spaces surrounding the asterisk, the order of const in this case is simply a matter of style. This chapter uses a prefix const, as for historical reasons this seems to be more extended, but both are exactly equivalent. The merits of each style are still intensely debated on the internet */

    // Pointers and string literals ________________________
    // As pointed earlier, string literals are arrays containing null-terminated character sequences. In earlier sections, string literals have been used to be directly inserted into cout, to initialize strings and to initialize arrays of characters.

    /* But they can also be accessed directly. String literals are arrays of the proper array type to contain all its characters plus the terminating null-character, with each of the elements being of type const char (as literals, they can never be modified). For example: */

    const char * fooo = "hello"; 

    // Note that here fooo is a pointer and contains the value 1702, and not 'h', nor "hello", although 1702 indeed is the address of both of these.

    /* The pointer foo points to a sequence of characters. And because pointers and arrays behave essentially in the same way in expressions, foo can be used to access the characters in the same way arrays of null-terminated character sequences are. 
    
    *(foo+4)
    foo[4]  */

    // Pointers to pointer
    /* C++ allows the use of pointers that point to pointers, that these, in its turn, point to data (or even to other pointers). The syntax simply requires an asterisk (*) for each level of indirection in the declaration of the pointer
    
    char a;
    char * b;
    char ** c;
    a = 'z';
    b = &a;
    c = &b;     */

    /* The new thing in this example is variable c, which is a pointer to a pointer, and can be used in three different levels of indirection, each one of them would correspond to a different value:

    c is of type char** and a value of 8092
    *c is of type char* and a value of 7230
    **c is of type char and a value of 'z' */

    // Void Ponters________________________________________
    /* Void pointers are pointers that point to a value that has no type (and thus also an undetermined length and undetermined dereferencing properties).
    
    This gives void pointers a great flexibility, by being able to point to any data type, from an integer value or a float to a string of characters. In exchange, they have a great limitation: the data pointed to by them cannot be directly dereferenced (which is logical, since we have no type to dereference to), and for that reason, any address in a void pointer needs to be transformed into some other pointer type that points to a concrete data type before being dereferenced.*/
    char a = 'x';
    int b = 1602;
    increaser (&a,sizeof(a));
    increaser (&b,sizeof(b));
    cout << a << ", " << b << '\n';

    // sizeof is an operator integrated in the C++ language that returns the size in bytes of its argument. For non-dynamic data types, this value is a constant. Therefore, for example, sizeof(char) is 1, because char has always a size of one byte. 

    // Invalid pointers and null pointers _________________
    /* In principle, pointers are meant to point to valid addresses, such as the address of a variable or the address of an element in an array. But pointers can actually point to any address, including addresses that do not refer to any valid element. Typical examples of this are uninitialized pointers and pointers to nonexistent elements of an array:


    int * p;               // uninitialized pointer (local variable)

    int myarray[10];
    int * q = myarray+20;  // element out of bounds 


    Neither p nor q point to addresses known to contain a value, but none of the above statements causes an error. In C++, pointers are allowed to take any address value, no matter whether there actually is something at that address or not. What can cause an error is to dereference such a pointer (i.e., actually accessing the value they point to). Accessing such a pointer causes undefined behavior, ranging from an error during runtime to accessing some random value.

    But, sometimes, a pointer really needs to explicitly point to nowhere, and not just an invalid address. For such cases, there exists a special value that any pointer type can take: the null pointer value. This value can be expressed in C++ in two ways: either with an integer value of zero, or with the nullptr keyword:

    int * p = 0;
    int * q = nullptr;


    Here, both p and q are null pointers, meaning that they explicitly point to nowhere, and they both actually compare equal: all null pointers compare equal to other null pointers. It is also quite usual to see the defined constant NULL be used in older code to refer to the null pointer value:

 
    int * r = NULL;


    NULL is defined in several headers of the standard library, and is defined as an alias of some null pointer constant value (such as 0 or nullptr).

    Do not confuse null pointers with void pointers! A null pointer is a value that any pointer can take to represent that it is pointing to "nowhere", while a void pointer is a type of pointer that can point to somewhere without a specific type. One refers to the value stored in the pointer, and the other to the type of data it points to. */

    // Pointers to functions_________________________________
    /* C++ allows operations with pointers to functions. The typical use of this is for passing a function as an argument to another function. Pointers to functions are declared with the same syntax as a regular function declaration, except that the name of the function is enclosed between parentheses () and an asterisk (*) is inserted before the name: */

    int m,n;
    int (*minus)(int,int) = substraction;

    m = operation (7, 5, addition);
    n = operation (20, m, minus);
    cout <<n;




    return 0;
}