#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "repositories/StorageContainer.h"

using namespace std;

int main(int argc,char **argv)
{
    cout << "running main" << endl;

    Address a_x;
    Address* a_wsk1 = &a_x;

    ClientPtr c1 = new Client("pawel", "nowak","127", a_wsk1);
    ClientPtr c2 = new Client("jan", "tomaszewski","337", a_wsk1);
    ClientPtr c3 = new Client("adam", "kowalski","777", a_wsk1);

    VehiclePtr v1 = new Vehicle("ABC",1);
    VehiclePtr v2 = new Vehicle("XYZ",2);
    VehiclePtr v3 = new Vehicle("EPA",3);

    pt::ptime date1 = pt::ptime(gr::date(2015,5,13),pt::hours(9)+pt::minutes(25));

    RentPtr r1 = new Rent(1,c1,v2,date1);

    ClientRepository cRep;
    RentRepository rRep;
    VehicleRepository vRep;

    StorageContainer sCont(vRep,cRep,rRep);

    sCont.getClientRep().addClient(c2);
    sCont.getClientRep().addClient(c1);
    sCont.getClientRep().addClient(c3);

    sCont.getVehicleRep().addVehicle(v1);
    sCont.getVehicleRep().addVehicle(v2);
    sCont.getVehicleRep().addVehicle(v3);

    sCont.getRentRep().addRent(r1);

    cout << sCont.getVehicleRep().getReport() << endl;
    cout << sCont.getRentRep().getReport() << endl;
    cout << sCont.getClientRep().getReport() << endl;

    return 0;
}
