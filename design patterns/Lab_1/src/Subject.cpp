#include <random>
#include <cassert>
#include "Subject.hpp"
#include "Observer.hpp"

using namespace std;
using namespace design_patterns;

Subject::~Subject() {}

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
    // clear changed shares of current round
    curDealShares_ = 0;
    // notify all registered observers
    notifyObservers();
}

void Stock::registerObserver(Observer *observer)
{
    // assert the pointer to the observer is not nullptr
    // and the given observer is not registered
    assert(observer != nullptr);
    assert(!infos_.count(observer));
    // store the observer and with default info
    observers_.push_back(observer);
    infos_[observer] = make_tuple(0, price_, DefaultRange);
}

void Stock::removeObserver(Observer *observer)
{
    // assert the observer has been registered
    assert(infos_.count(observer));
    // remove the observer
    observers_.remove(observer);
    infos_.erase(observer);
}

void Stock::notifyObservers()
{
    // traverse all observers and
    // notify the observers that satisfy the condition
    for (auto observer : observers_)
    {
        auto [_, price, range] = infos_[observer];
        auto low  = price - price * range,
             high = price + price * range;
        // notify the observer if price
        // is less than the low threshold
        // or greater than the high threshold
        if (price_ <= low or price_ >= high)
        {
            // update with this stock and changed range
            observer->update(this, (price_ - price) / price);
        }
    }
}

void Stock::changeShares(Observer *observer, int shares)
{
    // assert the observer has been registered
    assert(infos_.count(observer));
    // firstly update the curDealShares_
    curDealShares_ += shares;
    auto [oldShares, oldPrice, oldRange] = infos_[observer];
    // remove the observer if the observer has sold all shares it has
    if (oldShares + shares == 0)
    {
        // removeObserver(observer) should be called by the observer
        return;
    }
    // update the info of this investor
    auto price = (oldShares * oldPrice + shares * price_) / (oldShares + shares);
    infos_[observer] = make_tuple(oldShares + shares, price, oldRange);
}

void Stock::changeRange(Observer *observer, double range)
{
    // assert the observer has been registered
    assert(infos_.count(observer));
    get<2>(infos_[observer]) = range;
}

void Stock::nextRound()
{
    updatePrice();
}

void Stock::updatePrice()
{
    // this code is copied from
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    // to produce a random floating-point value
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 0.5);
    // if curDealShares_is less than SellThreshold,
    //     increse the price with the random range
    // else reduce the price with the random range
    setPrice(price_ * (curDealShares_ <= SellThreshold
        ? (1 - dis(gen))
        : (1 + dis(gen))));
}
