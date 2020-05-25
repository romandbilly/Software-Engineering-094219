//
// Created by rom on 5/16/19.
//

#ifndef HW2_ZOO_H
#define HW2_ZOO_H

#include <iostream>
#include <vector>
#include "Lion.h"
#include "Duck.h"
#include "Elephant.h"
#include "Mammoth.h"


using std::vector;
using std::string;
using std::cout;

typedef vector<Animal*> AnimalPtrVector;


const string FAILED_TRAVEL("failed");
const string ANIMAL_NOT_FOUND("The animal was not found!");
const string NUMBER_OF_ANIMALS("number of animals in the community is: ");

/**
 * Class Zoo
 * holds and mange zoo of animals
 */
class Zoo {
private:
    AnimalPtrVector _members;
    Zoo(const Zoo& zoo){};
    const Zoo& operator = (const Zoo& zoo){};
    /**
     * this method finds if an animal exists in the zoo, based on the animal`s name
     *
     * @param animalName string: the name of the animal we wish to find
     * @return Aninal*: pointer to the animal if it presents, NULL otherwise.
     */
    Animal* findAnimal(const string& animalName) const;
    /**
     *
     * @param name: the name of the new animal
     * @param type: the type of the new animal
     * @param gender: the gender of the new animal
     * @return pointer to the new creature
     */
    Animal* createAnimalByType(const string& name, const string& type, Gender gender);


public:

    /**
     * constructs a new Zoo, which requires one animal of each gender
     *
     * @param maleName string: the name of the male animal
     * @param femaleName string: the name of the female animal
     */
    Zoo(const string& maleName, const string& femaleName, const string& type);

    /**
     * method to reproduce a new animal, using two valid parents with a given name and
     * a gender
     *
     * @param firstParentName string: the name of the first parent
     * @param secondParentName string: the name of the second parent
     * @param name string: the name of the newborn baby animal
     * @param gender Gender: the gender of the newborn
     * @return boolean: whether the reproduce was valid and were succeeded
     */
    bool animalReproduce(const string& firstParentName, const string& secondParentName,
                         const string& name, Gender gender);

    /**
     * this method euthanizes a given animal and removes it from the zoo.
     * It also removes from the zoo any orphan child of the animal in question.
     *
     * @param name string: the name of the animal to euthanize
     * @return boolean: whether the euthanasia process was successful
     */
    bool euthanize(const string& name);

    /**
     * this method grow up by 1 year all the animals in the zoo.
     */
    void growUp() const;

    /**
     * prints the details of the animals community.
     */
    void printCommunity() const;

    /**
     * prints the size of the community
     */
    void printCommunitySize() const;

    /**
     * this method traverses the family tree and prints each node of it by the orders
     * given as an input
     *
     * @param travelOrders vector<string> a container that holds
     */
    void ancestorsPath (const vector<string> &travelOrders ) const;
    /**
     * crteate a new animal in insert him to the zoo
     *
     * @param name : the name of the new animal
     * @param type : the type of the new animal
     * @param gender : the gender of the new animal
     */
    void createNewAnimal(const string& name, const string& type, Gender gender);
    /**
     *print the SOUND of the requested animal
     * @param name: the name of the animal
     */
    void makeSound(const string& name) const ;

    /**
     * destructs the class
     *
     */
    ~Zoo();

};

#endif //HW2_ZOO_H
