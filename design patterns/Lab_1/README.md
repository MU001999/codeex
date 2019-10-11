# Run it

Just type `make` and enter, then type './bin/lab_1' and enter, you will see the output.

## For example

```plain
> make
mkdir bin
g++ -std=c++17 Stock.cpp Observer.cpp Test.cpp -o bin/lab_1
> ./bin/lab_1
Initial...
Tfosorcim's price is 2000
Elgoog's price is 1500
Elppa's price is 1000
Then the stock market is starting to work

XiaoMing buys 100 shares of Tfosorcim
Tfosorcim's price is 2400
Elgoog's price is 1500
Elppa's price is 1000
...
> make clean
rm -rf ./bin
```
