#include <cassert>
#include "Observer.hpp"
#include "Subject.hpp"

using namespace std;
using namespace design_patterns;

Observer::~Observer() {}

void Investor::update(double range)
{

}

void Investor::buyStock(Subject *stock, int shares)
{
    if (!infos_.count(stock))
    {
        stock->registerObserver(this, shares, defaultRange);
        stocks_.push_back(stock);
        infos_[stock] = make_tuple(shares, defaultRange);
    }
    else
    {
        stock->updateObserver(this, shares, get<1>(infos_[stock]));
        get<0>(infos_[stock]) += shares;
    }
}

void Investor::changeRange(Subject *stock, double range)
{
    assert(infos_.count(stock));
    stock->updateObserver(this, 0, range);
    get<1>(infos_[stock]) = range;
}

void Investor::sellStock(Subject *stock, int shares)
{
    assert(infos_.count(stock));
    assert(shares < get<0>(infos_[stock]));
    stock->updateObserver(this, -shares, get<1>(infos_[stock]));
    get<0>(infos_[stock]) -= shares;
    if (get<0>(infos_[stock]) == 0)
    {
        stocks_.remove(stock);
        infos_.erase(stock);
    }
}
