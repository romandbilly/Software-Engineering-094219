#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


/** getDnaFrom1stLine
 * read the first line , the dna string
 *
 * @param dna - the dna string
 */

void getDnaFrom1stLine(string& dna)
{
    getline(cin, dna);
}

/** getAcidContent
 * Function converts the raw acid content into the acid itself.
 *
 * @param RawAcidContent - a string that include the indexes of Nucleotides separated by
 * commas.
 * @param dna - the dna string
 * @return string that include the acid content.
 */
string getAcidContent(string RawAcidContent, const string& dna)
{
    string delimiter = ",";
    size_t index;
    string indexStr;
    string acidContent;
    size_t delimiterPosition = RawAcidContent.find(delimiter);

    while (delimiterPosition != string::npos)
    {
        indexStr = RawAcidContent.substr(0,delimiterPosition);
        std::istringstream wrappingIndex(indexStr);
        wrappingIndex >> index;
        acidContent += dna[index];
        RawAcidContent = RawAcidContent.substr(delimiterPosition + delimiter.length());
        delimiterPosition = RawAcidContent.find(delimiter);
    }
    std::istringstream wrapingIndex(RawAcidContent);
    wrapingIndex >> index;
    acidContent += dna[index];
    return acidContent;
}

/** getMapFrom2ndLine
 * The function reads the second line ("the map string") and from this string :
 * it inserts the names of acids to acidNamesVector by order.
 * The function inserts the contents of acids to acidContentsVector by the same order.
 *
 * @param acidNamesVector - include the names of acids
 * @param acidContentsVector - include the contents of acids
 * @param dna - the dna string
 */
void getMapFrom2ndLine(vector<string>& acidNamesVector,
                       vector<string>& acidContentsVector,
                       const string& dna)
{
    string mapStr;
    string delimiter = " ";
    string rawContentOfAcid;
    string nameAcid;
    string acidContent;

    getline(cin, mapStr);
    size_t delimiterPosition = mapStr.find(delimiter);
    size_t detectByPositionNameOrContent = 0;

    while (delimiterPosition != string::npos)
    {
        if(detectByPositionNameOrContent == 0)
        {
            rawContentOfAcid = mapStr.substr(0, delimiterPosition);
            acidContent = getAcidContent(rawContentOfAcid, dna);
            acidContentsVector.push_back(acidContent);
            detectByPositionNameOrContent++;
        }
        else
        {
            nameAcid = mapStr.substr(0, delimiterPosition);
            acidNamesVector.push_back(nameAcid);
            detectByPositionNameOrContent--;
        }
        mapStr = mapStr.substr(delimiterPosition+delimiter.length());
        delimiterPosition = mapStr.find(delimiter);
    }
    acidNamesVector.push_back(mapStr);
}

/** printAcid
 * The function prints the three Nucleotides of the current acid.
 *
 * @param acid - the name of the acid
 * @param acidNamesVector - include the names of acids
 * @param acidContentsVector - include the contents of acids
 */
void printAcid(const string &acid,
               const vector<string> &acidNamesVector,
               const vector<string> &acidContentsVector)
{
    vector<string>::const_iterator citNames;
    vector<string>::const_iterator citContents;

    citNames = acidNamesVector.begin();
    citContents = acidContentsVector.begin();
    while (citNames != acidNamesVector.end())
    {
        if (acid == *citNames)
        {
            cout << *citContents;
            break;
        }
        citContents++;
        citNames++;
    }
}

/** printGen
 * the function prints the gen.
 *
 * @param protein - string that include acids
 * @param acidNamesVector  - include the names of acids
 * @param acidContentsVector -include the contents of acids
 */
void printGen(string protein,
              const vector<string>& acidNamesVector,
              const vector<string>& acidContentsVector)
{
    string delimiter = " ";
    string acid;
    size_t delimiterPosition = protein.find(delimiter);

    while (delimiterPosition != string::npos)
    {
        acid = protein.substr(0,delimiterPosition);
        printAcid(acid, acidNamesVector, acidContentsVector);
        protein = protein.substr(delimiterPosition + delimiter.length());
        delimiterPosition = protein.find(delimiter);
    }
    printAcid(protein, acidNamesVector, acidContentsVector);
}


int main()
{
    string dna;
    vector<string> acidNamesVector;
    vector<string> acidContentsVector;
    string protein;

    getDnaFrom1stLine(dna);
    getMapFrom2ndLine(acidNamesVector, acidContentsVector, dna);
    getline(cin, protein);
    while(protein != "end")
    {
        printGen(protein, acidNamesVector, acidContentsVector);
        cout << endl;
        getline(cin,protein);
    }
    return 0;
}