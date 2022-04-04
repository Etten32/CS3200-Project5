//J+M+J
/** FILE: TrieNode.h
 * CLASS: PROVIDED: TRIENODE
 * DEPENDANCY: FILES: NONE
 * -<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-
 * FUNCTIONS:
 * *v*v*v*v* PUBLIC: *v*v*v*v*
 * CONSTRUCTORS:
 * TrieNode()
 *      Postcondition: //* DOCUMENTATION NEEDED
 * 
 * DESTRUCTOR:
 * ~Trie()
 *      Postcondition: //* DOCUMENTATION NEEDED
 * 
 * INFORMATION: FUNCTIONS:
 * TrieNode* getLetter(int i)
 *      Postcondition: returns this->letter[i]
 * 
 * bool isEndOfWord()
 *      Postcondition: return isEnd
 * 
 * bool checkOcupation(char checkFor)
 *      Postcondition: returns true if TrieNode::checkOcupation().checkFor pointer in 'this' is already ocupied
 *                     returns false otherwise
 * 
 * MUTATION: FUNCTIONS:
 * void markAsEnd()
 *      Postcondition: marks this->isEnd as true
 * 
 * TrieNode* getPToLetter(char letter)
 *      Postcondition: returns pointer to node that matches this->letters[] index of TrieNode->letter - 'a'
 * 
 * void addNodeAt(char addAt, TrieNode* toAdd)
 *      Postcondition: adds node to this->letters[] at index of TrieNode->addAt - 'a'
 * 
 * *v*v*v*v* PRIVATE: *v*v*v*v*
 * INFORMATION: FUNCTIONS:
 * 
 * 
 * MUTATION: FUNCTIONS:
 * 
 * 
 * -<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-
 * VARIABLES:
 * *v*v*v*v* PRIVATE: *v*v*v*v*
 * bool isEnd
 *      To signify if this node is the end of a word
 * 
 * TrieNode[26] letterArray
 *      An array of pointers to other nodes, one for each alaphabet letter
 * */
#pragma once
class TrieNode{
    public:
    TrieNode();

    TrieNode* getLetter(int i);

    bool isEndOfWord();

    void markAsEnd();

    bool checkOcupation(char checkFor);

    TrieNode* getPToLetter(char letter);

    void addNodeAt(char addAt, TrieNode* toAdd);

    private:
    bool isEnd;
    TrieNode* letters[26];              //syntax help obtained from family member
    int subTreeWords;                   // number of words in the subtree (inclusive of node)
};