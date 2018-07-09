/*
Q-URL: https://www.codewars.com/kata/count-ones-in-a-segment/train/cpp
*/

#include <limits>

long long countOne ( int n )
{
    long long result = 0;
    for (int i = std::numeric_limits<int>::digits - 1; i >= 0; --i)
    {
        int b = 1 << i;
        if (n & b)
        {
            result += static_cast<long long>(i) * (b >> 1) +  // MEANS THE NUMBER OF 1 BEFORE 100...;
                      (n & b - 1) + 1;                        // MEANS THE NUMBER OF 1 AT THE CURRENT POSITION OF I;
        }
    }
    return result;
}

long long countOnes ( int left, int right )
{
	  return countOne(right) - countOne(left - 1);
}
