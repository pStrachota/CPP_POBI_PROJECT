//
// Created by student on 27.05.2021.
//

#ifndef STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_TEMPLATES_H
#define STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_TEMPLATES_H


#include <memory>
#include <string>
#include <typedefs.h>
#include <vector>

/**
 * @brief klasa szablonowa dla klas
 * @tparam T - typ klasy
 */


template <class T>
class Repository
{
protected:
    std::vector<std::shared_ptr<T>> objects;
public:

    /**
     * @brief dodaj nowy obiekt klasy
     * @param newObject - obiekt okreslonego typu
     */
    void add(std::shared_ptr<T> newObject) {
        if(newObject == nullptr) {}
        else {
            objects.push_back(newObject);
        }
    }
    /**
     * @brief usun obiekt danej klasy
     * @param delObject - obiekt okreslonego typu do usuniecia
     */
    void removeObject(std::shared_ptr<T> delObject) {
        if(delObject == nullptr) {}
        else {
            for(int i = 0; i < objectSize(); i++) {
                if (objects[i] == delObject) {
                    objects.erase(objects.begin()+i);
                }
            }            
        }
    }

    /**
     * @brief "dostan" sie do obiektu o okreslonym indeskie
     * @param index - indeks do wyszukania
     * @return znaleziony obiekt o danym indeksie
     */
    std::shared_ptr<T>getObject(unsigned int index){
        for(int i = 0; i < objects.size(); i++) {
            if(i == index) {
                return objects[index];
            }
        }
        return nullptr;
    }
    /**
     * @brief getReport zwraca informacje o wszystkich obiektach danej klasy
     * @return informacje. typ string
     */
    std::string getReport() {
        std::string result;
        for(int i = 0; i<objects.size(); i++)
        {
            result += objects[i]->getInfo();
            result += "\n";
        }
        return result;
    }

    /**
     * @brief zwraca wielkosc danej klasy - ile obiektow sie w niej znajduje
     * @return usigned int informujacy o liczie obiekow
     */
    const unsigned int objectSize() const {
        return objects.size();
    }

    /**
     * @brief findById wyszukuje na podstawie (zaleznej od klasy) wlasciwosci
     * dla klienta - pesel, dla pojazdu - tablica, dla wypozyczen - id
     * @tparam I
     * @param id
     * @return jeden znaleziony obiekt
     */
    template<class I> std::shared_ptr<T> findById(I id) {
        for (unsigned int i = 0; i < objects.size(); i++) {
            std::shared_ptr<T> object = getObject(i);
            if (object != nullptr && object->getId() == id) {
                return object;
            }
        }
        return nullptr;
    }

};

/**
 * getInfo zwraca informacje o danym obiekcie (jednym)
 * @tparam R - typ klasy
 * @param object - obiekt
 * @return informacje, typ string
 */
template<class R> std::string getInfo(std::shared_ptr<R> object) {
    return object->getInfo();
}
/**
 * getId zwraca informacje o danym obiekcie (jednym), na podstawie jego identyfikatora
 * @tparam R - typ klasy
 * @param object - obiekt
 * @return informacje, typ string
 */
template<class C> std::string getId(std::shared_ptr<C> object) {
    return object->getId();
}







#endif //STRACHOTA_WIECZOREK_PROJEKT_BIBLIOTEKA_TEMPLATES_H
