//J+M+J
/** FILE: Trie.h
 * CLASS: PROVIDED: TRIE
 * DEPENDANCY: FILES: TrieNode.h, TrieNode.cpp, vector.h
 * -<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-
 * FUNCTIONS:
 * *v*v*v*v* PUBLIC: *v*v*v*v*
 * CONSTRUCTORS:
 * Trie()
 *      Postcondition: initializes Trie with the following:
 *          root = new blank node
 *          words = 0
 *          nodes = 1
 * 
 * DESTRUCTOR:
 * ~Trie()
 *      Postcondition: all nodes in Trie including root are released back to heap
 *      Dependancies: Trie::clearBelow()
 * 
 * INFORMATION: FUNCTIONS:
 * int count()
 *      Postcondition: returns this->words
 * 
 * int getSize()
 *      Postcondition: returns this->nodes
 * 
 * bool find(string toFind)
 *      Postcondition: returns true if Trie::find().toFind is within Trie as a word
 *                     else returns false
 *      Dependancies: Trie::findH()
 * 
 * int completeCount(string wordPart)
 *      Postcondition: returns number of words starting with Trie::completeCount().wordPart
 * 
 * vector<string> complete(string wordPart)
 *      Postcondition: returns vector full of all the words that start with Trie::complete().wordPart
 *      Dependancies: Trie::completeH()
 *   
 * outputTrie(ostream& os)
 *      Postcondition: prints out properties of Trie to os
 * 
 * MUTATION: FUNCTIONS:
 * bool insert(string toInsert)
 *      Postcondition: //* DOCUMENTATION NEEDED
 *      Dependancies: Trie::insertH()
 * 
 * void clearFrom(TrieNode* nodeAt) - RECURSIVE IMPLEMENTATION
 *      Postcondition: //* DOCUMENTATION NEEDED
 * 
 * *v*v*v*v* PRIVATE: *v*v*v*v*
 * INFORMATION: FUNCTIONS:
 * bool findH(string toFind, TrieNode* nodeAt)
 *      Postcondition: //* DOCUMENTATION NEEDED
 * 
 * vector<string> completeH(string appender, TrieNode* nodeAt) ///USE THIS->VECTOR + RECURSIVE VECTOR TO GET VECTOR
 *      Postcondition: //* DOCUMENTATION NEEDED
 * 
 * MUTATION: FUNCTIONS:
 * bool insertH(string toFind, TrieNode* nodeAt)
 *      Postcondition: //* DOCUMENTATION NEEDED
 * 
 * -<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-
 * VARIABLES:
 * *v*v*v*v* PRIVATE: *v*v*v*v*
 * TrieNode* root
 *      The root pointer of the Trie
 * 
 * int words
 *      The number of words currently in the Trie
 * 
 * int nodes
 *      The number of nodes currently in the Trie
 * */

#include <iostream>
#include <vector>
#pragma once
#include "TrieNode.h"

using namespace std;
class Trie{
    public:                                                         //-------------------------------------------------------------------
    Trie();                                                         //defualt constructor

    ~Trie();                                                        //deconstructor

    int count();                                                    //get the number of words in the Trie

    int getSize();                                                  //get the size or number of nodes in the Trie
    
    bool find(string toFind);                                       //find if a given word exists in the Trie

    int completeCount(string wordPart);                             //function to count the number of words that start with given prefix

    vector<string> complete(string wordPart);                       //function to return a vector of words that start with given prefix

    void outputTrie(ostream& os);                                   //prints out 'this' properties to os

    bool insert(string toInsert);                                   //function to insert a word into the Trie

    void clearFrom(TrieNode* nodeAt);                               //recursive function to delete all nodes below this one non-inclusive

    private:                                                        //-------------------------------------------------------------------
    bool findH(string toFind, TrieNode* nodeAt);                    //recursive helper function for Trie::find()

    vector<string> completeH(string appender, TrieNode* nodeAt);    //recursive helper function for Trie::complete()

    bool insertH(string toFind, TrieNode* nodeAt);                  //recursive helper function for Trie::insert()
    
    ;                                                               //-------------------------------------------------------------------
    TrieNode* root;                                                 //baseNode of Trie

    //int words;                                                    //number of words in Trie     //* DEPRECATED
    
    int nodes;                                                      //number of nodes in Trie

    bool rootCleared = false;
};