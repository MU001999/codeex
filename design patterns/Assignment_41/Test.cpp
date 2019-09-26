#include <string>
#include <iostream>
#include "Text.hpp"
#include "Cipher.hpp"

using namespace std;
// using the namespace named design_patterns for this project
using namespace design_patterns;

// the main control function
int main(int argc, char *argv[])
{
    PlainText text("This an example LOL"s);

    // case 1: just simple encrypt
    {
        cout << SimpleEncrypt(text, 5).getText() << endl;
    }

    // case 2: just simple encrypt twice
    {
        cout << SimpleEncrypt(SimpleEncrypt(text, 5), 5).getText() << endl;
    }

    // case 3: just reverse the plain text
    {
        cout << ReverseEncrypt(text).getText() << endl;
    }

    // case 4: sepcial instance with unexcepted result
    {
        // actually the result will be same with case 3
        // there will be copy elision in cpp
        // explanation at https://en.cppreference.com/w/cpp/language/copy_elision
        // in the initialization of a variable,
        // when the initializer expression is a prvalue of the same class type (ignoring cv-qualification) as the variable type:
        // T x = T(T(f())); // only one call to default constructor of T, to initialize x
        cout << ReverseEncrypt(ReverseEncrypt(text)).getText() << endl;
        // it can be solved by add addtional parameter (just for distinguish but not used)
        // for example, make the constructor like ReverseEncrypt(ReverseEncrypt(text, 0), 0)
        // the zero is not used in constructor and any other places
    }

    // case 5: just complex (simple in fact) encrypt
    {
        cout << ComplexEncrypt(text).getText() << endl;
    }

    // case 6: encrypt with all methods
    {
        cout << ComplexEncrypt(ReverseEncrypt(SimpleEncrypt(text))).getText() << endl;
    }

    return 0;
}
