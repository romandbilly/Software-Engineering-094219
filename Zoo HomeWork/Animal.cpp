

#include "Animal.h"


Animal::Animal(Animal *motherPtr, Animal *fatherPtr, const string &animalName,
               Gender animalGender, AnimalType type):_mother(motherPtr),_father(fatherPtr),
               _name(animalName), _gender(animalGender), _type(type), _isAdult(false),
               _alive(true), _age(BIRTH_AGE) {}

void Animal::printAnimal() const
{
    cout << AnimalNames[_type] << COMMA_DELIMITER;
    cout << toPrint[NAME] << _name << DELIMITER;
    cout << toPrint[GENDER] << genderStrings[_gender] << DELIMITER;
    cout << toPrint[ADULT] << isAdultStrings[_isAdult] << DELIMITER;
    cout << toPrint[MOTHER] << ((_mother) ? _mother->_name : "") << DELIMITER;
    cout << toPrint[FATHER] << ((_father) ? _father->_name : "") << DELIMITER;
    cout << toPrint[CHILDREN] << _children.size() << endl;
}

Animal* Animal::reproduce(Animal *partner, const string &descendantName,
                          Gender decendantGender)
{
    Animal *animalPtr = NULL;

    if (isReproduceValid(partner))
    {
        Animal *mother(NULL), *father(NULL);
        if (_gender == FEMALE)
        {
            mother = this;
            father = partner;
        }
        else
        {
            father = this;
            mother = partner;
        }
        animalPtr = mother->createNewAnimal(descendantName, decendantGender, mother,
                                            father);

        mother->fillMyChildrenList(animalPtr);
        father->fillMyChildrenList(animalPtr);
    }

    return animalPtr;
}

bool Animal::isReproduceValid(Animal *potentialPartner) const
{
    return (_isAdult
            && potentialPartner->_isAdult
            && _gender != potentialPartner->_gender && _type == potentialPartner->_type);
}

Animal *Animal::getAncestor(const string &AncestorGender) const
{
    if(AncestorGender == Parents[MALE]){
        return _father;
    }
    else if (AncestorGender == Parents[FEMALE]) {
        return _mother;
    }
    return NULL;
}

void Animal::fillMyChildrenList(Animal *child)
{
    _children.push_back(child);
}

void Animal::removeFromParents(Gender gender) const
{
    Animal* parent = (gender == FEMALE) ? _mother : _father;
    if (!parent){
        return;
    }
    for(vector<Animal*>::iterator iter = parent->_children.begin();
        iter!=parent->_children.end(); iter++){
        if (*iter == this){
            parent->_children.erase(iter);
            return;
        }
    }
}

Animal::~Animal()
{
    for(vector<Animal*>::iterator iter = _children.begin(); iter!=_children.end();
    iter++ ) {
        if (_gender == FEMALE) {
            (*iter)->_mother = NULL;
        }
        else {
            (*iter)->_father = NULL;
        }
        if ((*iter)->_father == (*iter)->_mother && !(*iter)->_isAdult) {
            (*iter)->_alive = false;
        }
    }
    removeFromParents(FEMALE);
    removeFromParents(MALE);
}