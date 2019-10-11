#include <cassert>
#include "Stock.hpp"

using namespace std;
using namespace design_patterns;

Stock::Stock(string name, double price)
  : name_(move(name)), price_(price)
{
    // do nothing
}

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
    notifyObservers();
}

void Stock::registerObserver(Observer *observer, int shares, double range)
{
    assert(observer != nullptr);
    assert(!infos_.count(observer));
    observers_.push_back(observer);
    infos_[observer] = std::make_tuple(shares, price_, range);
    updatePrice(shares);
}

void Stock::updateObserver(Observer *observer, int shares, double range)
{
    assert(infos_.count(observer));
    auto [old_shares, old_price, old_range] = infos_[observer];
    if (old_shares + shares == 0)
    {
        removeObserver(observer);
        return;
    }
    auto price = (old_shares * old_price + shares * price_) / (old_shares + shares);
    infos_[observer] = std::make_tuple(old_shares + shares, price, range);

    if (shares > 0)
    {
        updatePrice(shares);
    }
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

void Stock::updatePrice(int shares)
{
    if (shares < SellThreshold)
    {
        setPrice(price_ * 0.9);
    }
    else
    {
        setPrice(price_ * 1.1);
    }
}
