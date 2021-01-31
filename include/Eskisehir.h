#ifndef ESKISEHIR_H
#define ESKISEHIR_H
#include <City.h>

class Eskisehir : public City
{
public:
    Eskisehir(int size);
    void append(Passenger pass);
    stack<Passenger> getTrain();
    std::string getCity();
private:
    int _index;
};

#endif // ESKISEHIR_H
