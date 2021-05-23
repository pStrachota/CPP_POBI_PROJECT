//
// Created by student on 21.05.2021.
//

#ifndef CARRENTAL_FUNCTORS_H
#define CARRENTAL_FUNCTORS_H
#include <regex>
#include "typedefs.h"

/**
 * @brief functors.h to plik, gdzie w jednym miejscu zgromadzone sa klasy funktorow
 */

class FirstNamePredicate
{
private:
    std::regex match;
public:
    FirstNamePredicate(std::regex rmatch) : match(rmatch) {}

    bool operator()(ClientPtr &ptr)
    {
        return (regex_match(ptr->getFirstName(), match));
    }
};

class LastNamePredicate
{
private:
    std::regex match;
public:
    LastNamePredicate(std::regex bmatch) : match(bmatch) {}

    bool operator()(ClientPtr &ptr)
    {
        return (regex_match(ptr->getLastName(), match));
    }
};


class IdPredicate
{
private:
    std::string id;

public:
    IdPredicate(std::string id) : id(id) {}

    bool operator()(ClientPtr &ptr)
    {
        return ptr->getId() == id;
    }
};









#endif //CARRENTAL_FUNCTORS_H
