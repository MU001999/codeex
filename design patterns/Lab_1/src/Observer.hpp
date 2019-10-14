#pragma once

#include <map>
#include <list>
#include <tuple>
#include <functional>

namespace design_patterns
{
class Stock;

// abstract base class Observer
class Observer
{
  public:
    // pure virtual destructor but with definition
    virtual ~Observer() = 0;
    // pure virtual method which will be called by the subject
    // it has a default implement, so it can be called normally
    // and it will be fun to add interfaces for others Observer
    // if possible
    virtual void update(Subject *subject, double range) {};
};

// derived class Investor extends class Observer
class Investor : public Observer
{
  public:
    // type for the updateAction, which will be called in method update
    using ActionType = std::function<void(Investor *, Stock *, double)>;

    // constructor
    // param name: the name of this investor
    // param action: the funtion object which will be called
    //               in method update
    Investor(std::string name, ActionType &&action = nullptr);

    // get the name of this stock
    std::string getName() const;
    // set the action which will be called in method update
    void setUpdateAction(ActionType &&action);

    // inherited method and it will be called by the stock
    //     when the stock's price changes
    // param stock: which stock calls this method
    // param range: the changed range
    void update(Subject* stock, double range) override;
    // buy shares of the given stock and change the range
    //     if given range is greater than zero
    // param stock: which stock the investor buy shares of
    // param shares: how many shares to buy
    // param range: change the investor's range for notifying
    //              if given range is greater than zero
    void buyStock(Stock *stock, int shares, double range = -1.0);
    // change the range of this investor in the given stock
    // param stock: which stock the investor's range changes in
    // param range: the expected range to set in the given stock
    void changeRange(Stock *stock, double range);
    // sell shares of the given stock
    // param stock: the pointer to which stock the investor
    //              plans to sell shares of
    // param shares: the number of how many shares to sell
    void sellStock(Stock *stock, int shares);
    // sell all shares of the given stock
    // param stock: the pointer to which stock the investor
    //              plans to sell all shares of
    void sellStockAll(Stock *stock);

  private:
    std::string name_;
    // function object will be called in method update
    // to execute the real updating
    ActionType updateAction_;
    // stores all stocks the investor bought
    std::list<Stock *> stocks_;
    // stores shares of each stock the investor bought
    std::map<Stock *, int> shares_;
};

} // namespace design_patterns
