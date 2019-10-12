#include <map>
#include <iomanip>
#include <iostream>
#include "Observer.hpp"
#include "Stock.hpp"

using namespace std;
using namespace design_patterns;

Stock Tfosorcim("Tfosorcim", 2000);

// there are three inverstor
Investor XiaoMin("XiaoMin"),
         DaXiong("DaXiong"),
         Michael("Michael");

void showStock()
{
    cout << "Tfosorcim's price is " \
    << Tfosorcim.getPrice() << endl;
}

void roll(int num)
{
    cout << "This is Roll " << num << "!" << endl;
    Tfosorcim.nextRoll();
    showStock();
    cout << endl;
}

// the main control function
int main(int argc, char *argv[])
{
#define DEAL(Name, Num, Range)\
    cout << #Name " buys " #Num " shares of Tfosorcim" << endl;\
    Name.buyStock(&Tfosorcim, Num, Range)

    showStock();
    cout << "Then the stock market is starting to work" << endl;
    DEAL(XiaoMin, 80, 0.1);
    DEAL(DaXiong, 60, 0.2);
    DEAL(Michael, 40, 0.3);
    cout << endl;

    for (int i = 1; i <= 10; ++i)
    {
        roll(i);
    }

    return 0;
}
