#ifndef ANKARA_H
#define ANKARA_H
#include <City.h>


class Ankara : public City
{
public:
    Ankara(int size);
    void append(Passenger pass);
    stack<Passenger> getTrain();
    std::string getCity();
private:
    int _index;
};

#endif // ANKARA_H
