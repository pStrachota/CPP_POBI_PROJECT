#include <iostream>
#include "math_helpers.h"
#include "model/Client.h"
#include "model/Address.h"
#include <boost/date_time.hpp>
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
//using namespace std;
#include "model/Moped.h"
#include "repositories/StorageContainer.h"
#include "model/Bicycle.h"

int main() {



    pt::ptime test = pt::ptime(gr::date(2021, 4, 5), pt::hours(9) + pt::minutes(25));
    Address *a = new Address("Garwolin", "nawetfajna", "1503");
    Client *client = new Client("Piotr", "Strachota", "7", a);
    Client *client2 = new Client("Robert", "Maklowicz", "7", a);
    Address b("Garwolin", "nawetfajna", "1503");
    Vehicle *vehicle = new Vehicle("US3333", 345);
    Rent rent(1, client, vehicle, test);
    Rent *r = new Rent(45, client, vehicle, test);





    Moped *mope = new Moped(45, "nnnnnnn", 5678);
    Bicycle *bike = new Bicycle("WT42416", 99);



    VehicleRepository vR;
    vR.addVehicle(mope);
    ClientRepository cR;
    cR.addClient(client);
    RentRepository rR;
    rR.addRent(r);
    StorageContainer testSc(vR, cR, rR);

    std::cout << "All Clients report: " << testSc.getClientRepo().getReport() << std::endl;
    std::cout << "All Rents report: " << testSc.getRentRepo().getReport() << std::endl;
    std::cout << "All Vehicle report: " << testSc.getVehicleRepo().getReport() << std::endl;
    vR.addVehicle(bike);
    cR.addClient(client2);
    std::cout << "All Clients report after add: " << cR.getReport() << std::endl;
    std::cout << "All Vehicle report after add: " << vR.getReport() << std::endl;




    return 0;
}
