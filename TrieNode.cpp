// J+M+J
#include "TrieNode.h"

TrieNode::TrieNode(){//initializes the node
    this->isEnd = 0;
    for(int i = 0; i < 26; i++) letters[i] = nullptr;
    this->words = 0;
}

TrieNode* TrieNode::getLetter(int i){//returns the pointer to the letter that corrasponds with index i
    return this->letters[i];
}

int TrieNode::getWordsAt(){//returns the number of words in subtree of this node
    return words;
}

bool TrieNode::isEndOfWord(){//returns if this node marks the end of a word
    return isEnd;
}

void TrieNode::markAsEnd(){//changes this node as now marking the end of a word
    this->isEnd = true;
}

void TrieNode::addWordToSubtree(){//increases amount of words contained in this subtree by 1
    this->words++;
}

bool TrieNode::checkOcupation(char checkFor){//checks if the pointer for the corrasponding letter is !nullptr and return true it is occupied or false if nullptr
    if(letters[checkFor - 'a'] != nullptr) return true;
    return false;
}

TrieNode* TrieNode::getPToLetter(char letter){//returns the pointer value in this node to the input letter
    return this->letters[letter - 'a'];
}

void TrieNode::addNodeAt(char addAt, TrieNode* toAdd){//adds addNodeAt().toAdd to this node at letter pointer matching with addAt
    this->letters[addAt - 'a'] = toAdd;
}