#include <cassert>
#include "Stock.hpp"
#include "Observer.hpp"

using namespace std;
using namespace design_patterns;

Stock::Stock(string name, double price)
  : name_(move(name)), price_(price), curDealShares_(0) {}

string Stock::getName() const
{
    return name_;
}

double Stock::getPrice() const
{
    return price_;
}

void Stock::setPrice(double price)
{
    price_ = price;
    curDealShares_ = 0;
    notifyObservers();
}

void Stock::registerObserver(Observer *observer)
{
    assert(observer != nullptr);
    assert(!infos_.count(observer));
    observers_.push_back(observer);
    infos_[observer] = make_tuple(0, price_, DefaultRange);
}

void Stock::removeObserver(Observer *observer)
{
    assert(infos_.count(observer));
    observers_.remove(observer);
    infos_.erase(observer);
}

void Stock::notifyObservers()
{
    for (auto observer : observers_)
    {
        auto [_, price, range] = infos_[observer];
        auto low  = price - price * range,
             high = price + price * range;
        if (price_ <= low or price_ >= high)
        {
            observer->update(this, (price_ - price) / price);
        }
    }
}

void Stock::changeShares(Observer *observer, int shares)
{
    assert(infos_.count(observer));
    curDealShares_ += shares;
    auto [oldShares, oldPrice, oldRange] = infos_[observer];
    if (oldShares + shares == 0)
    {
        removeObserver(observer);
        return;
    }
    auto price = (oldShares * oldPrice + shares * price_) / (oldShares + shares);
    infos_[observer] = make_tuple(oldShares + shares, price, oldRange);
}

void Stock::changeRange(Observer *observer, double range)
{
    assert(infos_.count(observer));
    get<2>(infos_[observer]) = range;
}

void Stock::nextRound()
{
    updatePrice(curDealShares_);
}

void Stock::updatePrice(int shares)
{
    setPrice(price_ * (shares <= SellThreshold ? 0.8 : 1.2));
}
