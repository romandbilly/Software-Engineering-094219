
#include "Elephant.h"

Elephant::Elephant(Animal *motherPtr, Animal *fatherPtr, const string &animalName,
                   Gender animalGender):Proboscidea(motherPtr, fatherPtr, animalName,
                                        animalGender, ELEPHANT){}

Animal* Elephant::createNewAnimal(const string &descendantName, Gender decendantGender,
                                  Animal *mother, Animal *father) const
{
    Animal *animalPtr = new Elephant(mother, father, descendantName, decendantGender);
    return animalPtr;
}
