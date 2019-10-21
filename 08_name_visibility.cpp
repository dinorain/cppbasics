#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/* the keyword using introduce a name into the current declarative region (such as block), thus avoiding the need to
qualify the name 
*/
#define NEWLINE '\n'

// Scopes ________________________________________________________________________________________________________
/* 
An entity declared outside any block has global scope, meaning that its name valid anywhere
in the code. While an entity declared within a block, such as a function or a selective
statement, has block scope, and is only visible within the specific block in  which it is 
declared, but not outside it.

variables with block scope are known as local variables

For example, a varibale declared in the body of a function is a local variable that extends until 
the end of the function that closes the function definition, but not outside it
*/

int foo;    // global variable

int some_funtion () {
    int bar;        // local variable
    bar = 0;
}

int other_function () {
    foo = 1;    // ok: foo is a global variable
    int bar = 2; // correct
    // bar = 2;    // wrong: bar is not visible from this function
}

// namespaces are particularly useful to avoid name collisions
namespace wow {
    int value() { return 5; } // function
}

namespace wew {
    const double pi = 3.1416;
    double value() { return  2*pi; }
}

// namespace can be split
namespace wow { int a; }
namespace wew { int b; }

// using
namespace first {
    int x = 5;
    int y = 10;
}

namespace second {
    double x = 3.1416;
    double y = 2.7183;
}

int main () {
    /* The visibility of an entity with block scope extends until the end of the block, including
    inner blocks. Nevertheless, an inner block, it is a different block, can re-utilize a name existing
    in an outer scope to refer to a different entity; in this case, the named will refer to a different
    entity until only within the inner block, hiding the intity it names outsikde. While outside it, it will still
    refer to the original entity.
    */
   
   // inner block scopes
   int a = 10;
   int b = 20;
   {
       int a;   // ok, inner scope.
       a = 50;  // sets value to inner x
       b = 50;  // sets value to (outer) y
       cout << "inner block:\n";
       cout << "a: " << a << '\n';
       cout << "b: " << b << '\n';
       cout << NEWLINE;
   }
   cout << "outer block:\n";
   cout << "a: " << a << endl;
   cout << "b: " << b << endl;
   cout << NEWLINE;

   // Namespces __________________________________________________________________________________________________
   /*
   Only one entry can exist with a particular name in a particular scope. This is seldom a problem for local names,
   since blocks tend to be relativley short, and names have particular purposes within them, such as naming a counter 
   varibale, an argument, etc..

   But non-local names bring more possibilities for name collision, especially conszidering that libraries may declare
   many functions, types, and varibles, neither of them local in nature, and some of them very genetic

   Namespace allow us to group named entities that otherwise would have global scope into narrow scopes, giving
   them namespace scope. This allows organizing the elemnts of programs into different logical scopes referred to by names.

   namespace identifier
   {
       named_enities
   } 
   */
    cout << wow::value() << endl; // accessing objects
    cout << wew::value() << endl; 
    cout << wew::pi << endl;
    cout << NEWLINE;

    // using _________________________________________________________________________________________________________
    using first::x;
    using second::y;
    cout << x << endl;
    cout << y << endl;
    cout << first::y << endl;
    cout << second::x << endl;
    cout << NEWLINE;

    using namespace first;
    cout << x << endl;
    cout << y << endl;
    cout << second::x << endl;
    cout << second::y << endl;
    cout << NEWLINE;

    // it would be possible to first use the objects of one namespace and then those of another one by splitting the code 
    {
        using namespace first;
        cout << x << endl;
    }
    {
        using namespace second;
        cout << x << endl;
    }
    cout << NEWLINE;

    // existing namespace can be aliased with new names, with the following syntax
    // namespace new_name = current_name;

    /* 
    Variables with static storage (such as global varibles) that are not explicitly initialized are automatically initialized to zeros

    Variables with automatic storage (such as local varibales) that are nolt explicityly initialized are left uninitialized and thus have an undetermined value
    */

    cout << foo << endl;
    int p;
    cout << p << endl;

    return 0;
}