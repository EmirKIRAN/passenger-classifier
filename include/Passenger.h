#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>

using namespace std;

class Passenger
{
private:
    string name;
    string surname;
    string destination;
public:
    Passenger();
    Passenger(string name,string surname,string destination);
    string getName();
    string getSurname();
    string getDestination();
    void setName(string name);
    void setSurname(string surname);
    void setDestination(string destination);
};

#endif // PASSENGER_H
