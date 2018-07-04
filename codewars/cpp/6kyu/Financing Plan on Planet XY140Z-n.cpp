/*
Q-URL: https://www.codewars.com/kata/financing-plan-on-planet-xy140z-n/cpp
*/

class Finance
{
  public:
  static unsigned long long finance(unsigned long long n){
      return n * (n + 1) * (n + 2) / 2;
  }
};
