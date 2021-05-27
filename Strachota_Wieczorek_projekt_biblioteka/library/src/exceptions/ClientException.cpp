#include "exceptions/ClientException.h"

ClientException::ClientException(const std::string &arg) : logic_error(arg)
{}

const std::string ClientException::exceptionFirstName = "INVALID FIRST NAME";
const std::string ClientException::exceptionLastName = "INVALID LAST NAME";
const std::string ClientException::exceptionPersonalID = "INVALID PERSONAL ID";
const std::string ClientException::exceptionAddress = "INVALID ADDRESS";
const std::string ClientException::exceptionClientType = "INVALID CLIENT TYPE";
