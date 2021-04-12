#include <iostream>
#include "math_helpers.h"
#include "model/Client.h"
#include "model/Address.h"
#include <boost/date_time.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;

int main() {


    pt::ptime test = pt::ptime(gr::date(2021,4,5), pt::hours(9)+pt::minutes(25));
    Address *a = new Address("Garwolin", "nawetfajna", "1503");
    Client *client = new Client("Piotr", "Strachota", "7", a);
    Address b("Garwolin", "nawetfajna", "1503");
    Vehicle *vehicle = new Vehicle("US3333", 345);
    Rent rent(1555, client, vehicle, test);



    std::cout << "cena za wypozyczenie przed zmiana: " << rent.getRentCost() << std::endl;
    unsigned int proba = rent.getRentCost();
    vehicle->setBasePrice(1);
    std::cout << "cena za wypozycznie po zmianie: " << rent.getRentCost() << std::endl;
    std::cout << rent.getRentInfo() << std::endl;




    return 0;
}
