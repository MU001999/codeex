#include <iostream>
#include <exception>
#include "Product.hpp"
#include "Factory.hpp"

using namespace std;
using namespace design_patterns;

template <typename F, typename T1, typename ...Ts>
void test(T1 arg, Ts... args)
{
    Factory *factory = new F();
    try
    {
        auto product = factory->createProduct(arg);
        cout << product->getInfo() << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
    }
    delete factory;
    if constexpr (sizeof...(Ts) > 0)
    {
        test<F>(args...);
    }
}

int main(int argc, char *argv[])
{
    test<HaierFactory>("TV", "Fridge", "Mobilephone");
    test<TCLFactory>("TV", "Fridge", "Mobilephone");
    test<HisenseFactory>("TV", "Fridge", "Mobilephone");
    test<AppleFactory>("TV", "Fridge", "Mobilephone");

    return 0;
}
