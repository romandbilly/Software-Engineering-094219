
#include <iostream>
#include "Tree.h"
using std::pair;
using std::make_pair;
using std::logic_error;
using std::cin;
using std::runtime_error;

typedef enum {NEW=0, INSERT, DELETE, SEARCH, EMPTY, SIZE, TRAVEL, QUIT} CommandsEnum;
const string consoleCommands[] = {"new", "insert", "deleteLeaf", "search", "empty",
                                  "size", "inorderTraversal", "quit"};

typedef enum {INT=0, FLOAT, STRING} TreeTypes;
const string treeTypes[] = {"int", "float", "string"};

typedef enum {KEY, ITEM,INPUT} TypesLocationErrors;
const string typesErrorLocation[] = {"Key", "Item","Input"};

const string EMPTY_TREE("The tree is empty");
const string NOT_EMPTY_TREE("The tree is not empty");
const string FOUND = "found:";
const string TREE_SIZE("Tree size: ");
const string BAD_COMMAND("Bad command");
/*
 * the func throw error
 */
void errorThrower(TypesLocationErrors loc, const string& erroredType){
    throw runtime_error("Bad " + typesErrorLocation[loc] + " Type: " + erroredType);
}
/*
 * the template func take care of the inputs from the user
 */
template<typename Type1>
Type1 getInputs(CommandsEnum command){
    Type1 input;
    cin >> input;
    if (cin.fail()){
        throw runtime_error("Bad input type!");
    }
    return input;
}
/*
 * the template func take care of the inputs from the user
 */
template<typename Type1, typename Type2>
pair<Type1, Type2> getInputs(CommandsEnum command){
    Type1 firstInput(getInputs<Type1>(command));
    Type2 secondInput(getInputs<Type2>(command));
    return make_pair(firstInput, secondInput);
}
/*
 * the template func start a session of requested commands
 */
template <typename T, typename G>
void treeSession() {
    Tree <T, G> tree;
    string input;
    cin >> input;
    while (input != consoleCommands[QUIT]){
        try{
        if (input == consoleCommands[INSERT])
        {
            pair<T, G> tempPair(getInputs<T, G>(INSERT));
            T key(tempPair.first);
            G item(tempPair.second);
            tree.insert(key, item);
        }
            else if (input == consoleCommands[DELETE])
                {
                    T needToDie = getInputs<T>(DELETE);
                    tree.deleteLeaf(needToDie);
                }
            else if (input == consoleCommands[SEARCH])
                {
                T lookFor = getInputs<T>(SEARCH);
                Node<T, G> *temp = tree.search(lookFor);
                if (temp != NULL)
                    cout << FOUND << *temp;
                }
            else if (input == consoleCommands[EMPTY])
                {
                if(tree.isEmpty())
                    cout << EMPTY_TREE << endl;
                else
                    cout << NOT_EMPTY_TREE << endl;
                }
            else if (input == consoleCommands[SIZE])
                {
                cout << TREE_SIZE << tree.size() << endl;
                }
            else if (input == consoleCommands[TRAVEL])
                {
                tree.inOrderTraversal();
                }
            else
                {
                cerr << BAD_COMMAND << endl;
                }
        cin >> input;
    }
        catch (const logic_error& error)
        {
            cerr << error.what() << endl;
        }
    }
}
/*
 * the template func create a tree
 */
template <typename T>
void treeCreator(){
    string valueType;
    cin >> valueType;
    if (valueType == treeTypes[INT]){
        treeSession<T, int>();
    }
    else if (valueType == treeTypes[FLOAT]){
        treeSession<T, float>();
    }
    else if (valueType == treeTypes[STRING]){
        treeSession<T, string>();
    }
    else{
        errorThrower(ITEM, valueType);
    }
}

int main() {

    try{
        string input;
        cin >> input;
        if (input == consoleCommands[NEW]) {
            string keyType;
            cin >> keyType;
            if (keyType == treeTypes[INT]) {
                treeCreator<int>();
            }
            else if (keyType == treeTypes[FLOAT]){
                treeCreator<float>();
            }
            else if (keyType == treeTypes[STRING]){
                treeCreator<string>();
            }
            else{
                errorThrower(KEY, keyType);
            }
        }
        else {
            errorThrower(INPUT, input);
        }
    }
    catch( const runtime_error& error){
        cerr << error.what() << endl;
    }
}
