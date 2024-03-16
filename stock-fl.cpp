// g++ -std=c++11 stock-fl.cpp -o stock-fl

// use map to store key and value
// everytime update the value update the min and max at the same time
#include <iostream>
#include <map>
#include <vector>

class StockPrice
{
    int max;
    
    std::map<int, int> stockMap;

public:
    StockPrice()
    {
        this->max = 0;
    }

    void update(int timestamp, int price)
    {
        stockMap[timestamp] = price;
    }

    int current()
    {
        return stockMap.rbegin()->second;
    }

    int maximum()
    {
        int max = stockMap.begin() -> second;
        for(auto it = stockMap.begin() ;it != stockMap.end(); it++){
         if(it->second > max){
            max = it ->second;
         }
        }
        return max;
    }

    int minimum()
    {
        int min = stockMap.begin() -> second;
        for(auto it = stockMap.begin() ;it != stockMap.end(); it++){
         if(it->second < min){
            min = it ->second;
         }
        }
        return min;
    }
};

int main()
{
    return 0;
}