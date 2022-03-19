#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include <cfloat>
#include "Car.h"

using namespace std;
int main()
{
    auto cars=randomCars();
    cout<<"Cars: "<<cars<< "\n";

    double avgPrice=0,range,minPrice=DBL_MAX,maxPrice=DBL_MIN;
    for(auto c: cars)
    {
        avgPrice+=c.price();
        minPrice=min(minPrice,c.price());
        maxPrice=max(maxPrice,c.price());
    }
    avgPrice/=cars.size();
    range= maxPrice-minPrice;

    cout<<"The average Price is: $"<<avgPrice<< "\n";
    cout<<"The range is: $"<<range<< "\n";
}