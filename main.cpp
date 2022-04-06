//J+M+J
//MAIN: takes in word file and runs Trie implemented spellchecker
#include "Trie.h"
#include "TestHarness.h"
#include <sstream> // help from: https://en.cppreference.com/w/cpp/string/basic_string/getline
#include <iostream>
#include <fstream> // help from: https://stackoverflow.com/questions/15080231/c-variable-stdifstream-ifs-has-initializer-but-incomplete-type
//#include <fstream>

using namespace std;

int main(){
    // run test harness -- uncomment to run 
    /*/
    TestHarness::testTries(); 
    //*/

    // Load in text file to Trie
    Trie* dictionary = new Trie();

    ifstream inputFile;                         // help from: https://www.educba.com/ifstream-in-c-plus-plus/
    //                                           / and from: https://docs.microsoft.com/en-us/cpp/standard-library/basic-ifstream-class?view=msvc-170
    string toInsert;
    inputFile.open("windows_wordlist.txt");

    for(int i = 0; i < 62887; i++){
        std::getline(inputFile, toInsert);
        dictionary->insert(toInsert);
    }
    inputFile.close();


    // Main program
    string userWord = " ";
    cout << "Please enter a word prefix (or press enter to exit): ";
    std::getline(cin,userWord);
    // as long as the user response isn't the empty string loop through question
    while(userWord.size() != 0){
        cout << "There are " << dictionary->completeCount(userWord) 
            << " completions for the prefix '" << userWord << "'. Show completions? ";
        // to show completions or not
        string userAnswer = " ";
        std::getline(cin,userAnswer);
        // show completions
        if(userAnswer.compare("Yes") == 0 || userAnswer.compare("yes") == 0 || userAnswer.compare("Y") == 0 || userAnswer.compare("y") == 0){ // help from: https://www.cplusplus.com/reference/string/string/compare/
            cout << "Completions" << endl
                << "----------" << endl;
            vector<string> completions = dictionary->complete(userWord);
            for(int i = 0; i < completions.size(); i++) cout << completions[i] << endl;
        }
        // else continue (or continue afterwards)
        cout << "Please enter a word prefix (or press enter to exit): ";
        std::getline(cin,userWord);
    }
}