#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define NEWLINE '\n'

int main () {
    // Selection statements : if and else _________________________________________________________
    /* The if keyword is usd to execute a statment or blcok, if , and only if, a confition is fulfilled. 

    It's syntax is : 
    if (condition) statement;
    else if (condition) statement;
    else statement

    */
    string str;
    int x;
    cout << "Please input a number : ";
    getline (cin, str);
    stringstream(str) >> x;
    
    if (x > 0) {
            cout << "Your number is " << x << " and ";
            cout << x << " is positive";
        }
    else if (x < 0) {
            cout << "Your number is " << x << " and ";
            cout << x << " is negative";
        }
    else 
        cout << x << "is 0";

    cout << NEWLINE;

    // Execute both if and else statements in C/C++ simultaneously
    // The trick is to use goto statement which provides an unconditional jump from the ‘goto’ to a labelled statement in the same function.
    if (1) //Replace 1 with 0 and see the magic 
    { 
    label_1: printf("Hello "); 
      
    // Jump to the else statement after  
    // executing the above statement 
    goto label_2; } 
    else
    { 
    // Jump to 'if block statement' if  
    // the Boolean condition becomes false 
    goto label_1; 
  
    label_2: printf("Geeks"); } 
    // Iteration statements (loops) _________________________________________________________
    // while (expressions) statement _________________________________________________________
    
    while (x>0) {
        cout << x << ", ";
        --x;
    }
    cout << "liftoff!\n";
    cout << NEWLINE;

    // do statement while (condition); _________________________________________________________
    /* In do-while loop, the condition is evaluated after the execution of statement instead of before,
    guaranteeing at least one execution of statement, even if condition is never fulifilled. */

    string text;
    do {
        cout << "Enter a text or a goodbye : ";
        getline (cin, text);
        cout << "You entered : " << text << '\n';
    } while (text != "goodbye");

    // for (initialization; condition; increase) statement; _________________________________________________________

    // countdown using a for loop
    for (int n = 10; n >0; n--) {
        cout << n << ", ";
    }
    cout << "goodbye!\n";

    /* The three fields in a for-loop are optional. They can be left empty, but in all cases the semicolon signs between them are required.
    For example :
    for (;n<10;) is a loop without initialization or increase (equivalent to a while loop)
    for (;n<10;++n) is a loop with no initialization (maybe because the variable was already initialized before)
    */

    // It's possible to exedcute more than a single expression as any of initialization, condition, or statement
    int a, b;
    for ( a=0, b=100 ; a!=b ; ++a, --b) {
        // whatever here...   
    }
    cout << NEWLINE;

    // Range-based for loop _________________________________________________________
    // for ( declaration : range ) statement;
    /* this kind of for loop iterates all the element in range, where declation declares some variable
    able to take the value of an elemtn in this range.
    */

    string word;
    cout << "Please input a word : ";
    getline (cin, word);
    for (char c : word) {
        cout << "[" << c << "]";
    }
    cout << NEWLINE << NEWLINE;

    // Jump statements _________________________________________________________
    // Jump statements allow altering the flow of a program by performing jumps to specific locations

    // The break statement _________________________________________________________
    // break leaves a loop, even if the condition for its end is not fulfilled

    for (int n = 10; n>0 ; n--) {
        cout << n << ", ";
        if (n == 3) {
            cout << "countdown aborted!";
            break;
        }
    }
    cout << NEWLINE;

    // The continue statement _________________________________________________________
    // causes the program to to skip the rest of the loop in the current iteration and restart
    for (int m = 10; m>0; m--) {
        if (m==5) continue;
        cout << m << ", ";
    }
    cout << "liftoff!\n";


    // The goto statement _________________________________________________________
    /* allows ro make an absolute jump to another point in the program. This unconditional jump ignores
    nesting levels, and does not cause any automatic stack unwinding
    
    The destination point is identified by a label, which is then used as an argument for the go to statement.
    A label is made of a valid identifier followed by a colon (:) */

    int p=10;
mylabel:
    cout << p << ", ";
    p--;
    if (p >0) goto mylabel;
    cout << "liftoff!\n";
    cout << NEWLINE;

    // switch _________________________________________________________
    // switch lets you check for a value among a number of possible constant expressions
    /* 
    switch (expression) {
        case constant1:
            group-of-statements-1;
            break;
        case constant2:
            group-of-statements-2;
            break;
        .
        .
        .
        default:
            default-group-of-statements
    }

    switch evaluates expressoin and checks if it is equivalent to constant1;
    if it is , it executes group-of-statements-1 until it finds the break statement.
    When it finds this break statement, the program jumps tok the end of the entire switch statement

    If expression was not equal to constan1, it is then checked against constant2. If it is 
    equal to this, it executes group-of-statement-2 until a break is found, when it jumps to the end of the switch.

    Finally, if the value of expression did not match any of the previously spedcified constants, 
    the program executes the statments include dafter the default: label, if it exists (since it isk optional)

    */
    int y (9);

    switch (y) {
        case 1:
            cout << "y is 1";
            break;
        case 2:
            cout << "y is 2";
            break;
        
        default:
            cout << "value of y is unknown";
    }

    cout << NEWLINE;

    int z (1);

    switch (z) {
        case 1:
        case 2:
        case 3:
            cout << "z is 1, 2, or 3";
            break;
        
        default:
            cout << "z is not 1, 2, or 3";
    }

    /*
    Constant expressions allowed
    switch(1+2+23)
    switch(1*2+3%4) */

    /* 
    Variable expression not allowed
    switch(ab+cd)
    switch(a+b+c)  */

    return 0;
}