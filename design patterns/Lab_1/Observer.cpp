#include <cassert>
#include <iomanip>
#include <iostream>
#include "Observer.hpp"
#include "Stock.hpp"

using namespace std;
using namespace design_patterns;

Observer::~Observer() {}

Investor::Investor(string name)
  : name_(move(name)) {}

string Investor::getName() const
{
    return name_;
}

void Investor::update(Stock* stock, double range)
{
    cout << "\tMy name is " << name_ << endl;
    if (range < 0)
    {
        cout << "\tThe stock of " << stock->getName() << " "
            "fell " << setprecision(2) << -range * 100 << "%." << endl;

        cout << "\tI'm going to buy more 100 shares, "
            "or rather I've been trapped :(" << endl;

        buyStock(stock, 100);
    }
    else if (range == 0)
    {
        cout << "\tThe stock of " << stock->getName() << " "
            "is realy a bad stock for me because it is unchanged, "
            "so I will sell all the shares :(" << endl;

        sellStockAll(stock);
    }
    else
    {
        cout << "\tThe stock of " << stock->getName() << " "
            "is up " << setprecision(2) << range * 100 << "%." << endl;

        cout << "\tI'm goint to sell 10 shares "
            "because I don't like to earn much money "
            "although I believe that it will keep going up :)" << endl;

        sellStock(stock, 10);
    }
}

void Investor::buyStock(Stock *stock, int shares, double range)
{
    assert(shares > 0);
    if (!infos_.count(stock))
    {
        range = (range < 0) ? DefaultRange : range;
        stocks_.push_back(stock);
        infos_[stock] = make_tuple(shares, range);
        stock->registerObserver(this, shares, range);
    }
    else
    {
        get<0>(infos_[stock]) += shares;
        stock->updateObserver(this, shares, (range < 0) ? get<1>(infos_[stock]) : range);
    }
}

void Investor::changeRange(Stock *stock, double range)
{
    assert(infos_.count(stock));
    get<1>(infos_[stock]) = range;
    stock->updateObserver(this, 0, range);
}

void Investor::sellStock(Stock *stock, int shares)
{
    assert(infos_.count(stock));
    shares = std::min(shares, get<0>(infos_[stock]));
    stock->updateObserver(this, -shares, get<1>(infos_[stock]));
    get<0>(infos_[stock]) -= shares;
    if (get<0>(infos_[stock]) == 0)
    {
        stocks_.remove(stock);
        infos_.erase(stock);
    }
}

void Investor::sellStockAll(Stock *stock)
{
    assert(infos_.count(stock));
    sellStock(stock, get<0>(infos_[stock]));
}
