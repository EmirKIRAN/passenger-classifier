#include "TicketClassifier.h"

TicketClassifier::TicketClassifier(string filePath):filePath(filePath){} // set the file path received from the client.
void TicketClassifier::getInstance() // main function in this class.
{
    // call funcitons
    pushPassenger();
    createCities();
    fillCities();
    writeFile();
}
void TicketClassifier::pushPassenger() // adds to the queue the passengers on the file.
{
    ifstream fileReader(filePath); // file read object created.
    string text; // line read.
    while(getline(fileReader,text)) // loop the read all lines.
    {
        Passenger p = get_passenger(text); // call method.
        this->passengers.push(p); // push to the queue.
    }
    fileReader.close();
}
Passenger TicketClassifier::get_passenger(string message) // this function returns the desired passenger.
{
    std::string delimiter = " "; // splitter argument(Space).
    std::string arr[3];
    int iter=0;
    size_t pos = 0;
    std::string token;
    while ((pos = message.find(delimiter)) != std::string::npos) { // splitting by space.
        token = message.substr(0, pos);
        arr[iter] = token;
        iter++;
        message.erase(0, pos + delimiter.length());
    }
    arr[iter] = message;
    Passenger pass(arr[0],arr[1],arr[2]);
    return pass;
}
void TicketClassifier::createCities() // this function fills in the 'cities' vector.
{
    queue<Passenger> q = this->passengers;  // created a copy queue.
    vector<string> _cities; // a new vector was created to hold cities.
    TrainFactory tf;

    while(!q.empty()) // traverse queue
    {
        _cities.push_back(q.front().getDestination());
        q.pop();
    }
    sort(_cities.begin(),_cities.end()); // sorted vector to find unique values.
    auto last = unique(_cities.begin(),_cities.end()); // finding non-unique values.
    _cities.erase(last,_cities.end()); // deletion of duplicate values.
    for(string c : _cities)
        this->cities.push_back(tf.getTrainObject(c,100)); // The number of passengers can be dynamically assigned.
}
vector<Passenger> TicketClassifier::filter_passengers(string destination) // filter by destination
{
    vector<Passenger> result;
    queue<Passenger> _copy_passengers = this->passengers;
    while (!_copy_passengers.empty()) {
        if(destination == _copy_passengers.front().getDestination())
            result.push_back(_copy_passengers.front());
        _copy_passengers.pop();
    }
    return result;
}
void TicketClassifier::fillCities() // filling cities with relevant passengers.
{
    for(City* c : this->cities)
    {
        vector<Passenger> pass = filter_passengers(c->getCity());
        for(Passenger p : pass)
            c->append(p);
    }
}
void TicketClassifier::writeFile() // create new file named cities
{
    for(City* c : this->cities)
    {
        string city_name = "";
        for(char ch : c->getCity())
            city_name += (char)tolower(ch); // convert a city name to lowercase letters.
        ofstream writer(city_name+".txt"); // create a new file with the name of the city name.
        stack<Passenger> _copy = c->getTrain();
        while(!_copy.empty())
        {
            writer << _copy.top().getName() << " " << _copy.top().getSurname() << " " << _copy.top().getDestination() << std::endl; // writes the passenger to the file.
            _copy.pop();
        }
        writer.close();
    }
}
