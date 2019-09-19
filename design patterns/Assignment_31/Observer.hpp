#pragma once

#include <iostream>

namespace design_patterns
{
class Observer
{
  public:
    virtual ~Observer() = 0;
    virtual void update(int voice) = 0;
};

inline Observer::~Observer() {}

class Rat : public Observer
{
  public:
    void update(int voice) override
    {
        if (voice > 0)
        {
            std::cout << "I'm a rat, I run away LOL" << std::endl;
        }
    }
};

class Dog : public Observer
{
  public:
    void update(int voice) override
    {
        if (voice > 0)
        {
            std::cout << "I'm a dog, I bark LOL" << std::endl;
        }
    }
};

class Duck : public Observer
{
  public:
    void update(int voice) override
    {
        if (voice > 0)
        {
            std::cout << "I'm a duck, I do nothing LOL" << std::endl;
        }
    }
};
} // namespace design_patterns
