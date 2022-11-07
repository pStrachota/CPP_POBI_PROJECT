
#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEM_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEM_H

#include <string>
#include <iostream>

/**
 * @brief RentableItem jest to klasa reprezentujaca fizyczny obiekt wypozyczany z biblioteki
 * rentableItem jest przypisany do wypozyczenia Rent
 */

class RentableItem {
private:
    std::string serialNumber;
    std::string author;
    std::string title;
    bool archive = false;
public:
    virtual ~RentableItem();

public:
    RentableItem(const std::string &serialNumber, const std::string &author, const std::string &title);
   
    virtual std::string getInfo() const = 0;
   
    void setArchive(bool archive);
   
    const std::string &getId() const;
   
    const std::string &getAuthor() const;
    
    const std::string &getTitle() const;
    
    bool isArchive() const;
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEM_H
