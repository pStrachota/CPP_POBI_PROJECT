

#include "model/Rent.h"

Rent::Rent(pt::ptime rentBeginTime, ClientPtr client, RentableItemPtr rentableItem) : client(client), rentableItem(rentableItem) {
    if(rentBeginTime == pt::not_a_date_time) beginTime = pt::second_clock::local_time();
    else beginTime = rentBeginTime;

    boost::uuids::random_generator generator;
    this->RentId = generator();
}

