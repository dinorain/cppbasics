#include <iostream>
#include <string>
using namespace std;

// prepocessor macros definitions #define
#define PI 3.14159
#define NEWLINE '\n'
// macro with parameter 
#define AREA(l, b) (l * b) 

// typed constants value
const double pi = 3.14159;
const char newline = '\t';

int main () {
    int a (75);  // decimal
    cout << a << endl;
    int b (0113); // octal starts with 0
    cout << b << endl;
    int c (0x4b); // hexadecimal starts with 0x
    cout << c << endl;

    float d (3.14159L);
    cout << d << endl;
    float e (6.02e23f); //  6.02 x 10^23
    cout << e << endl;
    float f (1.6e-19); //  1.6 x 10^-19
    cout << f << endl;

    cout << "This continues to \n a new line \n " << endl; // \n means new line
    cout << "One \nTwo \nThree \n " << endl;
    cout << "Left \t Right " << endl; // \t means tab

    /* 
    Several string literals can be concacenated to form a single string literal simply 
    by separating them one by one or more blank spaces, including tabs, newline, and other
    valid blank characters.
    */

   cout << "This forms " "a single"   " string"
   " of characters " << endl; // spaces within the quotes are part of literal, while those outside them are not

   // line-continuation "\"
   cout << "This string is expressed in \
   two lines" << endl;

   /* All the character literals and string literals are made of characters of type char */

   // Raw strings R
   /* In raw strings, backslashes and single and double quotes are all valid charactes;
   the content of the literal is deliminated by an initial R"sequence( and a final )sequence", 
   where sequence is any sequence if characters (including an empty sequence). The content of the string
   is what lies inside the parentheses, ignoring the delimiting sequence itself.
   */
    
    cout << R"(string with \backslash)" << endl;
    cout << R"&%&(string with \backslash)&%&" << endl;
    
    // true, false , and nullptr
    // true and false are two possible values for variables of type bool
    // nullptr is the null pointer value
    
    bool foo = true;
    bool bar = false;
    int* p = nullptr;

    cout << foo << endl; // prints 1
    cout << bar << endl; // prints 0
    
    // typed constant values >> scroll upmost ^^
    double r = 5.0;   // radius
    double circle;
    
    circle = 2 * pi * r;
    cout << circle;
    cout << NEWLINE;
    
    // prepocessor definitions #define >> scroll upmost ^^ 
    circle = 2 * PI * r;
    cout << circle;
    cout << NEWLINE;

    int l1 = 10, l2 = 5, area; 
    area = AREA(l1, l2); 
    cout << "Area of rectangle is: " << area; 


    return 0;
}