
#ifndef HW3_PROBOSCIDEA_H
#define HW3_PROBOSCIDEA_H
#include "Animal.h"

class Proboscidea: public Animal {

private:
    static const string PROBOSCIDEA_SOUND;
    static const size_t _proboscideaMatureAge;
    static const string _SOUND;
    Proboscidea(const Proboscidea& proboscidea){};
    const Proboscidea& operator = (const Proboscidea& proboscidea){};


protected:
    Proboscidea(){};


public:
    /**
   * create a new Proboscidea with a given name and a gender, that has a pointer to its
   * parents
   *
   * Proboscidea is abstract class
   *
   * @param motherPtr Animal*: a pointer to the animal mother
   * @param fatherPtr Animal*: a pointer to the animal father
   * @param animalName string: the name of the newborn
   * @param animalGender Gender: the gender of the newborn
   * @param animalType animalType: the type of Proboscidea
   */
    Proboscidea(Animal* motherPtr, Animal* fatherPtr, const string& animalName, Gender
                animalGender, AnimalType animalType);
    /**
     * destructor
     */
    virtual ~Proboscidea(){}
    /**
     * print the SOUND of the Animal
     */
    virtual void makeSound() const;
    /**
     * raise the age of animal by 1 and change isAdult to true if the age is higher
     * then mature age of Proboscidea.
     */
    virtual void grow();
    /**
     * pure virtual , look at the sons func description
     *
     * @param descendantName
     * @param decendantGender
     * @param mother
     * @param father
     * @return
     */
    virtual Animal *createNewAnimal(const string &descendantName, Gender decendantGender,
                                    Animal *mother, Animal *father) const = 0;

};


#endif //HW3_PROBOSCIDEA_H
