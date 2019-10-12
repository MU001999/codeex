#pragma once

#include <map>
#include <list>
#include <tuple>
#include <string>

namespace design_patterns
{
class Observer;

// concrete class without an absract base class
class Stock
{
  public:
    // constructor
    // param name: the name of this stock
    // param price: initial price of this stock
    Stock(std::string name, double price);

    // return name of the stock
    std::string getName() const;
    // return current price of the stock
    double getPrice() const;
    // set price for the stock
    // param price: the price you want to set
    void setPrice(double price);

    // register the given observer in the stock
    void registerObserver(Observer *observer);
    // remove the given observer in the stock
    void removeObserver(Observer *observer);
    // notify all registered observers
    void notifyObservers();

    // change shares for the given observer to buy or sell
    // param observer: for which observer to buy or sell
    // param shares: shares of this deal
    void changeShares(Observer *observer, int shares);
    // change range for the given observer to
    //     decide to receive notifications or not
    // param observer: for which observer
    // param range: the expected range
    void changeRange(Observer *observer, double range);

    // execute all transactions in current round and then update the price
    void nextRound();

  private:
    // constant for the threshold to decide to increase or reduce the price
    // less than it to reduce and greater than it to increase
    constexpr static int SellThreshold = 50;
    // default range for observer to decide to receive notification or not
    constexpr static double DefaultRange = 0.2;

    // update price of this stock by all changed shares in current round
    void updatePrice(int shares);

    std::string name_;
    double price_;
    // member to remeber changed shares in current round
    int curDealShares_;
    // member contains all the registered observers
    std::list<Observer *> observers_;
    // member to store the info,
    // which contains shares, price for investor and the range, of each observer
    std::map<Observer *, std::tuple<int, double, double>> infos_;
};
} // namespace design_patterns
