#include "TrainFactory.h"
#include <Ankara.h>
#include <Istanbul.h>
#include <Eskisehir.h>

TrainFactory::TrainFactory(){} // constructor method implementation.that is empties method.
City* TrainFactory::getTrainObject(string cityName,int size)
{
    /**
    * The 'cityName' variable represent the destination.
    * The 'size' variable represent the capacity of the train.
    */

    if(cityName == "ANKARA")
    {
        train = new Ankara(size); // if the cityName equals to 'ANKARA', a new Ankara object is created.
        return train;
    }
    else if(cityName == "ESKISEHIR") // if the cityName equals to 'ESKISEHIR', a new Eskisehir object is created.
    {
        train = new Eskisehir(size);
        return train;
    }
    else // if the cityName equals to 'ISTANBUL', a new Istanbul object is created.
    {
        train = new Istanbul(size);
        return train;
    }
}
