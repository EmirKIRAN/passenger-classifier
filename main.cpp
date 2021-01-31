#include <iostream>
#include <TicketClassifier.h>

/**
 * @file ExampleClass.cc
 *
 * @brief In this project, passenger classifier has been made.
 *
 * @author Emirhan KIRAN
 * Contact: linkedin.com/in/emir-kiran/
 *
 * @note You can access other file from folders.
 */

using namespace std;


int main()
{
    TicketClassifier tc("passengerList.txt"); // here it is sufficient to simply indicate the location of the file containing passengers' information.
    tc.getInstance(); // this method that creates files.
}
