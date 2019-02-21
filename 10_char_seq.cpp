// character sequences
#include <iostream>
#include <string>
#include <sstream>
#include <array>
using namespace std;

#define NEWLINE '\n'

// Initialization of null-terminated character sequences
char myword[] {'H', 'e', 'l', 'l', 'o', '\0'}; // declares an array of 6 elements 

// Initialization using string literals directly 
/* Sequences of characters enclosed in double-quotes (") are literal constants. And their type is, in fact, a null-
terminated array of characters. This means that string literals always have null character ('\0') automaticlaly appended at the end*/
char word[] = "Hello";


int main () {
    /* Strings are sequences of characters so we can represent them also as plain arrays of elements of a character type
    
    For example, the following array :
    char foo [20]; is an array that can store up to 20 elements of type char

    By convention, the end of strings represented in character sequences is signaled by a special character:
    the null character, whose literal value can be written as '\0' (backslash, 0)

    In this case, the array of 20 elements of type char called foo can be represented storing the character sequences :
    "Hello" and "Merry Christmas" */

    cout << "Before : " << myword[0] << endl;
    myword[0] = 'B';
    cout << "After : " << myword[0] << endl;
    /* Expressions like
    myword = "Bye"; or
    myword[] = "Bye"; or 
    myword = {'B', 'y', 'e', '\0' }

    would not be valid. This is because arrays cannokt be assigned values. Note, though, that each of its elments can 
    be assigned a value individually */

    myword[0] = 'B';
    myword[1] = 'y';
    myword[2] = 'e';
    myword[3] = '\0';

    // Strings and null-terminated char seq____________________________________________________________________________
    /* In C++, even though the satandard library defines a specific type for strings (class string), still, plain
    arrays with null-terminated sequences of characters (C-strings) are a natural way of representing strings in the language; in fact, string literals still always produce null-terminated character sequences, and not string objects*/

    /* Fro example. cin and cout support null=terminated sequences directly, allowing them to be directly extracted from cin or inserted into cout , just like strings*/

    // strings and NTCS
    char question1[] = "What is your name? ";
    string question2 = "where do you live? ";
    char answer1 [20]; //arrays have a fixed size that needs to be specified either implicit or explicitly when declared
    string answer2;
    cout << question1;
    cin >> answer1;
    cout << question2;
    cin >> answer2;

    cout << "Hello, " << answer1;
    cout << " from " << answer2 << "\n";
    cout << NEWLINE;

    /* Null-terminated char seq can be transformed into strings implicitly, and strings can be transformed into
    null-terminated char seq by using either of string's member functions c_str or data : */
    char myntcs[] = "some text";
    string mystring = myntcs;   // convert c-string to string
    cout << mystring;           // printed as a library string
    cout << mystring.c_str();   // printed as a c-string



    return 0;
}