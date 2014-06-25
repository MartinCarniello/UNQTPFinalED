#include "PriorityQueue.h"

#include <iostream>
#include <stdlib.h>
#include <assert.h>

int testEmptyPriorityQueue() {
    PriorityQueue pq = emptyPriorityQueue();
    assert(size(pq) == 0);
    std::cout << "testEmptyPriorityQueue - OK" << std::endl;
    return 1;
}

int testSize() {
    PriorityQueue pq = emptyPriorityQueue();
    assert(size(pq) == 0);
    HuffmanTree leaf1 = leaf('a', 4);
    enqueue(pq, leaf1);
    assert(size(pq) == 1);
    std::cout << "testSize - OK" << std::endl;
    return 1;
}

int testEnqueue() {
//    PriorityQueue pq = emptyPriorityQueue();
//    assert(size(pq) == 0);
//    HuffmanTree leaf1 = leaf('a', 4);
//    enqueue(pq, leaf1);
//    assert(size(pq) == 1);
//    HuffmanTree leaf2 = leaf('b', 5);
//    dequeue(pq);
//    assert(size(pq) == 0);
//    enqueue(pq, leaf2);
//    assert(size(pq) == 1);

    HuffmanTree leaf1 = leaf('a', 1);
    HuffmanTree leaf2 = leaf('l', 1);
    HuffmanTree leaf3 = leaf('o', 1);
    HuffmanTree leaf4 = leaf('h', 1);

    PriorityQueue pq = emptyPriorityQueue();
    enqueue(pq, leaf1);
    enqueue(pq, leaf2);
    enqueue(pq, leaf3);
    enqueue(pq, leaf4);

    std::cout << size(pq) << std::endl;

    while (size(pq) > 1) {
        HuffmanTree a = dequeue(pq);
        HuffmanTree b = dequeue(pq);
        enqueue(pq, binary(a,b));
    }

    std::cout << "testEnqueue - OK" << std::endl;
    return 1;
}

int testDequeue() {
    PriorityQueue pq = emptyPriorityQueue();
    HuffmanTree leaf1 = leaf('a', 1);
    HuffmanTree leaf2 = leaf('b', 2);
    HuffmanTree leaf3 = leaf('b', 3);
    HuffmanTree leaf4 = leaf('b', 5);
    HuffmanTree leaf5 = leaf('b', 6);
    HuffmanTree leaf6 = leaf('b', 4);
    enqueue(pq, leaf1);
    enqueue(pq, leaf2);
    enqueue(pq, leaf3);
    enqueue(pq, leaf4);
    enqueue(pq, leaf5);
    enqueue(pq, leaf6);
    assert(weight(dequeue(pq)) == 1);
    assert(weight(dequeue(pq)) == 2);
    assert(weight(dequeue(pq)) == 3);
    assert(weight(dequeue(pq)) == 4);
    assert(weight(dequeue(pq)) == 5);
    assert(weight(dequeue(pq)) == 6);
    HuffmanTree prueba = leaf('z', 1);
    enqueue(pq, prueba);
    std::cout << "testDequeue - OK" << std::endl;
    return 1;
}
