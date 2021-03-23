#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include <string>
#include <iostream>

using namespace std;

class Client {

private:
    string firstName;
    string lastName;
    string personalID;
public:
    Client();
    Client(string imie, string nazwisko, string id);
    ~Client();
    string getClientInfo();
    void setFirstName(string);
    void setLastName(string);
    string getFirstName();
    string getLastName();
    string getPersonalID();
};



#endif //CARRENTAL_CLIENT_H
