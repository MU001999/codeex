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
        cout << SimpleEncrypt(text).getText() << endl;
    }

    // case 2: special initial with result unexpected
    {
        // actually the result will be same with case 1
        // there will be copy elision in cpp
        // explanation at https://en.cppreference.com/w/cpp/language/copy_elision
        // in the initialization of a variable,
        // when the initializer expression is a prvalue of the same class type (ignoring cv-qualification) as the variable type:
        // T x = T(T(f())); // only one call to default constructor of T, to initialize x
        cout << SimpleEncrypt(SimpleEncrypt(text)).getText() << endl;
    }

    return 0;
}
