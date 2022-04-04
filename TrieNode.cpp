// J+M+J
#include "TrieNode.h"

TrieNode::TrieNode(){
    this->isEnd = 0;
    for(int i = 0; i < 26; i++) letters[i] = nullptr;
    this->words = 0;
}

TrieNode* TrieNode::getLetter(int i){
    return this->letters[i];
}

int TrieNode::getWordsAt(){
    return words;
}

bool TrieNode::isEndOfWord(){
    return isEnd;
}

void TrieNode::markAsEnd(){
    this->isEnd = true;
}

void TrieNode::addWordToSubtree(){
    this->words++;
}

bool TrieNode::checkOcupation(char checkFor){
    if(letters[checkFor - 'a'] != nullptr) return true;
    return false;
}

TrieNode* TrieNode::getPToLetter(char letter){
    return this->letters[letter - 'a'];
}

void TrieNode::addNodeAt(char addAt, TrieNode* toAdd){
    this->letters[addAt - 'a'] = toAdd;
}