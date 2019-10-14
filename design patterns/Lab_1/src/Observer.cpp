#include <cassert>
#include "Subject.hpp"
#include "Observer.hpp"

using namespace std;
using namespace design_patterns;

// implement for destructor of Observer
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

void Investor::update(Subject *stock, double range)
{
    // call updateAction_ to do some actions
    updateAction_(this, dynamic_cast<Stock *>(stock), range);
}

void Investor::buyStock(Stock *stock, int shares, double range)
{
    // assert that the number of shares is greater than 0
    assert(shares > 0);
    // if the investor never buys this stock before
    if (!shares_.count(stock))
    {
        // register this investor in the stock firstly
        stock->registerObserver(this);
        // stores the stock and shares
        stocks_.push_back(stock);
        shares_[stock] = shares;
    }
    // else if the investor had bought some shares of this stock
    else
    {
        // update shares of the stock
        shares_[stock] += shares;
    }

    // set the range of this investor
    // if range is greater than zero
    if (range >= 0)
    {
        stock->changeRange(this, range);
    }
    // update shares changed by the investor in the stock
    stock->changeShares(this, shares);
}

void Investor::changeRange(Stock *stock, double range)
{
    // assert this investor has bought the stock
    assert(shares_.count(stock));
    // set the range of this investor in the given stock
    stock->changeRange(this, range);
}

void Investor::sellStock(Stock *stock, int shares)
{
    // assert this investor has bought the stock
    assert(shares_.count(stock));
    // if the number of shares to sell
    // is greater than the shares the investor has
    // make it be the shares the investor contains
    shares = std::min(shares, shares_[stock]);
    // update shares changed
    stock->changeShares(this, -shares);
    shares_[stock] -= shares;
    // delete the stock after selling all shares
    // and remove this investor from the stock
    if (shares_[stock] == 0)
    {
        stocks_.remove(stock);
        shares_.erase(stock);
        stock->removeObserver(this);
    }
}

void Investor::sellStockAll(Stock *stock)
{
    // assert this investor has bought the stock
    assert(shares_.count(stock));
    // just call method sellStock
    sellStock(stock, shares_[stock]);
}
