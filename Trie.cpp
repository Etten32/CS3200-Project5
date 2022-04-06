//J+M+J
#include "Trie.h"
Trie::Trie(){//defualt constructor
    this->root = new TrieNode();
    //this->words = 0; //* DEPRECATED
    this->nodes = 1;
}                                                         

Trie::~Trie(){//deconstructor
// if root is not cleared, clear tree, else skip as there is no root to clear at
    if(!rootCleared) clearFrom(root);
}                                                        

int Trie::count(){//get the number of words in the Trie
    //return this->words; //* DEPRECATED
    return root->getWordsAt();
}                                                    

int Trie::getSize(){//get the size or number of nodes in the Trie
    return this->nodes;
}                                                  

bool Trie::find(string toFind){//find if a given word exists in the Trie
    return this->findH(toFind, this->root);
}                                       

int Trie::completeCount(string wordPart){//function to count the number of words that start with given prefix
    TrieNode* nodeAt = this->root;
    while(nodeAt != nullptr && wordPart.size() != 0){
        // go to first letter node
        nodeAt = nodeAt->getPToLetter(wordPart[0]);
        wordPart = wordPart.substr(1,wordPart.size() - 1);
    }
    if(nodeAt != nullptr) return nodeAt->getWordsAt();
    return 0;
}                             

vector<string> Trie::complete(string wordPart){//function to return a vector of words that start with given prefix
    // if root is compromised return an empty vector
    if(rootCleared) return vector<string>();
    
    // go to place in trie to add words to vector
    TrieNode* nodeAt = this->root;
    string appender = wordPart;
    while(nodeAt != nullptr && wordPart.size() != 0){
        // go to first letter node
        nodeAt = nodeAt->getPToLetter(wordPart[0]);
        wordPart = wordPart.substr(1,wordPart.size() - 1);
    }
    if(nodeAt != nullptr) return completeH(appender, nodeAt);
    else return vector<string>();
}                       

bool Trie::insert(string toInsert){//function to insert a word into the Trie
    // if root is not cleared, call recursive insert, else skip as there is no root to insert at
    if(!rootCleared) return this->insertH(toInsert, root);
}                                   

void Trie::clearFrom(TrieNode* nodeAt){//recursive function to delete all nodes below this one non-inclusive
    if(nodeAt == this->root) this->rootCleared = true;

    //Base Case: nodeAt is nullptr
    if(nodeAt == nullptr) return;

    //Recursive Case: nodeAt is not nullptr
    //call clearBelow on all subtrees and delete node
    for(int i = 0; i < 26; i++){
        clearFrom(nodeAt->getLetter(i));
    }
    //if(nodeAt->isEndOfWord()) this->words -= 1; //if it's a word ending, subtract from the total number of words //* DEPRECATED
    delete(nodeAt);
    this->nodes -= 1;
}                              

bool Trie::findH(string toFind, TrieNode* nodeAt){//recursive helper function for Trie::find()

}                    

vector<string> Trie::completeH(string appender, TrieNode* nodeAt){//recursive helper function for Trie::complete()
    //Base Case: node is null, return an empty vector
    if(nodeAt == nullptr) return vector<string>();

    //Recursive Case: add this word to list (if it is a word) and recursively call and add words from returned list to this list
    vector<string> toReturn = vector<string>();
    if(nodeAt->isEndOfWord()) toReturn.push_back(appender);
    //go through each letter and call completeH on it
    for(char letter = 'a'; letter <= 'z'; letter++){
        vector<string> fromReturn = completeH(appender + letter, nodeAt->getPToLetter(letter));
        //add all returned results 
        for(int i = 0; i < fromReturn.size(); i++) toReturn.push_back(fromReturn[i]);
    }
    return toReturn;
}    

bool Trie::insertH(string toInsert, TrieNode* nodeAt){//recursive helper function for Trie::insert()
    //Base Case-0: toInsert is empty and this word has not been inserted (there is no endWord mark) -- mark node as endOfWord
    if(toInsert.size() == 0 && !nodeAt->isEndOfWord()){ // help for string functions obtained from: https://www.tutorialspoint.com/how-to-convert-string-to-char-array-in-cplusplus
        nodeAt->markAsEnd();
        nodeAt->addWordToSubtree();
        return true;
    }
    //Base Case-1: toInsert is empty and this has been inserted (there is an endWord mark) -- return false
    if(toInsert.size() == 0 && nodeAt->isEndOfWord()) return false;

    //Recursive Case-0: there is already a node pointing to the next letter
    if(nodeAt->checkOcupation(toInsert[0])){
        // if there is only one letter, recursive call with an empty string
        if(toInsert.size() == 1){
            if(insertH("", nodeAt->getPToLetter(toInsert[0]))){
                nodeAt->addWordToSubtree();
                return true;
            }
            else return false;
        } 
        // call again sending it the node corrasponding with the letter and the word minus the first letter
        if(insertH(toInsert.substr(1,toInsert.size() - 1), nodeAt->getPToLetter(toInsert[0]))){ // help for .substr() obtained from: https://www.geeksforgeeks.org/substring-in-cpp/
            nodeAt->addWordToSubtree();
            return true;
        } 
        else return false;
    }

    //Recursive Case-1: there is no node pointing to the next letter
    TrieNode* toAdd = new TrieNode();
    nodeAt->addNodeAt(toInsert[0], toAdd);
    this->nodes += 1;
    // if there was only one letter, recursive call with an empty string
    if(toInsert.size() == 1){ 
        if(insertH("", toAdd)){
            nodeAt->addWordToSubtree();
            return true;
        }
    }
    // else call it on a substring passing it the new node
    else if(insertH(toInsert.substr(1,toInsert.size() - 1), toAdd)){
        nodeAt->addWordToSubtree();
        return true;
    }
}                  

void Trie::outputTrie(ostream& os){
    os << "TRIE: " << endl;
    os << "\tNODES: " << this->nodes << endl;
    os << "\tWORDS:" << this->root->getWordsAt() << endl;
}