#include <cassert>
#include "Subject.hpp"

using namespace std;
using namespace design_patterns;

Subject::~Subject() {}

Stock::Stock(string name, double price)
    : name_(move(name)), price_(price)
{
    // do nothing
}

// get the voice of the cat
double Stock::getPrice() const
{
    return price_;
}

// receives the value of voice
// and set the voice of the cat
void Stock::setPrice(double price)
{
    price_ = price;
    // notify all observers after setting the voice
    notifyObservers();
}

// implement of registerObserver
void Stock::registerObserver(Observer *observer, int shares, double range)
{
    assert(observer != nullptr);
    assert(!infos_.count(observer));
    observers_.push_back(observer);
    infos_[observer] = std::make_tuple(shares, price_, range);
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
}

// implement of removeObserver
void Stock::removeObserver(Observer *observer)
{
    assert(infos_.count(observer));
    observers_.remove(observer);
    infos_.erase(observer);
}

// implement of notifyObservers
void Stock::notifyObservers()
{
    // traverse observers
    for (auto observer : observers_)
    {
        auto [_, price, range] = infos_[observer];
        auto low  = price - price * range,
                high = price + price * range;
        if (price_ <= low or price_ >= high)
        {
            observer->update((price_ - price) / price);
        }
    }
}
