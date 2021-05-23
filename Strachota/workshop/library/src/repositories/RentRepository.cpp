#include <repositories/RentRepository.h>


/*
std::vector <RentPtr> RentRepository::findBy(RentPredicate predicate) {

    std::vector<RentPtr> fonde;
    for(auto & currentRent : objects) {
        if(currentRent != nullptr && predicate(currentRent)) {
            fonde.push_back(currentRent);
        }
    }
    return fonde;
    /*
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < objects.size(); i++) {
        RentPtr rent = getRent(i);
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;

}

std::vector<RentPtr> RentRepository::findAll() {
    std::vector<RentPtr> found;
    for(auto & currentRent : objects) {
        if(currentRent != nullptr) {
            found.push_back(currentRent);
        }
    }
    /*
    for (unsigned int i = 0; i < objects.size(); i++) {
        RentPtr rent = getRent(i);
        if (rent != nullptr) {
            found.push_back(rent);
        }
    }
     */
   //return found;
//}

/*
RentPtr RentRepository::findById(std::string id) {

    if (objects.empty()) {
        return nullptr;
    } else {
        for (auto & currentRents : objects) {
            std::string s = boost::lexical_cast<std::string>(currentRents->getId());
            if(s == id) {
                return currentRents;
            }
        }
    }
    return nullptr;
}

*/
std::vector<RentPtr> RentRepository::findByPredicate(const RentPredicate& predicate) {
    {
        std::vector<RentPtr> result;
        for(int i = 0; i<objects.size(); ++i)
        {
            RentPtr rent = objects[i];
            if(predicate(rent))
            {
                result.push_back(rent);
            }
        }
        return result;
    }
}



std::vector<RentPtr> RentRepository::findAllRents() {

    std::vector<RentPtr> result;
    for(int i = 0; i<objects.size(); ++i)
    {
        {
            result.push_back(objects[i]);
        }
    }
    return result;
};
