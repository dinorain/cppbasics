#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

#define NEWLINE '\n'

int findOdd(int arr[], int n) { 
    int res = 0, i; 
    for (i = 0; i < n; i++) res ^= arr[i]; 
    return res; 
} 

int main () {
    // assignment operator _________________________________________________________
    int a, b;           // a: ?, b: ?
    a = 10;             // a: 10, b: ?
    b = 4;              // a: 10, b: 4
    a = b;              // a: 4, b: 4
    b = 7;              // a: 4, b : ?

    cout << "a: ";
    cout << a;
    cout << ", b :";
    cout << b << endl;
    cout << NEWLINE;

    int c, d;
    c = 2 + (d = 5);
    cout << "c: ";
    cout << c << endl;
    cout << NEWLINE;

    int x, y, z;
    x = y = z = 6;
    cout << "x :";
    cout << x;
    cout << ", y: ";
    cout << y;
    cout << ", z: ";
    cout << z << endl;
    cout << NEWLINE;

    // Arithmetic operators (+,-,*,/,%) _________________________________________________________
    // correspond literally to their respective mathemathical operations
    int i = 11 % 3;
    cout << "11 mod 3 = ";
    cout << i << endl;
    cout << NEWLINE;

    // Compound assignment operators (+=, -=, *=, /=, %= , >>=, <<=, &= , ^=, |=) ___________________________
    /* Compound assignment operators modify the current valued of a variable by performing an operation on it*/

    int e, f = 3;
    e = f;
    e += 2;
    cout << "e: ";
    cout << e << endl;
    cout << NEWLINE;

    // Increment and decrement (++, --)
    // the increase operator (++) increase by one the value stored in a variable
    // the derement operator (--) decrease by one the value stored in a variable

    int g = 5;
    ++g;        // g = 6
    g += 1;     // g = 7
    g = g + 1;  // g = 8
    cout << "g: ";
    cout << g << endl;
    cout << NEWLINE;

    // A peculiarity in increment and decrement can be used in both as a prefix ++x and as a suffix x++
    // When it is used as a prefix ++x, the expression evaluates to the final value of x
    // When it is used as a suffix x++, the expression evauluates to the value of x that had before being increased

    // prefix ++x
    int j, k;
    j = 1;
    k = ++j;
    // j contains 2, k contains 2
    cout << "j: ";
    cout << j << endl;
    cout << "prefix k = ++j" << endl;
    cout << "k: ";
    cout << k << endl;
    cout << NEWLINE;

    // suffix x++
    int m, n;
    m = 1;
    n = m++;
    // m contains 2, n contains 1
    cout << "m: ";
    cout << m << endl;
    cout << "suffix n = m++" << endl;
    cout << "n: ";
    cout << n << endl;
    cout << NEWLINE;

    // Relational and comparison operators (==, !=, >, <, >=, <=) __________________________________________________
    // result of such an operations is either true or false (i.e. , a Boolean value)

    bool l  = (7 < 4);
    cout << l << endl; // prints 0 
    cout << (5 < 5) << endl;

    // not just numeric constants can be compared, but just any value
    cout << (a == b) << endl;
    cout << (a*b >= c ) << endl;
    cout << (b+4 > a*c) << endl;
    cout << ((b = 2) == a) << endl;
    cout << NEWLINE;

    // Logical operations (!, &&, ||) _________________________________________________________
    // The operator ! corresponds to the Boolean logical expressions NOT
    cout << !(a == b) << endl;
    cout << !true << endl;
    cout << NEWLINE;

    /* the operaots && and || are used when evaluating two expressons to obatain a single redlational result
    The operator %% corresponds to the Boolean logical operations AND
    The operator || corresponds to the Boolean logical operations OR */

    bool u, v;
    u = (5 == 5) && (3 > 6);
    v = (5 == 5) || (3 > 6);
    cout << u << endl; // evaluate to false (true && false)
    cout << v << endl; // evaluate to true (true || false)
    cout << NEWLINE;

    /* C++ uses a short-circuit evaluations _________________________________________________________
    && if the left-hand side expressions is false, the combined result is false (the right-hand expression is never evaluated)
    || if the left-hand side expressions is false, the combined result is true (the right-hand expressions is never evaluated)
    */
    
    // Conditional theory operator (?) _________________________________________________________
    /* The conditional operator evaluates an expression, returning one value if that expression evaluates to true 
    and a different one if the expressions evaluates as false 
    
    It's syntax is: 
    condition ? result1 : result2
    if conditions is, the entire expressions evaluates to result1, and otherwise to result2
    */
    
    int t = (7 == 5) ? 4 : 3;
    cout << t << endl; // evaluates to 3, since 7 is not equal to 5
    cout << NEWLINE;
   
    // Comma operator , _________________________________________________________
    /* used to separate two or more expressions that are included where only one expression is expected. 
    When the set of expressions has to be evaluated for a value, only the right-most expression is considered*/

    int p, q;
    p = (q = 3, q + 2); /* would assign the value 3 to q, and then assign q + 2 to variable p. 
    So at the end , variable p would contain the value 5 while variable q would contain value 3*/

    // Bitwise operators (&, |, ^, ~, <<, >>) _________________________________________________________
    unsigned char a = 5, b = 9; // a = 5(00000101), b = 9(00001001) 
    printf("a = %d, b = %d\n", a, b); 
    printf("a&b = %d\n", a&b); // The result is 00000001 
    printf("a|b = %d\n", a|b);  // The result is 00001101 
    printf("a^b = %d\n", a^b); // The result is 00001100 
    printf("~a = %d\n", a = ~a);   // The result is 11111010 
    // ~ Takes one number and inverts all bits of it

    printf("b<<1 = %d\n", b<<1);  // The result is 00010010 
    // << Takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
    printf("b>>1 = %d\n", b>>1);  // The result is 00000100 
    // >> Takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.

    // The left shift and right shift operators should not be used for negative numbers, otherwise it results in undefined behaviour

    // The bitwise XOR operator is the most useful operator from technical interview perspective.
    // Given a set of numbers where all elements occur even number of times except one number, find the odd occurring number
    int arr[] = {12, 12, 14, 90, 14, 14, 14}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf ("The odd occurring element is %d ", findOdd(arr, n));

    // The bitwise operators should not be used in place of logical operators.
    // The result of logical operators (&&, || and !) is either 0 or 1, but bitwise operators return an integer value. Also, the logical operators consider any non-zero operand as 1
    int x = 2, y = 5; 
    (x & y)? printf("True ") : printf("False "); 
    (x && y)? printf("True ") : printf("False "); 

    // The left-shift and right-shift operators are equivalent to multiplication and division by 2 respectively.
    int x = 19; 
    printf ("x << 1 = %d\n", x << 1); 
    printf ("x >> 1 = %d\n", x >> 1); 

    // The & operator can be used to quickly check if a number is odd or even
    int x = 19; 
    (x & 1)? printf("Odd"): printf("Even"); 

    // The ~ operator should be used carefully
    unsigned int x = 1; 
    printf("Signed Result %d \n", ~x); 
    printf("Unsigned Result %ud \n", ~x); 

    // Explicit type casting operator
    int r;
    float s = 3.14;
    r = (int) s; // converted to 3, the remainder is lost
    r = int (s); // the same as above
    cout << "r: ";
    cout << r << endl;
    cout << NEWLINE;

    // sizeof _________________________________________________________
    // This operator accepts one parameter, which can be either a type or a variable, and returns the size in bytes of that type or object

    cout << "The sizeof of a char is ";
    cout << sizeof (char) << endl;
    cout << NEWLINE;

    // Precedence of operators _________________________________________________________
    /* In C++, parts of the expressions can be enclosed in parenthesis to override the precedence order,
    or to make explicitly clear the intended effect */
    cout << (5 + 7) % 2 << endl;
    cout << 5 + (7 % 2) << endl;
    cout << NEWLINE;

    return 0;
}
