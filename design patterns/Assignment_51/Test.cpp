#include <iostream>
#include <exception>
#include "Product.hpp"
#include "Factory.hpp"

using namespace std;
using namespace design_patterns;

int main(int argc, char *argv[])
{
    {
        Factory *factory = new HaierFactory();
        auto product = factory->createProduct("TV");
        cout << product->getInfo() << endl;
    }

    {
        Factory *factory = new HaierFactory();
        try
        {
            auto product = factory->createProduct("Fridge");
            cout << product->getInfo() << endl;
        }
        catch(const std::invalid_argument& e)
        {
            cerr << e.what() << endl;
        }
    }

    return 0;
}
