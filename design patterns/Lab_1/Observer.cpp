#include <cassert>
#include <iomanip>
#include <iostream>
#include "Observer.hpp"
#include "Stock.hpp"

using namespace std;
using namespace design_patterns;

Observer::~Observer() {}

void Investor::update(Stock* stock, double range)
{
    if (range < 0)
    {
        cout << "The stock named " << stock->getName() << " "
        "fell " << setprecision(2) << -range * 100 << "%." << endl;

        cout << "I'm going to buy more 100 shares, "
        "or rather I've been trapped :(" << endl;

        buyStock(stock, 100);
    }
    else if (range == 0)
    {
        cout << "The stock named " << stock->getName() << " "
        "is realy a bad stock for me because it is unchanged, "
        "so I will sell all the shares :(" << endl;

        sellStockAll(stock);
    }
    else
    {
        cout << "I'm goint to sell 10 shares "
        "because I don't like to earn much money "
        "although I believe that it will keep going up :)" << endl;

        sellStock(stock, 10);
    }
}

void Investor::buyStock(Stock *stock, int shares)
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

void Investor::changeRange(Stock *stock, double range)
{
    assert(infos_.count(stock));
    stock->updateObserver(this, 0, range);
    get<1>(infos_[stock]) = range;
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
