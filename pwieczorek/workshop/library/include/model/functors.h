#ifndef CARRENTAL_FUNCTORS_H
#define CARRENTAL_FUNCTORS_H

#include "typedefs.h"
#include <boost/regex.hpp>

class IdPredicate{
    int id;

public:
    IdPredicate(int id) : id(id) {}

    bool operator()(const RentPtr &ptr) const
    {
        return ptr->getId() == id;
    }
};

class FirstNamePredicate{
private:
    std::regex comparison;
public:
    FirstNamePredicate(std::regex comparison) : comparison(comparison) {}

    bool operator()( ClientPtr &client)
    {
        return (regex_match(client->getFirstName(), comparison));
    }
};

class LastNamePredicate{
    std::regex comparison;
public:
    LastNamePredicate(std::regex comparison) : comparison(comparison) {}

    bool operator()( ClientPtr &client)
    {
        return (regex_match(client->getLastName(),comparison));
    }
};



#endif //CARRENTAL_FUNCTORS_H
