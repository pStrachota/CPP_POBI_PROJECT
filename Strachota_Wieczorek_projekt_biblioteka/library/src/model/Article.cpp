
#include "model/Article.h"

Article::Article(const std::string &serialNumber, const std::string &author, const std::string &title,
                 const std::string &parentOrganisation) : RentableItem(serialNumber, author, title) , parentOrganisation(parentOrganisation){}


const std::string & Article::getParentOrganisation() const {
    return parentOrganisation;
}

std::string Article::getInfo() const {
    std::string output;
    output = RentableItem::getInfo() + " parent organisation " + parentOrganisation;
    return output;
}


