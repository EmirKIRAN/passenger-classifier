#include "Passenger.h"

/**
* Constructor and getter/setter methods.
*/

Passenger::Passenger(){}
Passenger::Passenger(string name,string surname,string destination):name(name),surname(surname),destination(destination){}
string Passenger::getName(){return this->name;}
string Passenger::getSurname(){return this->surname;}
string Passenger::getDestination(){return this->destination;}
void Passenger::setName(string name){this->name = name;}
void Passenger::setSurname(string surname){this->surname = surname;}
void Passenger::setDestination(string destination){this->destination = destination;}
