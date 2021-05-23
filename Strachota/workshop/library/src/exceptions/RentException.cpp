#include "exceptions/RentException.h"

RentException::RentException(const std::string& arg) : logic_error(arg)
{}

const std::string RentException::exceptionClientNullPtr = "INVALID CLIENT (NULL)";
const std::string RentException::exceptionVehicleNullPtr = "INVALID VEHICLE (NULL)";
const std::string RentException::exceptionDays = "INVALID NUMBER OF DAYS TO SUBSTRACT (NEGATIVE VALUE)";

