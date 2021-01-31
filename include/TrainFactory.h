#ifndef TRAINFACTORY_H
#define TRAINFACTORY_H
#include <City.h>

class TrainFactory // factory design pattern object creation class.
{
public:
    TrainFactory(); // constructor.
    City* getTrainObject(string cityName,int size); // creates a city object by cityName value.
private:
    City* train; // reference object.
};

#endif // TRAINFACTORY_H
