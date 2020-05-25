//
// Created by nastia on 6/17/2019.
//

#ifndef HW3_ELEPHANT_H
#define HW3_ELEPHANT_H
#include "Proboscidea.h"

class Elephant: public Proboscidea {

private:
    Elephant(const Elephant& elephant){};
    const Elephant& operator = (const Elephant& elephant){};


public:
    /**
    * create a new Elephant with a given name and a gender, that has a pointer to its
    * parents
    *
    * @param motherPtr Animal*: a pointer to the animal mother
    * @param fatherPtr Animal*: a pointer to the animal father
    * @param animalName string: the name of the newborn
    * @param animalGender Gender: the gender of the newborn
    */
    Elephant(Animal* motherPtr, Animal* fatherPtr,const string& animalName, Gender
    animalGender);
    /**
    * destructor
    */
    virtual ~Elephant(){};

    /**
    * @param motherPtr Animal*: a pointer to the animal mother
    * @param fatherPtr Animal*: a pointer to the animal father
    * @param animalName string: the name of the newborn
    * @param animalGender Gender: the gender of the newborn
    * @return pointer to the new creature
    */
    virtual Animal* createNewAnimal(const string &descendantName, Gender
                                   decendantGender, Animal *mother, Animal *father) const;

};

#endif //HW3_ELEPHANT_H
