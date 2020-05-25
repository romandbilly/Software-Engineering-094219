
#include "Mammoth.h"

Mammoth::Mammoth(Animal *motherPtr, Animal *fatherPtr, const string &animalName,
                 Gender animalGender):Proboscidea(motherPtr, fatherPtr, animalName,
                                                  animalGender, MAMMOTH){}

Animal* Mammoth::createNewAnimal(const string &descendantName, Gender decendantGender,
                                 Animal *mother, Animal *father) const
{
    Animal *animalPtr = new Mammoth(mother, father, descendantName, decendantGender);
    return animalPtr;
}