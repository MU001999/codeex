#include <string>
#include <iostream>
#include "Text.hpp"
#include "Cipher.hpp"

using namespace std;
using namespace design_patterns;

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

    // case 3
    {

    }

    // case 4:
    {
        // actually the result will be same with case 3
        // there will be copy elision in cpp
        // explanation at https://en.cppreference.com/w/cpp/language/copy_elision
        // in the initialization of a variable,
        // when the initializer expression is a prvalue of the same class type (ignoring cv-qualification) as the variable type:
        // T x = T(T(f())); // only one call to default constructor of T, to initialize x

        // it can be solved by add addtional parameter (just for distinguish but not used)
        // list make the constructor like ComplexEncrypt(ComplexEncrypt(text, 0), 0)
        // the zero is not used in constructor and any other places
    }

    return 0;
}
