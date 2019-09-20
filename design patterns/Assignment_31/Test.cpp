#include "Observer.hpp"
#include "Subject.hpp"

// using the namespace named design_patterns for this project
using namespace design_patterns;

// template function for testing ovserver and subjects
// T for class Observer, and Ts for rest class Observers
// returns nothing and just test
template <typename T, typename ...Ts>
auto test(Cat *cat) -> void
{
    // init one object (observer)
    T obj;

    // register the observer in the subject (cat)
    cat->registerObserver(&obj);

    // call test<Ts...>(cat) if size of Ts (rest class Observers) is greater than 0
    // else call cat->yell()
    if constexpr (sizeof...(Ts) > 0)
    {
        test<Ts...>(cat);
    }
    else
    {
        cat->yell();
    }

    // remove the observer from the subject (cat)
    cat->removeObserver(&obj);
}

// the main control function
int main(int argc, char *argv[])
{
    // init a subject (cat)
    Cat cat;

    {
        // case that observer is only a rat
        test<Rat>(&cat);
    }

    {
        // case that observers consist of three rats
        test<Rat, Rat, Rat>(&cat);
    }

    {
        // case that observers consist of three dogs
        test<Dog, Dog, Dog>(&cat);
    }

    {
        // case that observers consist of one rat, one dog and one duck
        test<Rat, Dog, Duck>(&cat);
    }

    // just return 0
    return 0;
}
