// In each scope, a name can only represent one entity. So, there cannot be two variables with the same name in the same scope. Using namespaces, we can create two variables or member functions having the same name.
#include <iostream>
#include <stdio.h>
#include "ns_header.h" // user defined files
#define NEWLINE '\n'
using namespace std;

// variable created inside namespace ________
// first name space 
namespace first  
{  
   int val1 = 500;   
} 
  
// rest part of the first namespace 
namespace  first  
{  
   int val2 = 501;   
} 

// global variable
int val1 = 100;

// no name for static declaration of variables
namespace {
    int rel = 300;
}

// Function(s) in a namespace _______________
namespace ns1 {
    int value() { return 5;}
}

namespace ns2 {
    const double x = 100;
    double value () { return 2*x;}
}

// Class(es) in a namespace ______________
namespace ns {
    class geek {
    public:
        void display() {
            cout << "ns::geek::display()\n";
        }
    };
}

// class can also be declared inside namespace and defined outsid namespace
namespace in {
    class geek; // only declare
}

class in::geek {
public:
    void display() {
        cout << "ns::geek::display()\n";
    }
};

// Method(s) in a namepace)________________
namespace meth {
    void display();
    class awesome {
    public:
        void display();
    };
}

// defining methods of namespace
void meth::awesome::display() {
    cout << "meth::geek::display()\n";
}
void meth::display() {
    cout << "meth::display()\n";
}

// nested namespace _________________________
namespace out { 
    int val = 5;  
    namespace in {
        int val2 = val;     
    } 
}

// namespace aliasing _____________________
namespace name1  
{ 
    namespace name2  
    { 
        namespace name3  
        { 
            int var = 42; 
        } 
    } 
} 
  
// Aliasing  
namespace alias = name1::name2::name3;

int main () {
    // local variable
    int val1 = 600;
    // element in a namespace can be accessed with ::
    cout << first::val1 << endl;
    cout << val1;
    
    cout << NEWLINE << NEWLINE;

    printf("%d \n", val1);
    printf("%d \n", first::val2);
    cout << NEWLINE;
    cout << rel << '\n';

    // access value function within ns1
    cout << ns1::value() << '\n';

    // acess value function within ns2
    cout << ns2::value() << '\n';

    // acess variable x directly
    cout << ns2::x << '\n';

    // create an object of student class
    ns::geek obj;
    obj.display();
    cout << NEWLINE;
    in::geek wow;
    wow.display();
    
    // method
    meth::awesome lol;
    meth::display();
    lol.display();

    // using namepace in header files
    cout << foo::value() << '\n';

    // nested namespace
    cout << out::in::val2;   // prints 5 

    // aliasing
    cout << alias::var << '\n';
    
    return 0;
}