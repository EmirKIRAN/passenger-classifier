#ifndef ISTANBUL_H
#define ISTANBUL_H
#include <City.h>


class Istanbul : public City
{
public:
    Istanbul(int size);
    void append(Passenger pass);
    stack<Passenger> getTrain();
    std::string getCity();
private:
    int _index;
};

#endif // ISTANBUL_H
