#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include "Utility.h"
#include "Car.h"

using namespace std;
template <typename T>
class Tag {
public:
    Tag(bool isTagged, T value) : _tagged{ isTagged }, _value{ value } {}

    bool isTagged() const { return _tagged; }
    T item() const { return _value; }

private:
    bool _tagged;
    T _value;
};

template <typename T>
ostream& operator<<(ostream& out, const Tag<T>& tag) {
    out << "TAG: tagged(" << (tag.isTagged() ? "true" : "false") << "), item(" << tag.item() << ")";
    return out;
}

int main() 
{
    auto cars = randomCars();
    cout << "Cars: " << cars << "\n";

    vector<Tag<Car>> taggedCars;
    for(auto c: cars)
    {
        string _vin=c.vin();
        bool isTagged=false;
        if(c.price()<10000 || (_vin[0]>= 'A' && _vin[0] <= 'F'))
        {
            isTagged=true;
        }

        Tag<Car> tagCar(isTagged,c);
        taggedCars.push_back(tagCar);
    }
    cout << "Tagged Cars: " << taggedCars << "\n";
}