#include <string>
#include "model/Client.h"

using namespace std;

Client::Client() {
    firstName = "exampleFirstName";
    lastName = "exampleLastName";
    personalID = "example personalID";
}


Client::Client(string imie, string nazwisko, string id) : firstName(imie), lastName(nazwisko), personalID(id) {}


Client::~Client() {}


string Client::getClientInfo() {
    string chain;
    chain = firstName + " " + lastName + " " + personalID;
    return chain;
}

void Client::setFirstName(string newFirstName) {
    if(newFirstName == "") {
        cout << "invalid output given to firstName!" << endl;
    } else {
        firstName = newFirstName;
    }
}

void Client::setLastName(string newLastName) {
    if(newLastName == "") {
        cout << "invalid output given to lastName!" << endl;
    } else {
        lastName = newLastName;
    }
}

string Client::getFirstName() {
    return firstName;
}

string Client::getLastName() {
    return lastName;
}

string Client::getPersonalID() {
    return personalID;
}