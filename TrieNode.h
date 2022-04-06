//J+M+J
/** FILE: TrieNode.h
 * CLASS: PROVIDED: TRIENODE
 * DEPENDANCY: FILES: NONE
 * -<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-<=>-
 * FUNCTIONS:
 * *v*v*v*v* PUBLIC: *v*v*v*v*
 * CONSTRUCTORS:
 * TrieNode()
 *      Postcondition: the following is initialized:
 *                      TrieNode::isEnd = 0
 *                      TridNode::letters[0-26] = nullptr
 *                      TrieNode::words = 0
 * 
 * DESTRUCTOR:
 * ~Trie()
 *      Postcondition: no action: use Trie::~() takes care of deleting interior TrieNodes
 * 
 * INFORMATION: FUNCTIONS:
 * TrieNode* getLetter(int i)
 *      Postcondition: returns this->letter[i]
 * 
 * int getWordsAt()
 *      Postcondition: returns this->words
 * 
 * bool isEndOfWord()
 *      Postcondition: return this->isEnd
 * 
 * bool checkOcupation(char checkFor)
 *      Postcondition: returns true if TrieNode::checkOcupation().checkFor pointer in 'this' is already ocupied
 *                     returns false otherwise
 * 
 * MUTATION: FUNCTIONS:
 * void markAsEnd()
 *      Postcondition: marks this->isEnd as true
 * 
 * void addWordToSubtree()
 *      Postcondition: adds one to TrieNode.words (words in subtree of this node)
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
    public:                                         //-------------------------------------------------------------------
    TrieNode();                                     //initializes the node

    TrieNode* getLetter(int i);                     //returns the pointer to the letter that corrasponds with index i

    int getWordsAt();                               //returns the number of words in subtree of this node

    bool isEndOfWord();                             //returns if this node marks the end of a word

    void markAsEnd();                               //changes this node as now marking the end of a word

    void addWordToSubtree();                        //increases amount of words contained in this subtree by 1

    bool checkOcupation(char checkFor);             //checks if the pointer for the corrasponding letter is !nullptr and return true it is occupied or false if nullptr

    TrieNode* getPToLetter(char letter);            //returns the pointer value in this node to the input letter

    void addNodeAt(char addAt, TrieNode* toAdd);    //adds addNodeAt().toAdd to this node at letter pointer matching with addAt

    private:                                        //-------------------------------------------------------------------
    bool isEnd;                                     //if this node marks the end of a word
    TrieNode* letters[26];                          //the pointers to all the letter nodes of this node                             /syntax help obtained from family member
    int words;                                      //number of words in this nodes subtree (aka, number of isEnd == true markers)  / number of words in the subtree (inclusive of node)
};