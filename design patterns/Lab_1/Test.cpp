#include <map>
#include <iomanip>
#include <iostream>
#include "Observer.hpp"
#include "Stock.hpp"

using namespace std;
using namespace design_patterns;

// there are three stocks and their prices on Mondy
#define STOCK(Name, Price) Stock Name(#Name, Price)
    STOCK(Tfosorcim, 2000);
    STOCK(Elgoog,    1500);
    STOCK(Elppa,     1000);
#undef STOCK

// there are three inverstor
#define INVESTOR(Name) Investor Name(#Name)
    INVESTOR(XiaoMing);
    INVESTOR(DaXiong);
    INVESTOR(Michael);
#undef INVESTOR

void showStocks()
{
#define SHOW(Stock) cout << #Stock "'s price is " \
    << Stock.getPrice() << endl

    SHOW(Tfosorcim);
    SHOW(Elgoog);
    SHOW(Elppa);
#undef SHOW
}

// the main control function
int main(int argc, char *argv[])
{
    cout << "Initial..." << endl;
    showStocks();
    cout << "Then the stock market is starting to work" << endl << endl;

#define DEAL(Name, Num, Range, Firm)\
    cout << #Name " buys " #Num " shares of " #Firm << endl;\
    Name.buyStock(&Firm, Num, Range);\
    showStocks();\
    cout << endl

    DEAL(XiaoMing, 100, 0.3,  Tfosorcim);
    DEAL(XiaoMing, 100, 0.1,  Elgoog);
    DEAL(XiaoMing, 100, 0.2,  Elppa);
    DEAL(DaXiong,  40,  0.3,  Elgoog);
    DEAL(DaXiong,  60,  0.2,  Elgoog);
    DEAL(DaXiong,  200, 0.1,  Elppa);
    DEAL(Michael,  300, 0.4,  Elppa);

#undef DEAL

    return 0;
}
