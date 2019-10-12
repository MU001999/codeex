# Run it

Just type `make` and enter, then type './bin/lab_1' and enter, you will see the output.

## For example

```plain
> make
mkdir bin
g++ -std=c++17 src/Stock.cpp src/Observer.cpp src/Test.cpp -o bin/lab_1
> ./bin/lab_1
Tfosorcim's price is 2000
Then the stock market is starting to work
XiaoMin buys 80 shares of Tfosorcim
DaXiong buys 60 shares of Tfosorcim
Michael buys 40 shares of Tfosorcim

This is Round 1!
        My name is XiaoMin. The stock of Tfosorcim is up 20%. I'm goint to sell 20 shares because I don't like to earn much money although I believe that it will keep going up :)
        My name is DaXiong. The stock of Tfosorcim is up 20%. I'm goint to sell 20 shares because I don't like to earn much money although I believe that it will keep going up :)
Tfosorcim's price is 2400
...
> make clean
rm -rf ./bin
```
