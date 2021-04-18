//
// Created by student on 13.03.2021.
//

#include <iostream>
#include "model/Client.h"

using namespace std;

int main(int argc,char **argv)
{
    cout << "test obiektów:" << endl;
    Client c1("Pawel","Kowalski","7770777");
    Client c2("Gawel","Kowalski","7770777");

    Client *wskC = new Client;
    wskC = &c2;

    cout << wskC->getClientInfo() << endl;
    cout << c1.getClientInfo() << endl;

    c1.setFirstName("");
    c1.setFirstName("NoweImiePawla");
    cout << c1.getClientInfo();
    return 0;
}
