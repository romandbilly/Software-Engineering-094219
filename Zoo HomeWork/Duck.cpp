
#include "Duck.h"

const string Duck::DUCK_SOUND ("QUACK");
const string Duck::_SOUND(SOUNDS_FRAME + DUCK_SOUND + SOUNDS_FRAME);
const size_t Duck::DUCK_MATURE_AGE(1);


Duck::Duck(Animal *motherPtr, Animal *fatherPtr, const string &animalName, Gender
           animalGender):Animal(motherPtr, fatherPtr, animalName, animalGender, DUCK){}

void Duck::makeSound() const {
    std::cout << _SOUND << std::endl;
}

void Duck::grow(){
    _age ++;
    if(_age >= DUCK_MATURE_AGE)
    {
        _isAdult = true;
    }
}


Animal* Duck::createNewAnimal(const string &descendantName, Gender decendantGender,
                              Animal *mother, Animal *father) const
{
    Animal *animalPtr = new Duck(mother, father, descendantName, decendantGender);
    return animalPtr;
}
