/* A data structure is a group of data aelements grouped together under one name. These data elements, known as members, 
can have different types and different lengths. Data structures can be declared in C++ using thes following syntax:

struct type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3; 
.
.
} object_names; */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t {
    string title;
    int year;
}   mine, yours;

// array of strucures
struct movies_array {
    string title;
    int year;
}   films [3];

// pointers to structures
struct movies_p {
    string title;
    int year;
};

// nesting structures
struct friends_t {
    string name;
    string email;
    movies_t favorite_movie;
} charlie, maria;

void printmovie (movies_t movie);
void printmovie1 (movies_array movie);

int main () {
    string mystr;

    mine.title = "2001 A Spazce Odyssey";
    mine.year = 1968;

    cout << "Enter title: ";
    getline (cin, yours.title);
    cout << "Enter year: ";
    getline (cin, mystr);
    stringstream(mystr) >> yours.year;

    cout << "My favorite movie is:\n ";
    printmovie (mine);
    cout << "And yours is:\n ";
    printmovie (yours);

    // array of structures _____________________________________________________________________________________
    string myword;
    int n;

    for (n=0; n<3; n++) {
        cout << "Enter title: ";
        getline (cin, films[n].title);
        cout << "Enter year: ";
        getline (cin, myword);
        stringstream(myword) >> films[n].year;
    }

    cout << "\nYou have entered these movies: \n";
    for (n=0; n<3; n++) {
        printmovie1 (films[n]);
    }

    // Pointers to structures ___________________________________________________________________________________
    movies_p amovie;    // amovie is an object of strucutre type movies_p
    movies_p * pmovie;  // pmovie is a pointer to point to objects of structure type movies_p, also valid: pmovie = &amovie;
    pmovie = &amovie;

    cout << "Enter title: ";
    getline (cin, pmovie->title); // pmovie->title equivalents to (*pmovie).title
    cout << "Enter year: ";
    getline (cin, mystr);
    (stringstream) mystr >> pmovie->year;

    cout << "\nYou have entered: \n";
    cout << pmovie->title;
    cout << " (" << pmovie->year << ")\n";

    // The -> is a deference operator that is used exclusvely with pointers to objects that have members. This operator serves to access the member of an object direct;ly from its address.

    // Nesting sturctures _____________________________________________________________________________________
    friends_t * pfriends = &charlie;

    charlie.name;
    maria.favorite_movie.title;
    charlie.favorite_movie.year;
    pfriends->favorite_movie.year;



    return 0;
}

void printmovie (movies_t movie) {
    cout << movie.title;
    cout << " (" << movie.year << ")\n";
}

void printmovie1 (movies_array movie) {
    cout << movie.title;
    cout << " (" << movie.year << ")\n";
}
