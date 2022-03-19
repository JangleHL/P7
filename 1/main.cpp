#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

using namespace std;
bool compCars(const Car &c1,const Car &c2)
{
    return c1.price() >= c2.price();
}
int main()
{
    auto cars=randomCars();
    cout<<"Initial: "<<cars<< "\n";
    sort(cars.begin(),cars.end(),compCars);
    cout<<"Reversed: "<<cars<< "\n";
}