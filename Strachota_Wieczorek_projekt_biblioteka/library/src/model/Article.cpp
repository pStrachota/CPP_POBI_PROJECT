
#include "model/Article.h"

Article::Article(const std::string &serialNumber, const std::string &author, const std::string &title,
                 const std::string &parentOrganisation) : RentableItem(serialNumber, author, title) , parentOrganisation(parentOrganisation){}


const std::string & Article::getParentOrganisation() const {
    return parentOrganisation;
}

std::string Article::getRentableItemInfo() const {
    std::string output;
    output =  RentableItem::getRentableItemInfo();
    return output;
}


std::string Article::getArticleInfo() const {
    std::string output;
    output =  Article::getRentableItemInfo() + " parent organisation " + parentOrganisation;
    return output;
}
