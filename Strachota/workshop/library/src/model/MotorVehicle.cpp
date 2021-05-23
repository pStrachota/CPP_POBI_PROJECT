#include <model/MotorVehicle.h>

MotorVehicle::MotorVehicle(const int &engineDisplacement, const std::string &platenumber, const unsigned int &baseprice) : engineDisplacement(engineDisplacement), Vehicle(platenumber, baseprice) {}

double MotorVehicle::getActualRentalPrice() const {
    float wage = 0;
    float price;
    if (engineDisplacement < 1000)
    {
        wage = 1;
    }
    else if (engineDisplacement >= 1000 and engineDisplacement < 2000)
    {
        float base = 1000;
        float multip = 0.5;
        wage = static_cast<double>(engineDisplacement - base) / base;
        wage *= multip;
        float add = 1;
        wage += add;
    }
    else if (engineDisplacement >= 2000)
    {
        wage = 1.5;
    }
    price = wage * getBasePrice();
    return price;
}


std::string MotorVehicle::getInfo() const {
    std::string chain;
    chain = Vehicle::getInfo() + " " + std::to_string(engineDisplacement);
    return chain;
}


