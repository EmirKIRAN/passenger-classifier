#include "Eskisehir.h"

Eskisehir::Eskisehir(int size):_index(0)
{
    this->size = size;
    this->_city_name = "ESKISEHIR";
}
void Eskisehir::append(Passenger pass)
{
    if(this->_index < this->size)
    {
        this->train.push(pass);
        this->_index++;
    }
    else
        std::cout << "The train is already full !" << std::endl;

}
stack<Passenger> Eskisehir::getTrain()
{
    return this->train;
}
std::string Eskisehir::getCity()
{
    return _city_name;
}
