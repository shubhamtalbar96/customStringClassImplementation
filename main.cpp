#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

class Mystring {
    char* str;

public:
    // Default constructor
    Mystring();

    // Constructor with 1 argument
    Mystring(char* val);

    // Copy constructor
    Mystring(const Mystring& source);

    // Move constructor
    Mystring(Mystring&& source);

    // Delete constructor
    ~Mystring() {
        delete str;
    }
};

// Default constructor
Mystring::Mystring() {
    str = new char[1];
    str[0] = '\0';
}

// Constructor with one argument
Mystring::Mystring(char* val) {
    if(val == NULL) {
        str = new char[1];
        str[0] = '\0';
    }
    else {
        str = new char[strlen(val) + 1];
        strcpy(str, val);

        cout << "String generated : " << str << endl;
    }
}

// Copy constructor
Mystring::Mystring(const Mystring& source) {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring(Mystring&& source) {
    str = source.str;
    source.str = NULL;
}

int main() {
    Mystring a;
    
    char temp[] = "Hello";
    Mystring b(temp);

    cout << "Checking copy constructor" << endl;
    Mystring c(b);
    
    cout << "Checking Move constructor" << endl;
    Mystring d( Mystring (temp) );

    return 0;
}