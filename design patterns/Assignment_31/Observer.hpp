#pragma once

#include <iostream>

namespace design_patterns
{
// abstract base class Observer
class Observer
{
  public:
    // pure virtual destructor but with definition
    virtual ~Observer() = 0;
    // pure virtual method receives the value of the voice of the subject
    // and update (change sth. or do some actions)
    virtual void update(int voice) = 0;
};

// definition for Observer's destructor
inline Observer::~Observer() {}

// derived class Rat extends Observer
class Rat : public Observer
{
  public:
    // implement of update
    // receives the value of the voice of the subject (cat)
    // tell others that it is a rat and it runs away
    void update(int voice) override
    {
        // check the subject (cat) yells or not
        if (voice > 0)
        {
            std::cout << "I'm a rat, I run away LOL" << std::endl;
        }
    }
};

// derived class Dog extends Observer
class Dog : public Observer
{
  public:
    // implement of update
    // receives the value of the voice of the subject (cat)
    // tell others that it is a dog and it barks
    void update(int voice) override
    {
        // check the subject (cat) yells or not
        if (voice > 0)
        {
            std::cout << "I'm a dog, I bark LOL" << std::endl;
        }
    }
};

// derived class Duck extends Observer
class Duck : public Observer
{
  public:
    // implement of update
    // receives the value of the voice of the subject (cat)
    // tell others that it is a duck and it does nothing
    void update(int voice) override
    {
        // check the subject (cat) yells or not
        if (voice > 0)
        {
            std::cout << "I'm a duck, I do nothing LOL" << std::endl;
        }
    }
};
} // namespace design_patterns
