#include <iostream>
#include <exception>
#include "Product.hpp"
#include "Factory.hpp"

using namespace std;
// using the namespace named design_patterns for this project
using namespace design_patterns;

// template function for testing factories
// F for the class of one concrete factory
// T1 for the first type of product to test
// Ts for rest types of products to test
// return nothing and just test
template <typename F, typename T1, typename ...Ts>
void test(T1 arg, Ts... args)
{
    // new one factory of type F
    Factory *factory = new F();
    try
    {
        // try to get the product
        auto product = factory->createProduct(arg);
        // if success above then print the info of the product
        cout << product->getInfo() << endl;
    }
    catch (const invalid_argument &e)
    {
        // print the content of error
        // when the exception is catched
        cout << e.what() << endl;
    }
    // delete the factory
    delete factory;

    // if rest types are not empty
    // then continue to call test by rest types
    if constexpr (sizeof...(Ts) > 0)
    {
        test<F>(args...);
    }
}

int main(int argc, char *argv[])
{
    // just test that product TV, Fridge and Mobilephone by HaierFactory
    test<HaierFactory>("TV", "Fridge", "Mobilephone");

    // just test that product TV, Fridge and Mobilephone by TCLFactory
    test<TCLFactory>("TV", "Fridge", "Mobilephone");

    // just test that product TV, Fridge and Mobilephone by HisenseFactory
    test<HisenseFactory>("TV", "Fridge", "Mobilephone");

    // just test that product TV, Fridge and Mobilephone by AppleFactory
    test<AppleFactory>("TV", "Fridge", "Mobilephone");

    return 0;
}
