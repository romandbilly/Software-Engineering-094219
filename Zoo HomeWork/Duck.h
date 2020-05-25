

#ifndef HW3_DUCK_H
#define HW3_DUCK_H
#include "Animal.h"

class Duck : public Animal{

private:
    static const string _SOUND;
    static const size_t DUCK_MATURE_AGE;
    static const string DUCK_SOUND;

    Duck(const Duck &duck){};
    const Duck &operator=(const Duck &duck){};


public:
    /**
    * create a new Duck with a given name and a gender, that has a pointer to its
    * parents
    *
    * @param motherPtr Animal*: a pointer to the animal mother
    * @param fatherPtr Animal*: a pointer to the animal father
    * @param animalName string: the name of the newborn
    * @param animalGender Gender: the gender of the newborn
    */
    Duck(Animal *motherPtr, Animal *fatherPtr, const string &animalName, Gender
         animalGender);
    /**
    * destructor
    */
    virtual ~Duck(){}
    /**
    * print the Duck sound
    */
    virtual void makeSound() const;
    /**
    * raise the age of Duck by 1 and change isAdult to true if the age is higher
    * then mature age of Duck
    */
    virtual void grow();
    /**
    * @param motherPtr Animal*: a pointer to the animal mother
    * @param fatherPtr Animal*: a pointer to the animal father
    * @param animalName string: the name of the newborn
    * @param animalGender Gender: the gender of the newborn
    * @return pointer to the new creature
    */
    virtual Animal* createNewAnimal(const string &descendantName, Gender decendantGender,
            Animal *mother, Animal *father) const;

};

#endif //HW3_DUCK_H
