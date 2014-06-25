#include "PriorityQueue.h"
#include <iostream>
#include <stdlib.h>

struct PriorityQueueStr {
    HuffmanTree* trees;
    int capacity;
    int position;
};

PriorityQueue emptyPriorityQueue() {
    PriorityQueue newPriorityQueue = new PriorityQueueStr;
    newPriorityQueue -> capacity = 256;
    newPriorityQueue -> position = 0;
    newPriorityQueue -> trees = new HuffmanTree[newPriorityQueue -> capacity + 1];
    newPriorityQueue -> trees[0] = leaf('a', 0);
    return newPriorityQueue;
}

void deletePriorityQueue(PriorityQueue& q) {
//    for(int i = 0; i < q -> capacity; i++) {
//        std::cout << "asd" << std::endl;
//        std::cout << "Se borro el " << i << std::endl;
//        deleteHuffmanTree(q -> trees[i]);
//    }

    delete[] q -> trees;
    delete(q);
}

int size(PriorityQueue q) {
    return q -> position;
}

bool isFull(PriorityQueue q) {
  return size(q) == q -> capacity;
}

void enqueue(PriorityQueue& q, HuffmanTree tree) {
    int i;

    if(isFull(q)) {
        std::cout << "ERROR: " << size(q) << " == " << q -> capacity << std::endl;
        exit(1);
    }

    i = ++(q -> position);

    while(weight(q -> trees[i/2]) > weight(tree)) {
        q -> trees[i] = q -> trees[i/2];
        i = i/2;
    }

    q -> trees[i] = tree;
}

//precondicion: La cola no debe ser vacia
HuffmanTree dequeue(PriorityQueue& q) {
    int i, child;

    if(size(q) == 0) {
        std::cout << "ERROR: Size == " << size(q) << std::endl;
        exit(1);
    }

    HuffmanTree minElem = q -> trees[1];
    HuffmanTree lastElem = q -> trees[q -> position--];

    for(i = 1; i * 2 <= q -> position; i = child){
        child = i * 2;
        if(child != q -> position && weight(q -> trees[child + 1]) < weight(q -> trees[child])) {
            child++;
        }

        if(weight(lastElem) > weight(q -> trees[child])){
            q -> trees[i] = q -> trees[child];
        } else {
            break;
        }
    }

    q -> trees[i] = lastElem;

    return minElem;
}
