#include <model/MotorVehicle.h>

MotorVehicle::MotorVehicle(const int &capacity, const std::string &platenumber, const unsigned int &baseprice) : engineDisplacement(capacity), Vehicle(platenumber, baseprice) {}

double MotorVehicle::getActualRentalPrice() {
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

MotorVehicle::~MotorVehicle() {}

std::string MotorVehicle::getVehicleInfo() {
    std::string chain;
    chain = Vehicle::getVehicleInfo() + " " + std::to_string(engineDisplacement);
    return chain;
}

