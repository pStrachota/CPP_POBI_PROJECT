//
// Created by pawel on 05.07.2021.
//
#include "typedefs.h"
#include <vector>
#include <string>

#ifndef CARRENTAL_REPOSITORY_H
#define CARRENTAL_REPOSITORY_H

template<class T> class Repository{
protected:
    std::vector<std::shared_ptr<T>> objects;
public:

void add(std::shared_ptr<T> object){
    if (object != nullptr) objects.push_back(object);
}

void remove(std::shared_ptr<T> object){
    for (int i = 0; i<objects.size();i++){
        if (objects[i] == object) objects.erase(objects.begin()+i);
    }
}

std::shared_ptr<T> get(unsigned int index) const{
    if (index < objects.size()) return objects[index];
    else return nullptr;
}

unsigned int getSize() const{
    return objects.size();
}

std::string getRaport() const{
    std::string output;
    for (int i = 0;i<objects.size();i++){
        output += objects[i]->getInfo();
    }
    return output;
}

    template<class I> std::shared_ptr<T> findById(I id) const {
        for (unsigned int i = 0; i < getSize(); i++) {
            std::shared_ptr<T> object = get(i);
            if (object != nullptr && object->getId() == id) {
                return object;
            }
        }
        return nullptr;
    }


};


#endif //CARRENTAL_REPOSITORY_H
