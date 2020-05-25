
#include "Lion.h"


const string Lion::LION_SOUND("RWAR");
const string Lion::_SOUND(SOUNDS_FRAME + LION_SOUND + SOUNDS_FRAME);
const size_t Lion::LION_MATURE_AGE (3);


Lion::Lion(Animal *motherPtr, Animal *fatherPtr, const string &animalName, Gender
           animalGender):Animal(motherPtr, fatherPtr, animalName, animalGender, LION){}

void Lion::makeSound() const {
    std::cout << _SOUND << std::endl;
}

void Lion::grow(){
    _age ++;
    if(_age >= LION_MATURE_AGE)
    {
        _isAdult = true;
    }
}

Animal *Lion::createNewAnimal(const string &descendantName, Gender decendantGender,
                              Animal *mother, Animal *father) const
{
    Animal * animalPtr = new Lion(mother, father, descendantName, decendantGender);
    return animalPtr;
}
