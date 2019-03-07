#include <cstdio>
#include <cassert>
#include "calculate.hpp"

#define ASSERT(INPUT, TARGET)   printf("input \"%s\", result \"%s\"\n", INPUT, calculate(INPUT).c_str()); \
                                assert(calculate(INPUT) == TARGET);


int main()
{
    ASSERT("1 + 2", "3");
    ASSERT("1 + 2 * 3", "7");
    ASSERT("1 + 2 * 3 - 4 % 5 + 6 - 7 + 8 % 9", "10");
    ASSERT("(1 + 2) / 3", "1");
    ASSERT("(2 + 3) % (3 / 2)", "0");
    return 0;
}
