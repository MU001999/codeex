#pragma once

#include <map>
#include <list>
#include <tuple>

namespace design_patterns
{
class Stock;

// abstract base class Observer
class Observer
{
  public:
    // pure virtual destructor but with definition
    virtual ~Observer() = 0;
    // pure virtual method receives the value of the voice of the subject
    // and update (change sth. or do some actions)
    virtual void update(Stock *stock, double range) = 0;
};

class Investor : public Observer
{
  public:
    Investor(std::string name);
    std::string getName() const;

    void update(Stock* stock, double range) override;
    void buyStock(Stock *stock, int shares, double range = -1.0);
    void changeRange(Stock *stock, double range);
    void sellStock(Stock *stock, int shares);
    void sellStockAll(Stock *stock);

  private:
    std::string name_;
    std::list<Stock *> stocks_;
    std::map<Stock *, int> shares_;
};

} // namespace design_patterns
