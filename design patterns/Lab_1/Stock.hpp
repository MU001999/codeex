#pragma once

#include <map>
#include <list>
#include <tuple>
#include <string>
#include "Observer.hpp"

namespace design_patterns
{
class Stock
{
  public:
    Stock(std::string name, double price);

    std::string getName() const;
    double getPrice() const;
    void setPrice(double price);

    void registerObserver(Observer *observer, int shares, double range);
    void updateObserver(Observer *observer, int shares, double range);
    void removeObserver(Observer *observer);
    void notifyObservers();

  private:
    constexpr static int SellThreshold = 10;

    void updatePrice(int shares);

    std::string name_;
    double price_;
    std::list<Observer *> observers_;
    std::map<Observer *, std::tuple<int, double, double>> infos_;
};
} // namespace design_patterns
