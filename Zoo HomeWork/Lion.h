//
// Created by nastia on 6/17/2019.
//

#ifndef HW3_LION_H
#define HW3_LION_H


#include "Animal.h"

class Lion :  Animal {

private:
    static const string _SOUND;
    static const size_t LION_MATURE_AGE;
    static const string LION_SOUND;
    Lion(const Lion& lion){};
    const Lion& operator = (const Lion& lion){};


public:
    /**
    * create a new Lion with a given name and a gender, that has a pointer to its
    * parents
    *
    * @param motherPtr Animal*: a pointer to the animal mother
    * @param fatherPtr Animal*: a pointer to the animal father
    * @param animalName string: the name of the newborn
    * @param animalGender Gender: the gender of the newborn
    */
    Lion(Animal* motherPtr, Animal* fatherPtr, const string& animalName, Gender
         animalGender);
    /**
    * destructor
    */
    virtual ~Lion(){}
    /**
    * print the Lion sound
    */
    virtual void makeSound() const;
    /**
    * raise the age of Lion by 1 and change isAdult to true if the age is higher
    * then mature age of Lion
    */
    virtual void grow();
    /**
    * @param motherPtr Animal*: a pointer to the animal mother
    * @param fatherPtr Animal*: a pointer to the animal father
    * @param animalName string: the name of the newborn
    * @param animalGender Gender: the gender of the newborn
    * @return pointer to the new creature
    */
    virtual Animal *createNewAnimal(const string &descendantName, Gender decendantGender,
                                    Animal *mother, Animal *father) const;

};


#endif //HW3_LION_H
