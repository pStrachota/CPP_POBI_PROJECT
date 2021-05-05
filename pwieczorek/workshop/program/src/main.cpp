#include <iostream>
#include "model/Client.h"
#include "model/Address.h"

using namespace std;

int main(int argc,char **argv)
{
    cout << "running main" << endl;

    Address a_x;
    Address* a_wsk1 = &a_x;


    Client *c1 = new Client("pawel", "w","007", a_wsk1);
    Client *c2 = new Client("pawel", "w","007", a_wsk1);

    cout <<  c1->getClientInfo();
    cout <<  c2->getClientInfo();
    return 0;
}
