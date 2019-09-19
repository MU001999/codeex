#pragma once

#include <list>
#include <iostream>
#include "Observer.hpp"

namespace design_patterns
{
class Subject
{
  public:
    virtual ~Subject() = 0;
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers() = 0;
};

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
