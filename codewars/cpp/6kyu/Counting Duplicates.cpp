/*
Q-URL: https://www.codewars.com/kata/counting-duplicates/cpp
*/

size_t duplicateCount(const std::string& in); // helper for tests

inline char cast(char in)
{
  return ('a' <= in && in <= 'z') ? (in - 32) : in;
}

size_t duplicateCount(const char* in)
{
    int flags[43] = {0};
    while (*in) ++flags[cast(*in++)-48];
    size_t sum = 0;
    for (int i = 0; i < 43; i++) sum += flags[i] > 1;
    return sum;
}