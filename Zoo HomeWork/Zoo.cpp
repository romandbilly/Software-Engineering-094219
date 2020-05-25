
#include "Zoo.h"


Zoo::Zoo(const string& maleName, const string& femaleName, const string& type)
{
    createNewAnimal(maleName, type, MALE);
    createNewAnimal(femaleName, type, FEMALE);
}

Animal *Zoo::findAnimal(const string &animalName) const
{
    Animal * animalPtr = NULL;

    for(AnimalPtrVector::const_iterator cit = _members.begin(); cit != _members.end();
    cit++)
    {
        if ((*cit)->isNameEquals(animalName))
        {
            return *cit;
        }
    }

    return animalPtr;
}

bool Zoo::animalReproduce(const string &firstParentName, const string &secondParentName,
                          const string &name, Gender gender)
{
    Animal* firstParent = findAnimal(firstParentName);
    if (!firstParent)
    {
        return false;
    }
    Animal* secondParent = findAnimal(secondParentName);
    if (!secondParent)
    {
        return false;
    }
    Animal* child = firstParent -> reproduce(secondParent, name, gender);
    if (child)
    {
        _members.push_back(child);
        return true;
    }
    return false;
}

bool Zoo::euthanize(const string &name)
{
    for (AnimalPtrVector::iterator iter = _members.begin(); iter != _members.end();
    iter++)
    {
        if ((*iter)->isNameEquals(name))
        {
            delete *iter;
            _members.erase(iter);
            break;
        }
    }
    for(size_t i = 0; i < _members.size(); i++)
    {
        if(!_members[i]->isAlive())
        {
            delete _members[i];
            _members.erase(_members.begin() + i);
            i--;
        }
    }
    return false;
}

void Zoo::growUp() const
{
    for (AnimalPtrVector::const_iterator cit = _members.begin(); cit != _members.end();
    cit++) {
        (*cit)->grow();
    }
}

void Zoo::printCommunity() const
{
    for(AnimalPtrVector::const_iterator cit = _members.begin(); cit != _members.end();
    cit++) {
        (*cit)->printAnimal();
    }
}

void Zoo::printCommunitySize() const
{
    cout << NUMBER_OF_ANIMALS << _members.size() << endl;
}

void Zoo::ancestorsPath(const vector<string> &travelOrders) const
{
    vector<string>::const_iterator travelCit = travelOrders.begin();
    Animal* animalPtr = findAnimal(*travelCit);

    if (!animalPtr) {
        cout << ANIMAL_NOT_FOUND << endl;
        return;
    }
    animalPtr -> printAnimal();
    for(travelCit++; travelCit != travelOrders.end() && *travelCit!= END_TRAVEL ;
        travelCit++) {
        Animal* tempPtr = animalPtr -> getAncestor(*travelCit);
        if (!tempPtr) {
            cout << FAILED_TRAVEL << endl;
            continue;
        }
        animalPtr = tempPtr;
        animalPtr -> printAnimal();
    }
}


void Zoo::createNewAnimal(const string& name, const string& type, Gender gender)
{

    Animal *newAnimal = createAnimalByType(name, type, gender);
    _members.push_back(newAnimal);
}

Animal * Zoo::createAnimalByType(const string& name, const string& type, Gender gender)
{
    Animal *newAnimal = NULL;

    if (type == AnimalNames[LION])
    {
        newAnimal = new Lion(NULL, NULL, name, gender);
    }
    else
    if (type == AnimalNames[DUCK])
    {
        newAnimal = new Duck(NULL, NULL, name, gender);
    }
    else
    if(type == AnimalNames[ELEPHANT])
    {
        newAnimal = new Elephant(NULL, NULL, name, gender);
    }
    else
    if(type == AnimalNames[MAMMOTH])
    {
        newAnimal = new Mammoth(NULL, NULL, name, gender);
    }

    return newAnimal;
}

void Zoo::makeSound(const string& name) const
{
    Animal *requestedAnimal = findAnimal(name);
    requestedAnimal->makeSound();
}


Zoo::~Zoo()
{
    for(AnimalPtrVector::iterator iter = _members.begin(); iter != _members.end();
    iter++ ) {
        delete (*iter);
    }
    _members.clear();
}


