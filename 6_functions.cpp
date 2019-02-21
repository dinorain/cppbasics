#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

#define NEWLINE '\n'

void odd (int x);
void even (int x);

/* Functions allow structure programs in segment of code to perform individual tasks.

type name ( parameter1, parameter2, ...) { statements }

where:
    type is the type of the value returned by the function
    name is the identifier by which the function can be called
    parameters (as many as needed) 
    statement is the function's body

*/

int addition ( int a, int b ) {
    int r;
    r = a + b;
    return r;
}

int substraction ( int a, int b ) {
    int r;
    r = a - b;
    return r;
}

// functions with no type. The use of void
void printmessage () { // or void printmessage (void)
    cout << "I am a function!";
}

//passing parameters by reference
void duplicate ( int& a; int& b; int& c ) { 
    // references are indicated with an ampersand (&) following the parameter type
    a *= 2;
    b *= 2;
    c *= 2;
}
(
int divide(int a, int b=2) {
    int r;
    r = a / b;
    return (r);
}

// Recursivity
long factorial (long a) {
    if (a > 1)
        return (a * factorial (a-1));
    else
        return 1;
}

int main () {
    int z;
    z = addition (5,3);
    cout << "The result is " << z << endl;
    cout << NEWLINE;

    int x=5, y=3, n;
    n = substraction (7,2);
    cout << "The first result is " << n << endl;
    cout << "The second result is " << substraction (7,2) << endl;
    cout << "The third result is " << substraction (x, y) << endl;
    n = 4 + substraction (x,y);
    cout << "The forth result is " << n << endl;
    cout << NEWLINE;

    // void funtion
    printmessage ();

    // passing parameters by reference
    int a=1, b=3, c=5;
    duplicate (a, b, c);
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    // inline functions

    /* Preceding a function declaration with the inline specifier informs the compiler that inline expansion
    is preferred over the usual function call mechanism for a specific function. This does not change at all
    the behavior of a function, but is merely used to suggest the compiler that the code generated by the function body shell be inserted at each point the function is called, instead of being invoked with a regular function call.
    */

    // Default values in parameters
    /* In C++, functions can also have optional parameters, for which no arguments are required in the call,
    in such a way that, a function with three parameters may be called with only two. For this, the function shall
    include a default value for its last parameter, which is used by the function when called with fewer arguments
    */

    cout << divide (12) << NEWLINE;
    cout << divide (20,4) << endl;


    int i;
    do {
        cout << "Please input a number (0 to exit): ";
        cin >> i;
        odd (i);
    } while (i != 0);

    // Recursivity 
    // Recursivity is the property that functions have to be called by themselves.
    long number = 9;
    cout << number << "! = " << factorial (number);

    //floor
    double x =1.411, y =1.500, z =1.711; 
    cout << floor(x) << endl; 
    cout << floor(y) << endl; 
    cout << floor(z) << endl; 
  
    double a =-1.411, b =-1.500, c =-1.611; 
    cout << floor(a) << endl; 
    cout << floor(b) << endl; 
    cout << floor(c) << endl; 
    
    // ceil
    cout << ceil(x) << endl; 
    cout << ceil(y) << endl; 
    cout << ceil(z) << endl; 
  
    cout << ceil(a) << endl; 
    cout << ceil(b) << endl; 
    cout << ceil(c) << endl; 

    // trunc
    cout << trunc(x) << endl; 
    cout << trunc(y) << endl; 
    cout << trunc(z) <<endl; 
  
    cout << trunc(a) <<endl; 
    cout << trunc(b) <<endl; 
    cout << trunc(c) <<endl; 

    // round
    cout << round(x) << endl; 
    cout << round(y) << endl; 
    cout << round(z) << endl; 
  
    cout << round(a) << endl; 
    cout << round(b) << endl; 
    cout << round(c) << endl; 

    // set precision 
    double pi = 3.14159, npi = -3.14159; 
    cout << fixed << setprecision(0) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(1) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(2) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(3) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(4) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(5) << pi <<" "<<npi<<endl; 
    cout << fixed << setprecision(6) << pi <<" "<<npi<<endl; 
    return 0;
}

void odd (int x) {
    if ((x%2)!=0) cout << "It is odd.\n";
    else even (x);
}

void even (int x) {
    if ((x%2)==0) cout << "It is even.\n";
    else odd (x);
}