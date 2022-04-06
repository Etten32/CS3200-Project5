//J+M+J
// TEST HARNESS TO PROBE TRIE CLASS METHOD FUNCTIONALITY

#include "Trie.h"

using namespace std;

class TestHarness{
    public:
    //main testing method
    void static testTries(){
        // comment any one to remove testing
        cout << "==================================================" << endl << endl;
        TestHarness::testConstructor();
        cout << "==================================================" << endl << endl;
        TestHarness::testGetters();
        cout << "==================================================" << endl << endl;
        TestHarness::testInsert();
        cout << "==================================================" << endl << endl;
        //TestHarness::testClear();                                                     //make Trie->root variable public in order to test
        //cout << "==================================================" << endl << endl;
        TestHarness::testCompleteCount();
        cout << "==================================================" << endl << endl;
        TestHarness::testComplete();
        cout << "==================================================" << endl << endl;
        TestHarness::testFind();

    }
    private:
    //individual testing methods (refer to output text and names for functionings)
    void static testConstructor(){
        // test Trie::Trie()
        cout << "TESTING CONSTRUCTOR" << endl;
        cout << " --- EMPTY TREE --- " << endl;
        Trie* testTrie = new Trie();
        testTrie->outputTrie(cout);
        cout << endl << endl;
        delete(testTrie);
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
        //testTrie->clearFrom(testTrie->root);                                          //make Trie->root variable public in order to test
        cout << "0 NODES: " << testTrie->getSize() << endl;
        testTrie->insert("test");
        cout << "0 NODES: " << testTrie->getSize() << endl;

        cout << endl;

        delete(testTrie);
    }
    
    void static testCompleteCount(){
        Trie* testTrie = new Trie();

        cout << "TESTING COMPLETECOUNT()" << endl;

        // testing Trie::completeCount()
        testTrie->insert("a");
        testTrie->insert("an");
        testTrie->insert("ant");
        testTrie->insert("anti");

        cout << " --- TEST-0: CALLING COMPLETECOUNT --- " << endl;
        cout << "Expected: 2" << endl;
        cout << "Recieved: " << testTrie->completeCount("ant") << endl;

        testTrie->insert("anteater");
        cout << " --- TEST-1: CALLING COMPLETECOUNT --- " << endl;
        cout << "Expected: 3" << endl;
        cout << "Recieved: " << testTrie->completeCount("ant") << endl;

        testTrie->insert("alps");
        cout << " --- TEST-2: CALLING COMPLETECOUNT --- " << endl;
        cout << "Expected: 6" << endl;
        cout << "Recieved: " << testTrie->completeCount("a") << endl;

        cout << endl;
        delete(testTrie);
    }
    
    void static testComplete(){
        Trie* testTrie = new Trie();

        cout << "TESTING COMPLETE()" << endl;

        // testing Trie::complete()
        testTrie->insert("a");
        testTrie->insert("an");
        testTrie->insert("ant");
        testTrie->insert("anti");

        cout << " --- TEST-0: CALLING COMPLETE --- " << endl;
        cout  << "EXPECTED: v v v" << endl
            << "ant" << endl
            << "anti" << endl;
        cout << endl << "RECIEVED: v v v" << endl;
        vector<string> store = testTrie->complete("ant");
        for(int i = 0; i < store.size(); i++) cout << store[i] << endl;
        cout << endl;

        testTrie->insert("anteater");
        cout << " --- TEST-1: CALLING COMPLETE --- " << endl;
        cout << "EXPECTED: v v v" << endl
            << "ant" << endl
            << "anti" << endl
            << "anteater" << endl;
        cout << endl << "RECIEVED: v v v" << endl;
        store = testTrie->complete("ant");
        for(int i = 0; i < store.size(); i++) cout << store[i] << endl;
        cout << endl;

        testTrie->insert("alps");
        cout << " --- TEST-2: CALLING COMPLETE --- " << endl;
        cout << "EXPECTED: v v v" << endl
            << "a" << endl
            << "alps" << endl
            << "an" << endl
            << "ant" << endl
            << "anteater" << endl
            << "anti" << endl;
        cout << endl << "RECIEVED: v v v" << endl;
        store = testTrie->complete("a");
        for(int i = 0; i < store.size(); i++) cout << store[i] << endl;
        cout << endl;

        cout << endl;
        delete(testTrie);
    }
    
    void static testFind(){
        // test Trie::find()
        cout << "TESTING FIND()" << endl;
        cout << " --- TESTING ON EMPTY TREE --- " << endl;
        Trie* testTrie = new Trie();
        cout << "EXPECTED: 0" << endl;
        cout << "RECIEVED: " << testTrie->find("a") << endl;

        cout << " --- TEST-0: EXISTING NODE, NON-WORD --- " << endl;
        testTrie->insert("a");
        testTrie->insert("an");
        testTrie->insert("anne");
        testTrie->insert("app");
        testTrie->insert("alp");
        cout << "EXPECTED: 0" << endl;
        cout << "RECIEVED: " << testTrie->find("al") << endl;

        cout << " --- TEST-1: NON-NODE, NON-WORD --- " << endl;
        cout << "EXPECTED: 0" << endl;
        cout << "RECIEVED: " << testTrie->find("alpha") << endl;

        cout << " --- TEST-2: EXISTING NODE, EXISTING EDGE WORD --- " << endl;
        cout << "EXPECTED: 1" << endl;
        cout << "RECIEVED: " << testTrie->find("anne") << endl;

        cout << " --- TEST-3: EXISTING NODE, EXISTING INTERIOR WORD --- " << endl;
        cout << "EXPECTED: 1" << endl;
        cout << "RECIEVED: " << testTrie->find("an") << endl;

        delete(testTrie);
    }
};