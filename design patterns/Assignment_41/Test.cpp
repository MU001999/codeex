#include <string>
#include <iostream>
#include "Text.hpp"
#include "Cipher.hpp"

using namespace std;
using namespace design_patterns;

int main(int argc, char *argv[])
{
    PlainText text("This an example LOL"s);

    {
        cout << SimpleEncrypt(text).getText() << endl;
    }

    {
        cout << SimpleEncrypt(SimpleEncrypt(text)).getText() << endl;
    }

    return 0;
}
