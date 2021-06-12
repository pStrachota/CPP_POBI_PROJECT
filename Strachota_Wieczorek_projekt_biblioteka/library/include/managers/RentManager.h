
#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H

#include "typedefs.h"
#include <memory>
#include <vector>
#include <repositories/RentRepository.h>
#include "repositories/Templates.h"
#include <boost/date_time.hpp>
#include "model/Rent.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class RentManager {
    RentRepository currentRents;
    RentRepository archiveRents;
public:
    RentPtr rentRentableItem(const ClientPtr &client, const RentableItemPtr &rentableItem,pt::ptime beginTime);
    void removeRentableItem(RentableItemPtr rentableItem);
    //RentPtr getRentableItemRent(const boost::uuids::uuid rentId);
    RentPtr getRentableItemRent(const RentableItemPtr &rentableItem);
    std::vector<RentPtr> findRents(const RentPredicate& predicate);
    std::vector<RentPtr> getAllClientRents(const ClientPtr &client);

};



#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTMANAGER_H
