// J+M+J
#pragma once
#include "TrieNode.h"

TrieNode::TrieNode(){
    this->isEnd = 0;
    for(int i = 0; i < 26; i++) letters[i] = nullptr;
}

TrieNode* TrieNode::getLetter(int i){
    return this->letters[i];
}

bool TrieNode::isEndOfWord(){
    return isEnd;
}

void TrieNode::markAsEnd(){
    this->isEnd = true;
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