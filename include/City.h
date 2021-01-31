#ifndef CITY_H
#define CITY_H
#include <bits/stdc++.h>
#include <Passenger.h>


class City
{
public:
    virtual void append(Passenger pass) = 0;
    virtual stack<Passenger> getTrain() = 0;
    virtual std::string getCity() = 0;
protected:
    int size;
    std::string _city_name;
    stack<Passenger> train;
};

#endif // CITY_H
