#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H

#include <string>
#include <iostream>

class ClientType
{
public:
    virtual double applyDiscount(int);
    virtual int getMaxVehicles();
    //virtual ~ClientType()= default;
    virtual std::string getTypeInfo();
};



#endif //CARRENTAL_CLIENTTYPE_H
