
#include "Proboscidea.h"

const string Proboscidea::PROBOSCIDEA_SOUND("TRUMPET");
const string Proboscidea::_SOUND(SOUNDS_FRAME + PROBOSCIDEA_SOUND + SOUNDS_FRAME);
const size_t Proboscidea::_proboscideaMatureAge(5);


Proboscidea::Proboscidea(Animal *motherPtr, Animal *fatherPtr, const string &animalName,
                         Gender animalGender, AnimalType animalType)
                         :Animal(motherPtr, fatherPtr, animalName, animalGender,
                                 animalType){}

void Proboscidea::makeSound() const
{
    std::cout << _SOUND << std::endl;
}

void Proboscidea::grow()
{
    _age ++;
    if(_age >= _proboscideaMatureAge)
    {
        _isAdult = true;
    }
}


