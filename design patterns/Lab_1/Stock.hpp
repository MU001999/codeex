#pragma once

#include <map>
#include <list>
#include <tuple>
#include <string>

namespace design_patterns
{
class Observer;
class Stock
{
  public:
    Stock(std::string name, double price);

    std::string getName() const;
    double getPrice() const;
    void setPrice(double price);

    void registerObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notifyObservers();

    void changeShares(Observer *observer, int shares);
    void changeRange(Observer *observer, double range);

    void nextRound();

  private:
    constexpr static int SellThreshold = 50;
    constexpr static double DefaultRange = 0.2;

    void updatePrice(int shares);

    std::string name_;
    double price_;
    int curDealShares_;
    std::list<Observer *> observers_;
    std::map<Observer *, std::tuple<int, double, double>> infos_;
};
} // namespace design_patterns
