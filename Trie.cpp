//J+M+J
#pragma once
#include "Trie.h"
Trie::Trie(){//defualt constructor
    this->root = new TrieNode();
    this->words = 0;
    this->nodes = 1;
}                                                         

Trie::~Trie(){//deconstructor
    clearBelow(root);
    delete(root);
}                                                        

int Trie::count(){//get the number of words in the Trie
    return this->words;
}                                                    

int Trie::getSize(){//get the size or number of nodes in the Trie
    return this->nodes;
}                                                  

bool Trie::find(string toFind){//find if a given word exists in the Trie

}                                       

int Trie::completeCount(string wordPart){//function to count the number of words that start with given prefix

}                             

vector<string> Trie::complete(string wordPart){//function to return a vector of words that start with given prefix

}                       

bool Trie::insert(string toInsert){//function to insert a word into the Trie
    this->insertH(toInsert, root);
}                                   

void Trie::clearBelow(TrieNode* nodeAt){//recursive function to delete all nodes below this one non-inclusive
    //Base Case: nodeAt is nullptr
    if(nodeAt == nullptr) return;

    //Recursive Case: nodeAt is not nullptr
    //call clearBelow on all subtrees and delete node
    for(int i = 0; i < 26; i++){
        clearBelow(nodeAt->getLetter(i));
    }
    if(nodeAt->isEndOfWord()) this->words -= 1; //if it's a word ending, subtract from the total number of words
    delete(nodeAt);
    this->nodes -= 1;
}                              

bool Trie::findH(string toFind, TrieNode* nodeAt){//recursive helper function for Trie::find()

}                    

vector<string> Trie::completeH(string wordPart, TrieNode* nodeAt){//recursive helper function for Trie::complete()

}    

bool Trie::insertH(string toInsert, TrieNode* nodeAt){//recursive helper function for Trie::insert()
    //Base Case-0: toInsert is empty and this word has not been inserted (there is no endWord mark) -- mark node as endOfWord
    if(toInsert.size() == 0 && !nodeAt->isEndOfWord()){ // help for string functions obtained from: https://www.tutorialspoint.com/how-to-convert-string-to-char-array-in-cplusplus
        nodeAt->markAsEnd();
        this->words += 1;
        return true;
    }
    //Base Case-1: toInsert is empty and this has been inserted (there is an endWord mark) -- return false
    if(toInsert.size() == 0 && nodeAt->isEndOfWord()) return false;

    //Recursive Case-0: there is already a node pointing to the next letter
    if(nodeAt->checkOcupation(toInsert[0])){
        // if there is only one letter, recursive call with an empty string
        if(toInsert.size() == 1) return insertH("", nodeAt->getPToLetter(toInsert[0]));
        // call again sending it the node corrasponding with the letter and the word minus the first letter
        return insertH(toInsert.substr(1,toInsert.size() - 1), nodeAt->getPToLetter(toInsert[0])); // help for .substr() obtained from: https://www.geeksforgeeks.org/substring-in-cpp/
    }

    //Recursive Case-1: there is no node pointing to the next letter
    TrieNode* toAdd = new TrieNode();
    nodeAt->addNodeAt(toInsert[0], toAdd);
    this->nodes += 1;
    // if there was only one letter, recursive call with an empty string
    if(toInsert.size() == 1) return insertH("", toAdd);
    // else call it on a substring passing it the new node
    return insertH(toInsert.substr(1,toInsert.size() - 1), toAdd);
}                  

void Trie::outputTrie(ostream& os){
    os << "TRIE: " << endl;
    os << "\tNODES: " << this->nodes << endl;
    os << "\tWORDS:" << this->words << endl;
}