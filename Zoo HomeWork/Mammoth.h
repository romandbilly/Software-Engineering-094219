//
// Created by nastia on 6/17/2019.
//

#ifndef HW3_MAMMOTH_H
#define HW3_MAMMOTH_H
#include "Proboscidea.h"

class Mammoth : public Proboscidea  {

private:
    Mammoth(const Mammoth& mammoth){};
    const Mammoth& operator = (const Mammoth& mammoth){};


public:
    /**
    * create a new Mammoth with a given name and a gender, that has a pointer to its
    * parents
    *
    * @param motherPtr Animal*: a pointer to the animal mother
    * @param fatherPtr Animal*: a pointer to the animal father
    * @param animalName string: the name of the newborn
    * @param animalGender Gender: the gender of the newborn
    */
    Mammoth(Animal* motherPtr, Animal* fatherPtr,const string& animalName,
            Gender animalGender);
    /**
    * destructor
    */
    virtual ~Mammoth(){};
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


#endif //HW3_MAMMOTH_H
