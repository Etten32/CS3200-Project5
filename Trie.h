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
 * int completeCount(string wordPart) - RECURSIVE IMPLEMENTATION
 *      Postcondition: returns number of words starting with Trie::completeCount().wordPart
 * 
 * vector<string> complete(string wordPart)
 *      Postcondition: returns vector full of all the words that start with Trie::complete().wordPart
 *      Dependancies: Trie::completeH()
 * 
 * MUTATION: FUNCTIONS:
 * bool insert(string toInsert)
 *      Postcondition: //* DOCUMENTATION NEEDED
 *      Dependancies: Trie::insertH()
 * 
 * void clearBelow(TrieNode* nodeAt) - RECURSIVE IMPLEMENTATION
 *      Postcondition: //* DOCUMENTATION NEEDED
 * 
 * *v*v*v*v* PRIVATE: *v*v*v*v*
 * INFORMATION: FUNCTIONS:
 * bool findH(string toFind, TrieNode* nodeAt)
 *      Postcondition: //* DOCUMENTATION NEEDED
 * 
 * vector<string> completeH(string wordPart, TrieNode* nodeAt) ///USE THIS->VECTOR + RECURSIVE VECTOR TO GET VECTOR
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