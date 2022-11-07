//
// Created by student on 12.06.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_FUNCTORPREDICATES_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_FUNCTORPREDICATES_H

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
        return (regex_match(ptr->getName(), match));
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
        return (regex_match(ptr->getSurname(), match));
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

#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_FUNCTORPREDICATES_H
