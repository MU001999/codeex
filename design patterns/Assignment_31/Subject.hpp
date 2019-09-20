#pragma once

#include <list>
#include <iostream>
#include "Observer.hpp"

namespace design_patterns
{
// abstract base class Subject
class Subject
{
  public:
    // pure virtual destructor but with definition
    virtual ~Subject() = 0;
    // pure virtual method receives a point of one Observer
    // and register it in the subject
    virtual void registerObserver(Observer *observer) = 0;
    // pure virtual method receives a point of one Observer
    // and remove it from the subject
    virtual void removeObserver(Observer *observer) = 0;
    // pure virtual method receives no arguments
    // and notify all observers registered
    virtual void notifyObservers() = 0;
};

// definition for Subject's destructor
inline Subject::~Subject() {}

// derived class Cat extends Subject
class Cat : public Subject
{
  public:
    // default constructor
    Cat() : voice_(0)
    {
        // do nothing
    }

    // get the voice of the cat
    int getVoice() const
    {
        return voice_;
    }

    // receives the value of voice
    // and set the voice of the cat
    void setVoice(int voice)
    {
        voice_ = voice;

        // notify all observers after setting the voice
        notifyObservers();
    }

    // the cat yells
    void yell()
    {
        // just call setVoice(10)
        setVoice(10);
    }

    // implement of registerObserver
    void registerObserver(Observer *observer) override
    {
        observers_.push_back(observer);
    }

    // implement of removeObserver
    void removeObserver(Observer *observer) override
    {
        observers_.remove(observer);
    }

    // implement of notifyObservers
    void notifyObservers() override
    {
        // traverse observers
        for (auto observer : observers_)
        {
            // call every observer's update method
            observer->update(voice_);
        }
    }

  private:
    int voice_;
    // store all observers registered
    std::list<Observer *> observers_;
};
} // namespace design_patterns
