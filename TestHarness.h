//J+M+J
// TEST HARNESS TO PROBE TRIE CLASS METHOD FUNCTIONALITY

#include "Trie.h"

using namespace std;

class TestHarness{
    public:
    void static testTries(){
        // comment any one to remove testing
        TestHarness::testConstructor();
        TestHarness::testGetters();
        TestHarness::testInsert();
        TestHarness::testClear();
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
        delete(testTrie);
    }
    void static testGetters(){
        Trie* testTrie0 = new Trie();
        Trie* testTrie1 = new Trie();

        cout << "TESTING GETTERS" << endl;

        // testing Trie::count()
        cout << " --- CALLING COUNT(): # OF WORDS --- " << endl;
        cout << "EMPTY: " << testTrie0->count() << endl;
        testTrie0->insert("a");
        cout << "1 WORD: " << testTrie0->count() << endl;
        testTrie0->insert("be");
        testTrie0->insert("ah");
        cout << "3 WORDS: " << testTrie0->count() << endl;
        cout << endl;

        // testing Trie::getSize()
        cout << " --- CALLING GETSIZE(): # OF NODES --- " << endl;
        cout << "1 NODE: " << testTrie1->getSize() << endl;
        testTrie1->insert("a");
        cout << "2 NODES: " << testTrie1->getSize() << endl;
        testTrie1->insert("be");
        testTrie1->insert("ah");
        cout << "5 NODES: " << testTrie1->getSize() << endl;
        cout << endl;

        delete(testTrie0);
        delete(testTrie1);
    }
    void static testClear(){
        // testing Trie::clear()
        Trie* testTrie = new Trie();

        cout << " --- TESTING CLEAR() --- " << endl;
        cout << "1 NODE: " << testTrie->getSize() << endl;
        testTrie->insert("a");
        testTrie->insert("i");
        cout << "3 NODES: " << testTrie->getSize() << endl;
        testTrie->clearFrom(testTrie->root);
        cout << "0 NODES: " << testTrie->getSize() << endl;
        testTrie->insert("test");
        cout << "0 NODES: " << testTrie->getSize() << endl;

        cout << endl;

        delete(testTrie);
    }
};