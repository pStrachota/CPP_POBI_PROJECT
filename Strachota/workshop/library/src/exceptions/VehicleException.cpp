#include "exceptions/VehicleException.h"

VehicleException::VehicleException(const std::string& arg) : logic_error(arg)
{
}

const std::string VehicleException::exceptionPrice = "INVALID PRICE";
const std::string VehicleException::exceptionRegistration = "INVALID REGISTRATION NUMBER";

