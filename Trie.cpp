//J+M+J
#include "Trie.h"
Trie::Trie(){//defualt constructor

}                                                         

Trie::~Trie(){//deconstructor

}                                                        

int Trie::count(){//get the number of words in the Trie

}                                                    

int Trie::getSize(){//get the size or number of nodes in the Trie

}                                                  
    
bool Trie::find(string toFind){//find if a given word exists in the Trie

}                                       

int Trie::completeCount(string wordPart){//function to count the number of words that start with given prefix

}                             

vector<string> Trie::complete(string wordPart){//function to return a vector of words that start with given prefix

}                       

bool Trie::insert(string toInsert){//function to insert a word into the Trie

}                                   

void Trie::clearBelow(TrieNode* nodeAt){//recursive function to delete all nodes below this one non-inclusive

}                              

bool Trie::findH(string toFind, TrieNode* nodeAt){//recursive helper function for Trie::find()

}                    

vector<string> Trie::completeH(string wordPart, TrieNode* nodeAt){//recursive helper function for Trie::complete()

}    

bool Trie::insertH(string toFind, TrieNode* nodeAt){//recursive helper function for Trie::insert()

}                  