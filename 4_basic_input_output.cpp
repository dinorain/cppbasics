#include <iostream>
#include <cstring>
#include <sstream> // stringstream
using namespace std;

#define NEWLINE '\n'

int main () {
    /*
    C++ uses a convenient abstaraction called streams to perform input and output operaions in sequential
    media such as the screen, the keyboard aor a file. A stream is an entity where a program can insert or 
    extract characters to/from.

    cin standard input stream
    cout standard output stream
    cerr standard error (output) stream
    clog standard logging (input) stream

    */

    // Standard ouput (cout) _________________________________________________________
    // Multiple insertion operations (<<) may be chained in a single statement
    cout << "This is " << "a single" << " C++ statement" << endl;
    cout << NEWLINE;

    // Chaining insertions is especially useful to mix literals and variables in a single statement
    int age = 18;
    string name = "Dustin";
    cout << "I am " << age << " years old and my name is " << name <<endl;
    cout << NEWLINE;

    // Standard input (cin) _________________________________________________________
    // cin is used together as the extraction operator, which is written as >>
    int num;
    cout << "Please input a number : ";
    cin >> num;
    cout << "Your number is " << num;
    cout << " and its double value is " << num*2 << ".\n";
    cout << NEWLINE;

    // extractions on cin can also be chained to request more than one datujm in a single statement
    int a, b;

    cin >> a >> b;
    cout << NEWLINE;

    // cin and strings _________________________________________________________
    string mystr;
    cout << "What's your name ? ";
    getline (cin, mystr); 
    getline (cin, mystr);
    // to get an entire line from cin, there exists a function called getline
    cout << "Hello " << mystr << ".\n";
    cout << "What is your favorite colour ? ";
    getline (cin, mystr);
    cout << "I like " << mystr << " too." << '\n';
    cout << NEWLINE;
    
    /* the standard header <sstream> define a type called stringstream that allows a string to be treated as a
    stream, and thus allowing extraction or insertion operations from/to strings in the same way as they are 
    performed on cin and cout. This feature is most useful to convert strings to numerical values and vice versa.
    */

    string str;
    float price=0;
    int quantity=0;

    cout << "Enter price: ";
    getline (cin, str);
    stringstream(str) >> price; // converts numerical values to strings
    cout << "Enter quantity: ";
    getline (cin, str);
    stringstream(str) >> quantity;
    cout << "Total price: " << price*quantity << endl;

    // How to use getline() in C++ when there are blank lines in input?
    string str; 
    int t = 4; 
    while (t--) 
    { 
        getline(cin, str); 
  
        // Keep reading a new line while there is 
        // a blank line 
        while (str.length()==0 ) 
            getline(cin, str); 
  
        cout << str << " : newline" << endl; 
    } 

    return 0;
}