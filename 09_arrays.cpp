#include <iostream>
#include <string>
#include <sstream>
#include <array>
using namespace std;

#define NEWLINE '\n'
#define WIDTH 5
#define HEIGHT 3

/* Initializing arrays _________________________________________________________________________________
By default, regular arrays of local scope are left unitialized. This means that none of its elements
are set to any particular value; their contents are undetermined at then point the arrayh is declared
    
But the elements in an array can be explicitly initialized to specific values when it is declared,
by enclosing thokse initial values in braces {} */

int foo [5] = { 16, 2, 77, 40, 12071 };
// The number of values between braces {} shall not be greater than the number of elements in the array 

int bar [5] = { 10, 20, 30 };
// If declared with less, the remaining elements are set to their default values : 0

int empty [5] = { };
// The initializer can even have no values, just the braces

int autosize [] = { 16, 2, 77, 40, 12071 };
/* When an intialization of values is providxed for an array, C++ allows the possibility of leaving the
    square barckets empty []. In this case, the compiler will assume automatically a size for the array that matches
    the number of values incllude between the braces {} */

// The universal initializationfor arrays made by C++
int univ[] { 10, 20, 30 };
/* static arrays, and those declared directly in a namespace (outside any function), are always initialized. 
If no explicit initializer is specified, all the elements are default-initialized (wwith zeros)*/

int arrayy [] = { 16, 2, 77, 40, 12071 };
int n, result = 0;

// Multidimensional arrays _________________________________________________________________________________________
/* Multidimensional arrays can be described as "arrays of arrays". For example, a bidimensional array can
be imagined as a two -dimensional table made of elements, all of them of a same uniform data type */

int jimmy [3][5]; // jimmy represents a bidimensional array of 3 per 5 elements of type int

/* Multidimensionl arrays are not likmited to two indices(i.e., two dimensions). They contain as many as needed.
Although be careful : the amount of memory needed for an array increases exponentially wikth each 
dimension */

/* At the end, multidimensional arrays are just an abstraction for programmers, since the same results can be achieved with a simple array, by multiplying its indices */
int janet [3][5];   // is equivalent to int janet [15]
/* with the only difference that with multidimensional arrays, the compiler automatically remebers the depth of each 
imaginary dimension.*/

/* The following two pieces of code produce the same result, but one uses a bidimensional aray while the other uses a simple array */
int twin1 [HEIGHT][WIDTH];
int twin2 [HEIGHT * WIDTH];
int p,q;

// Arrays as parameters ________________________________________________________________________________________
/* In C++, it iks not possible to passs the entire block represented to a funciton directly as an argument.
But what can be passed instead is its address */

/* To accept an array as a parameter for a function, the parameters can be declared as the array type, but
with emptly brackets, omitting the actual size of the array */
void procedure (int arg[]); // This function accepts a parameter of type "array of int" called arg

// in order to pass this function an array is declared as int myarray [40];
// it would be enough to write a call like this : procedure (myarray);

// example
void printarray (int arg[], int length) {
    for (int n=0; n<length; ++n) {
        cout << arg[n] << ' ';
    }
    cout << '\n';
}

// In a function declaration, it is also possible to include multidiemensional arrays
// The format for a tridimensional array parameter is 
// base_type[][depth][depth]

void procedure3 (int myarray3[][3][4]);

/* In away, passing am array as argument always loses a dimension. The reason behind is that, for historical reasons, arrays cannot be directly copied, and thus what is really passed is a pointer. This is a common source of errors for
novice programmers. Although a clear understanding of pointers, expainedd in a coming chapter, helps a lot */

// Library arrays_____________________________________________________________________________________________
/* The arrays explained above are directly implemented as a language feature, inherited from the C language.
They are a great feature, but by restricting its copy and easily decay into pointers, they probably suffer from
an excess of optimization */

/* To overcome some of these issues wikth language built-in arrays, C++ provides an alternative array type as a standard container. It is a type template (a class template, in fact) defined in header <array> 

Containers are a library feature that falls out of the scope of this tutorial, and thus the class will not be explained in detail here. Suffice it to say that they operate in a similar way to built-in arrays, except that they allow being
copied (an actually expelnsive operation that copies the entire block of memory, and thus to use with care) and decay into pointers only when explicitly told to do so (by means of its member data) */


int main () {
    // Arrays _____________________________________________________________________________________________
    /* An array is a series of elements of the same type placed in contiguos memory locations that can be
    indvidually referenced by adding an index to a unique identifier */
    
    // Like a regular variable, an array must be declared before it is used.
    // type name [elements]


    // Accessing the values of an array __________________________________________________________________________
    // syntax : name[index]

    foo [2] = 75; // storing the vlaue 75 in the third elements of foo

    int x;
    x = foo[2]; // copies the vlaue of the third element of foo to a variable called x
    // Therefore, the expression foo[2] is itself a variable of typel int

    /* In C++, ikr is syntactically correct to exceed the valid range of indices for an array. This can create problenms
    since accessing out-of-range elements do not cause errors on compilation, butj can vause errors on runtime.
    The reason for this being allowed will be seen in a later chapter when apoinyers are introduced */

    /* At this point, it is important to be able to Clearly distinguish between two uses of that brackets */
    int wow[5]; // declaration of a new array
    wow[2] = 75; // access to an elemetn of the array

    // some other vlaikd operations with arrays
    int b, a = 5;

    foo[0] = a;
    foo[a] = 75;
    b = foo [a+2];
    foo[foo[a]] = foo[2] +5;

    for ( n=0 ; n<5 ; ++n ) {
        result += foo[n];
        cout << foo[n];
        if (n<4)
            cout << " + ";
    }
    cout << " = " << result << endl;
    cout << NEWLINE;

    // Multidimensional arrays________________________________________________________________________________
    /* Multidimensional arrays can be described as "arrays of arrays". For example, a bidimensional array can
    be imagined as a two -dimensional table made of elements, all of them of a same uniform data type */

    // reference always begin with 0
    jimmy[1][3] = 75; // the way to refer the second element vertically and fourth horizontally

    // The following two pieces of code produces the same result
    /* Note that the code uses defined constants for the width and height, instead of using directly their numerical values. This gives the code a better readibility, and allows changes in the code to be made easily in one place*/
    for (p=0; p<HEIGHT; p++) {
        for (q=0; q<WIDTH; q++) {
            twin1[p][q]=(p+1)*(q+1);
        }
    }

    for (p=0; p<HEIGHT; p++) {
        for (q=0; q<WIDTH; q++) {
            twin2[p*WIDTH+q]=(p+1)*(q+1);
        }
    }
    printarray (twin2, 15);
    cout << NEWLINE;

    // arrays as parameters
    int firstarray[] = {5, 10, 15};
    int secondarray[] = {2, 4, 6, 8, 10};
    
    printarray (firstarray, 3);
    cout << NEWLINE;
    printarray (secondarray, 5);
    cout << NEWLINE;

    // Library arrays_________________________________________________________________________________________\
    // language built-in array
    int arraybuilt[3] = {10, 20, 30};

    for (int z=0; z<3; z++) {
        ++arraybuilt[z];
    }
    for (int elem : arraybuilt) {
        cout << elem << endl;
    }
    cout << NEWLINE;


    array<int,3> arraylib {10, 20, 30};
    for (int k=0; k<arraylib.size(); ++k) {
        ++arraylib[k];
    }
    for (int elemb : arraylib) {
        cout << elemb << endl;
    }
    cout << NEWLINE;

    /* As you can see , both kinds of arrays use the same syntax to access its elements. Other than that,
    thne main differences lay on the declaration of the array, and the inclusion of an additional header for the library array. Notice also hows it is easy to access the size of the library array */



    return 0;
}