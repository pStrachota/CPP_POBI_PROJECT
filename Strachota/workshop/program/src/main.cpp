#include <iostream>
#include "math_helpers.h"
#include "model/Client.h"

using namespace std;

int main() {

    //cout << factorial(5) << endl;
    Client henryk("henryk", "trombobobob", "NIEtancerz");
    cout << henryk.getClientInfo() << endl;
    Client *d = new Client;
    cout << d->getClientInfo() << endl;
    delete d;
    Client piotr("piotr", "strachota", "tancerz");
    cout << piotr.getClientInfo() << endl;

    cout << piotr.getPersonalID() << endl;

    cout << "00000000000000000000000000000000" << endl;

    henryk.setFirstName("");
    cout << henryk.getClientInfo() << endl;
    Client a;


    return 0;
}
