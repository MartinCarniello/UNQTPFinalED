#include <iostream>
#include "LinkedList.h"
#include "CharBag.h"
#include "HuffmanTree.h"
#include "PriorityQueue.h"

using namespace std;

int main() {

//    List l = Nil();
//    mkSnoc('a', l);
//    mkSnoc('b', l);
//    mkSnoc('c', l);
//
//    printList(l);
//
//    deleteList(l);

//    CharBag bag = emptyCharBag(26);
//    add(bag, 'a');
//    add(bag, 'b');
//    add(bag, 'a');
//    add(bag, 'c');
//    add(bag, 'c');
//
//    CharBagIterator iterator = iterate(bag);
//    while(valid(iterator)) {
//        cout << "La cantidad de ocurrencias de " << currentChar(iterator) << " es " << currentCount(iterator) << endl;
//        next(iterator);
//    }
//
//    deleteCharBagIterator(iterator);

    HuffmanTree leaf1 = leaf('a', 4);
    HuffmanTree leaf2 = leaf('b', 5);
    HuffmanTree tree1 = binary(leaf1, leaf2);

    HuffmanTree leaf3 = leaf('c', 2);
    HuffmanTree leaf4 = leaf('d', 3);
    HuffmanTree tree2 = binary(leaf3, leaf4);

//    cout << "El peso del arbol 1 es: " << weight(tree1) << endl;
//    cout << "El peso del arbol 2 es: " << weight(tree2) << endl;

    PriorityQueue pq = emptyPriorityQueue();
    enqueue(pq, tree2);
    enqueue(pq, tree1);
    cout << "El peso del arbol 1 es: " << weight(dequeue(pq)) << endl;
    cout << "El peso del arbol 2 es: " << weight(dequeue(pq)) << endl;

    return 0;
}
