#include <iostream> // preprocessor , do not require semicolon ; at the end
#include <string>
using namespace std; // std stands for the standard character output

int main () { // initiates the declaration of a function
    cout << "Hello World";
    cout << endl; // Inserts a new line and flushes the stream
    cout << "\n"  // Only inserts a new line.


    /* This is a block comment */

    // declaring variables _________________________________________________________
    int a = 1;
    int b (2);
    int c {3};

    int result;
    result = a - b;
    cout << result << endl;

    int d;
    d = 4;

    // printing out _________________________________________________________
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

    decltype(a) e; // the type of e is as same as of a
    e = 5;
    cout << e << endl;

    auto f = e; // the type of f is as same as of e
    f = 6;
    cout << f << endl;

    string first = "This is the first";
    cout << first << endl;
    string second ("This is the second");
    cout << second << endl;
    string third {"This is the third"};
    cout << third << endl;

    string mystring;
    mystring = "This is my initial content";
    cout << mystring << endl;
    mystring = "This is my second content";
    cout << mystring << endl;

    // terminate your program
    return 0;
}