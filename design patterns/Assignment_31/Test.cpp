#include "Observer.hpp"
#include "Subject.hpp"

using namespace design_patterns;

template <typename T, typename ...Ts>
auto test(Cat *cat) -> void
{
    T obj;
    cat->registerObserver(&obj);
    if constexpr (sizeof...(Ts) > 0)
    {
        test<Ts...>(cat);
    }
    else
    {
        cat->yell();
    }
    cat->removeObserver(&obj);
}

int main(int argc, char *argv[])
{
    Cat cat;

    {
        test<Rat, Dog, Duck>(&cat);
    }

    return 0;
}
