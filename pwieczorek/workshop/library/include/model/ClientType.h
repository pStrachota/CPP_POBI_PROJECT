#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H

#include <string>

class ClientType{
private:
public:
    virtual int getMaxVehicles();
    virtual double applyDiscount(int price);
    virtual std::string getTypeInfo() = 0;
    // blad
    //virtual ~ClientType() = 0;
};



#endif //CARRENTAL_CLIENTTYPE_H
