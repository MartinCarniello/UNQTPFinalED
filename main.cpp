#include <iostream>
#include "LinkedList.test.h"
#include "CharBag.test.h"
#include "HuffmanTree.test.h"
#include "PriorityQueue.test.h"

using namespace std;

void corridaDeTests() {

    int passedTests = 0;

    cout << "Corrida de tests" << endl << endl;
    cout << "TESTS DE LISTA" << endl << endl;

    passedTests += testNil();
    passedTests += testIsNil();
    passedTests += testHead();
    passedTests += testMkSnoc();
    passedTests += testSizeList();

    cout << endl;
    cout << "TESTS DE ITERADOR DE LISTA" << endl << endl;

    passedTests += testGetCurrent();
    passedTests += testFinished();
    passedTests += testNext();

    cout << endl;
    cout << "TESTS DE CHARBAG" << endl << endl;

    passedTests += testEmptyCharBag();
    passedTests += testAddGet();

    cout << endl;
    cout << "TESTS DE ITERADOR DE CHARBAG" << endl << endl;

    passedTests += testValid();
    passedTests += testCurrentChar();
    passedTests += testCurrentCount();

    cout << endl;
    cout << "TESTS DE HUFFMANTREE" << endl << endl;

    passedTests += testLeaf();
    passedTests += testBinary();
    passedTests += testWeight();

    cout << endl;
    cout << "TESTS DE PRIORITYQUEUE" << endl << endl;

    passedTests += testEmptyPriorityQueue();
    passedTests += testSize();
    passedTests += testEnqueue();
    passedTests += testDequeue();

    cout << endl;

    cout << "Cantidad de tests pasados: " << passedTests << endl;
}


//int main() {
//    corridaDeTests();
//
//    return 0;
//}
