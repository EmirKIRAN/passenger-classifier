#ifndef TICKETCLASSIFIER_H
#define TICKETCLASSIFIER_H
#include <City.h>
#include <Passenger.h>
#include <TrainFactory.h>
#include <bits/stdc++.h>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cstring>

class TicketClassifier
{
public:
    TicketClassifier(string filePath);
    void getInstance();
private:
    string filePath;
    queue<Passenger> passengers;
    vector<City*> cities;
    void pushPassenger();
    void createCities();
    void fillCities();
    vector<Passenger> filter_passengers(string destination);
    Passenger get_passenger(string message);
    void writeFile();
};

#endif // TICKETCLASSIFIER_H
