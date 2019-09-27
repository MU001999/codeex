#include <iostream>
#include "Product.hpp"
#include "Factory.hpp"

using namespace std;
using namespace design_patterns;

int main(int argc, char *argv[])
{
    {
        Factory *factory = new HaierFactory();
    }

    return 0;
}
