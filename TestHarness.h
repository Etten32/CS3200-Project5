//J+M+J
// TEST HARNESS TO PROBE TRIE CLASS METHOD FUNCTIONALITY

#include "Trie.h"

using namespace std;

class TestHarness{
    public:
    void static testTries(){
        // uncomment any one to remove testing
        TestHarness::testConstructor();
        TestHarness::testInsert();
    }
    private:
    void static testConstructor(){
        // test Trie::Trie()
        cout << "TESTING CONSTRUCTOR" << endl;
        cout << " --- EMPTY TREE --- " << endl;
        Trie* testTrie = new Trie();
        testTrie->outputTrie(cout);
        cout << endl << endl;
    }
    void static testInsert(){
        // test Trie::insert()
        cout << "TESTING INSERT" << endl;
        Trie* testTrie = new Trie();

        cout << " --- ADDED 'yep' --- " << endl;
        cout << "Successful: " << testTrie->insert("yep") << endl;
        testTrie->outputTrie(cout);
        cout << endl;

        cout << " --- ADDED 'yep' AGAIN --- " << endl;
        cout << "Successful: " << testTrie->insert("yep") << endl;
        testTrie->outputTrie(cout);
        cout << endl;

        cout << " --- ADDED 'yes' --- " << endl;
        cout << "Successful: " << testTrie->insert("yes") << endl;
        testTrie->outputTrie(cout);
        cout << endl;

        cout << " --- ADDED 'yepper' --- " << endl;
        cout << "Successful: " << testTrie->insert("yepper") << endl;
        testTrie->outputTrie(cout);
        cout << endl;

        cout << " --- ADDED 'pepper' --- " << endl;
        cout << "Successful: " << testTrie->insert("pepper") << endl;
        testTrie->outputTrie(cout);
        cout << endl;

        cout << " --- ADDED 'yipeatseo' --- " << endl;
        cout << "Successful: " << testTrie->insert("yipeatseo") << endl;
        testTrie->outputTrie(cout);
        
        cout << endl << endl;
    }
};