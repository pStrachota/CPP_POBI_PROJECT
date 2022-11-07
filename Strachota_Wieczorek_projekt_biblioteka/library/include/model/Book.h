
#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_BOOK_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_BOOK_H

#include "RentableItem.h"

/**
 * @brief klasa Book reprezentuje ksiazke
 * dziedziczy z RentableItem
 */

class Book : public RentableItem{
private:
public:
    virtual ~Book();

private:
    std::string publishingHouse;
public:
    Book(const std::string &serialNumber, const std::string &author, const std::string &title, const std::string &publishingHouse);
   
    std::string getInfo() const override;
    
    const std::string &getPublishingHouse() const;
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_BOOK_H
