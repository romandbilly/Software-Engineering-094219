#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::vector;

typedef enum {REPRODUCE,EUTHANIZE,GROW_UP,PRINT_COMMUNITY,COMMUNITY_SIZE,
    ANCESTORS_PATH, ANCESTORS_PATH_END,QUIT_CODE, ADD_ANIMAL, MAKE_SOUND} CommandsEnum;
const std::string consoleCommands[]= {"animalReproduce", "euthanize", "growUp",
                                      "printCommunity", "printCommunitySize",
                                      "ancestorsPath", "end", "quit", "add_animal",
                                      "make_sound"};
typedef enum {MALE=0 , FEMALE} Gender;
const string isAdultStrings[] = {"False", "True"};
const string genderStrings[] = {"male", "female"};
typedef enum {NAME,GENDER,ADULT,MOTHER,FATHER, CHILDREN} OutputEnum;
const string toPrint[]= {"Name: ", "Gender: ","Is adult: ",
                              "Mother name: ","Father name: ","Number of children: "};

const string COMMA_DELIMITER(": ");
const size_t BIRTH_AGE = 0;
const string SOUNDS_FRAME(3,'*');

typedef enum {LION=0, DUCK, ELEPHANT, MAMMOTH} AnimalType;
const string AnimalNames[] = {"Lion", "Duck", "Elephant", "Mammoth"};
const string END_TRAVEL("end");

const string Parents[] = {"f", "m"};
/**
 *
 * @param genderString
 * @return
 */
inline Gender genderFromString(const string& genderString) {
    return (genderString == genderStrings[MALE]) ? MALE : FEMALE;
}


#endif //DEFINTIONS_H
