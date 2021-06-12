
#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_BOOK_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_BOOK_H

#include "RentableItem.h"

class Book : public RentableItem{
private:
    std::string publishingHouse;
public:
    Book(const std::string &serialNumber, const std::string &author, const std::string &title, const std::string &publishingHouse);
    std::string getInfo() const override;
    const std::string &getPublishingHouse() const;
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_BOOK_H
