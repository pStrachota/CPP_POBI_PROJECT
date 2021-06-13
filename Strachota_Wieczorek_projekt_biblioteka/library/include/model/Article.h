

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_ARTICLE_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_ARTICLE_H

#include "RentableItem.h"

/**
 * @brief klasa Article reprezentuje artykuł naukowy
 * dziedziczy z RentableItem
 */

class Article : public RentableItem {
private:
    std::string parentOrganisation;
public:
    Article(const std::string &serialNumber, const std::string &author, const std::string &title, const std::string &parentOrganisation);
    /**
   * @brief getInfo konkatenuje informacje artykule
   * @return string zawierający informacje o artykule
   */
    std::string getInfo() const override;
    /**
   * @brief getter dla organizacji macierzystej artkykułu
   * @return string zwraza informacje o organizacji
   */
    const std::string &getParentOrganisation() const;

    virtual ~Article();
};



#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_ARTICLE_H
