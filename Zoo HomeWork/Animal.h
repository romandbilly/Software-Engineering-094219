
#ifndef HW2_ANIMAL_H
#define HW2_ANIMAL_H

#include <iostream>
#include <string>
#include <vector>
#include "Definitions.h"

extern int dadada = 2;
using std::string;
using std::vector;
using std::cout;
using std::endl;

const string DELIMITER(", ");

class Animal {
private:

    Animal* _mother;
    Animal* _father;
    vector<Animal*> _children;
    string _name;
    AnimalType _type;
    bool _alive;
    Animal(const Animal& animal){};
    const Animal& operator = (const Animal& animal){};

    /**
     * remove the animal, before it dies, from its parents
     *
     * @param gender Gender: the gender of the parent to be removed from
     */
    void removeFromParents(Gender gender) const;
    /**
     * check whether the current animal and its potential partner are adult and are
     * from different gender
     *
     * @param potentialPartner Animal*: the potential partner for reproduce
     * @return boolean: whether the reproduce is valid
     */
    bool isReproduceValid(Animal* potentialPartner) const;

    /**
     * insert the new child to parent children list
     * @param child
     */
    void fillMyChildrenList(Animal *child);



protected:


    Gender _gender;
    bool _isAdult;
    size_t _age;
    Animal(){};

public:
    /**
     * create a new animal with a given name and a gender, that has a pointer to its
     * parents
     *
     * now animal is abstract class
     *
     * @param motherPtr Animal*: a pointer to the animal mother
     * @param fatherPtr Animal*: a pointer to the animal father
     * @param animalName string: the name of the newborn
     * @param animalGender Gender: the gender of the newborn
     * @param animalType animalType: the type of Animal
     */
    Animal(Animal* motherPtr, Animal* fatherPtr, const string& animalName, Gender
    animalGender, AnimalType type);

    /**
     * print the details of the animal
     */
    void printAnimal() const;

    /**
     * grow the animal age by 1 and change the isAdult to true if needed
     */
    virtual void grow(){};

    /**
     * Underage orphan animal is count as dead, and thereby can be removed
     *
     * @return boolean: whether the animal is alive
     */

    bool isAlive() const {return _alive;}


    /**
     * this method allows two adults from a different gender to reproduce a new animal
     * from a given gender
     *
     * @param partner Animal*: the potential mate of the animal
     * @param descendantName string: the name of the newborn
     * @param decendantGender Gender: the gender of the newborn
     * @return Animal*: a pointer to the new animal
     */
    Animal* reproduce(Animal* partner, const string& descendantName, Gender
                      decendantGender);


    /**
     * pure virtual
     * look at the sons funcs description
     */
    virtual void makeSound() const = 0;

    /**
     * pure virtual
     * look at the sons funcs description
     */
    virtual Animal* createNewAnimal(const string &descendantName, Gender decendantGender,
            Animal *mother, Animal *father) const= 0;


    /**
     * check if the name of the animal is same as input
     *
     * @param checkName string: the name to check
     * @return boolean: whether the name of the animal is similar to the one sent
     */
    bool isNameEquals(const string& checkName) const {return _name == checkName;}

    /**
     *
     * this method returns the father or mother of the animal
     *
     * @param AncestorGender string: the gender of the parent to return where:
     *  \arg "f" represents the father.
     *  \arg "m" represents the mother.
     * @return Animal*: pointer to the requested ancestor if presents, NULL otherwise.
     */
    Animal* getAncestor(const string& AncestorGender) const;

    /**
     * destructor
     *
     */
    ~Animal();
};

#endif //HW2_ANIMAL_H
