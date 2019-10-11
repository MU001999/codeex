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

        cout << "\tI've been trapped :(" << endl;

        int choice, shares;
        cout << "Tell me what's your opinion, "
            "1 for buying, 2 for selling and "
            "3 for doing nothing:" << endl;
        cin >> choice;
        cout << "Then tell me how many shares you want:" << endl;
        cin >> shares;

        if (choice != 3)
        {
            (choice == 1) ? buyStock(stock, shares) : sellStock(stock, shares);
        }
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

        cout << "\tI'm goint to sell 20 shares "
            "because I don't like to earn much money "
            "although I believe that it will keep going up :)" << endl;

        sellStock(stock, 20);
    }
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

    if (range > 0)
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
    stock->changeRange(this, -shares);
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
