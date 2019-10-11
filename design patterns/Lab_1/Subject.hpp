#pragma once

#include <map>
#include <list>
#include <tuple>
#include <string>
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
    virtual void registerObserver(Observer *observer, int shares, double range) = 0;
    // pure virtual method receives a point of one Observer
    // and remove it from the subject
    virtual void updateObserver(Observer *observer, int shares, double range) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    // pure virtual method receives no arguments
    // and notify all observers registered
    virtual void notifyObservers() = 0;
};

// derived class Cat extends Subject
class Stock : public Subject
{
  public:
    // default constructor
    Stock(std::string name, double price);

    double getPrice() const;
    void setPrice(double price);

    void registerObserver(Observer *observer, int shares, double range = 0.1) override;
    void updateObserver(Observer *observer, int shares, double range) override;
    void removeObserver(Observer *observer) override;
    void notifyObservers() override;

  private:
    std::string name_;
    double price_;
    // store all observers registered
    std::list<Observer *> observers_;
    std::map<Observer *, std::tuple<int, double, double>> infos_;
};
} // namespace design_patterns
