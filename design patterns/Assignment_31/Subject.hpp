#pragma once

#include <list>
#include <iostream>
#include "Observer.hpp"

namespace design_patterns
{
// abstract base class
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

class Cat : public Subject
{
  public:
    Cat() : voice_(0)
    {
        // do nothing
    }

    int getVoice() const
    {
        return voice_;
    }

    void setVoice(int voice)
    {
        voice_ = voice;
        notifyObservers();
    }

    void yell()
    {
        setVoice(10);
    }

    void registerObserver(Observer *observer) override
    {
        observers_.push_back(observer);
    }

    void removeObserver(Observer *observer) override
    {
        observers_.remove(observer);
    }

    void notifyObservers() override
    {
        for (auto observer : observers_)
        {
            observer->update(voice_);
        }
    }

  private:
    int voice_;
    std::list<Observer *> observers_;
};
} // namespace design_patterns
