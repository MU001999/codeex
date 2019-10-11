#pragma once

#include <map>
#include <list>
#include <tuple>
#include <iostream>

namespace design_patterns
{
class Subject;

// abstract base class Observer
class Observer
{
  public:
    // pure virtual destructor but with definition
    virtual ~Observer() = 0;
    // pure virtual method receives the value of the voice of the subject
    // and update (change sth. or do some actions)
    virtual void update(double range) = 0;
};

// definition for Observer's destructor
inline Observer::~Observer() {}

class Investor : public Observer
{
  public:
    constexpr static int defaultRange = 0.1;

    void update(double range) override;
    void buyStock(Subject *stock, int shares);
    void changeRange(Subject *stock, double range);
    void sellStock(Subject *stock, int shares);
    void sellStockAll(Subject *stock, int shares);

  private:
    std::list<Subject *> stocks_;
    std::map<Subject *, std::tuple<int, double>> infos_;
};

} // namespace design_patterns
