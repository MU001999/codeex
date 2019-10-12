#include <cassert>
#include "Stock.hpp"
#include "Observer.hpp"

using namespace std;
using namespace design_patterns;

Observer::~Observer() {}

Investor::Investor(string name, ActionType &&action)
  : name_(move(name)), updateAction_(move(action)) {}

string Investor::getName() const
{
    return name_;
}

void Investor::setUpdateAction(ActionType &&action)
{
    updateAction_ = move(action);
}

void Investor::update(Stock *stock, double range)
{
    updateAction_(this, stock, range);
}

void Investor::buyStock(Stock *stock, int shares, double range)
{
    assert(shares > 0);
    if (!shares_.count(stock))
    {
        stock->registerObserver(this);
        stocks_.push_back(stock);
        shares_[stock] = shares;
    }
    else
    {
        shares_[stock] += shares;
    }

    if (range >= 0)
    {
        stock->changeRange(this, range);
    }
    stock->changeShares(this, shares);
}

void Investor::changeRange(Stock *stock, double range)
{
    assert(shares_.count(stock));
    stock->changeRange(this, range);
}

void Investor::sellStock(Stock *stock, int shares)
{
    assert(shares_.count(stock));
    shares = std::min(shares, shares_[stock]);
    stock->changeShares(this, -shares);
    shares_[stock] -= shares;
    if (shares_[stock] == 0)
    {
        stocks_.remove(stock);
        shares_.erase(stock);
    }
}

void Investor::sellStockAll(Stock *stock)
{
    assert(shares_.count(stock));
    sellStock(stock, shares_[stock]);
}
