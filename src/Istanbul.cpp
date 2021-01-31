#include "Istanbul.h"

Istanbul::Istanbul(int size):_index(0)
{
    this->size = size;
    this->_city_name = "ISTANBUL";
}
void Istanbul::append(Passenger pass)
{
    if(this->_index < this->size)
    {
        this->train.push(pass);
        this->_index++;
    }
    else
        std::cout << "The train is already full !" << std::endl;

}
stack<Passenger> Istanbul::getTrain()
{
    return this->train;
}
std::string Istanbul::getCity()
{
    return _city_name;
}
