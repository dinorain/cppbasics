/* In C++, two different functions canhave the same name if their parameters are different; 
either because they have a different number or parameters, or because any of their parameters are of a different type.
*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define NEWLINE '\n'


// A funciton cannot be overloaded only by its return type. At lease one of it parameters must have a different type
int operate ( int a, int b) {
    return (a*b);
}

int operate ( double a, double b) {
    return (a/b);
}

// Overloaded functions may have the same definition
int sum ( int a, int b ) {
    return a + b;
}

double sum ( double a, double b) {
    return a + b;
}

/*C++ has the ability to define functions with generic types, known as function templates. 
Defining a function templates follows the same syntax as a regular function,
except that it is preceded by the template keyword and a series of template parameters enclosed in angle-brackets 
*/

template <class SomeType>
SomeType total (SomeType a, SomeType b) {
    return a + b;
}

/* templates are a powerful and versatile feature. They can have multiple template parameters, and the function call
still use regular non-templated types*/
template <class T, class U>
bool are_equal ( T a, U b) {
    return (a==b);
}

/* Non-type template arguments 
    The template parameters can not only include tyoes introduced by class or typename, but can also inlcude expressions of a particular type
*/
template <class T, int N>
T fixed_multiply (T val)
{
    return val * N;
}



int main () {
    int x = 5, y = 2;
    double n=5.0, m=2.0;
    cout << operate (x,y) << endl;
    cout << operate (n,m) << endl;
    cout << NEWLINE;

    cout << sum (10, 20) << endl;
    cout << sum (1.0, 1.5) << endl;
    cout << NEWLINE;

    /* calling the function template 
    name <template-arguments> ( function-arguments )
    */
    int z;
    z = total<int>(10,20);
    cout << z << endl;
    cout << endl;

    if (are_equal(10,10.0)) // equivalent to are_equal<int, double>(10, 10.0)
        cout << "x and y are equal" << endl;
    else
        cout << "x and y are not equal" << endl;
    cout << NEWLINE;

    cout << fixed_multiply<int,2>(10) << endl;
    cout << fixed_multiply<int,3>(10) << endl;

    return 0;
}