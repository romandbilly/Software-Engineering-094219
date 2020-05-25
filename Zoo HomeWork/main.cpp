#include <iostream>
#include <string>
#include<vector>
#include <sstream>
#include "Zoo.h"
#include "Definitions.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


int main() {
    string firstMale, firstType, firstFemale;
    cin >> firstMale >> firstFemale;
    cin >> firstType;

    Zoo* zoo = new Zoo(firstMale, firstFemale, firstType);

    string input;
    cin >> input;

    while ( input != consoleCommands[QUIT_CODE] ){

        if (  input == consoleCommands[REPRODUCE] ){
            string firstParentName,  secondParentName,  name_, gender;
            cin >>firstParentName>>secondParentName>>name_>>gender;
            Gender animalGender = genderFromString(gender);
            zoo->animalReproduce(firstParentName, secondParentName, name_, animalGender);
        }
        else if (input == consoleCommands[EUTHANIZE] ){
            string name_;
            cin >>name_;
            zoo->euthanize(name_);
        }
        else if(input == consoleCommands[GROW_UP]){
            zoo->growUp();
        }
        else if(input == consoleCommands[PRINT_COMMUNITY]){
            zoo->printCommunity();

        }
        else if(input == consoleCommands[COMMUNITY_SIZE]){
            zoo->printCommunitySize();
        }
        else if(input == consoleCommands[ANCESTORS_PATH]){
            vector<string> pathOrders;
            string name;
            cin >> name;
            while (name != consoleCommands[ANCESTORS_PATH_END]) {
                pathOrders.push_back(name);
                cin >> name;
            }
            zoo->ancestorsPath(pathOrders);
        }
        else if (input == consoleCommands[ADD_ANIMAL]) {
            string name, type, gender;
            cin >> name >> type >> gender;
            zoo->createNewAnimal(name,type,genderFromString(gender));
        }
        else if (input == consoleCommands[MAKE_SOUND]) {
            string name;
            cin >> name;
            zoo->makeSound(name);
        }
        cin >> input;
    }

    delete zoo;
    return 0;
}