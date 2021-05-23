#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H

#include <string>

class ClientType{
private:
public:
    virtual int getMaxVehicles();
    virtual double applyDiscount( int );
    virtual std::string getTypeInfo();
    virtual ~ClientType() = 0;
};



#endif //CARRENTAL_CLIENTTYPE_H
