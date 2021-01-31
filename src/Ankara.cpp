#include "Ankara.h"

Ankara::Ankara(int size):_index(0)
{
    this->size = size;
    this->_city_name = "ANKARA";
}
void Ankara::append(Passenger pass)
{
    if(this->_index < this->size)
    {
        this->train.push(pass);
        this->_index++;
    }
    else
        std::cout << "The train is already full !" << std::endl;

}
stack<Passenger> Ankara::getTrain()
{
    return this->train;
}
std::string Ankara::getCity()
{
    return _city_name;
}
