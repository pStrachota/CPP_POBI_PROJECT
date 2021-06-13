
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
    /**
    * @brief getter informacji o wypozyczeniu
    * @return string
    */
    virtual std::string getInfo() const = 0;
    /**
    * @brief setter dla "bycia w archiwum"
    * @param archive
    */
    void setArchive(bool archive);
    /**
    * @brief getter ID przedmiotu
    * @return string
    */
    const std::string &getId() const;
    /**
    * @brief getter autora przedmiotu
    * @return string
    */
    const std::string &getAuthor() const;
    /**
    * @brief getter tytułu przedmiotu
    * @return string
    */
    const std::string &getTitle() const;
    /**
    * @brief flaga czy zarchiwizowane
    * @return bool
    */
    bool isArchive() const;
};


#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_RENTABLEITEM_H
