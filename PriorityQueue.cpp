#include "PriorityQueue.h"

struct PriorityQueueStr {
    HuffmanTree* trees;
    int capacity;
    int position;
};

PriorityQueue emptyPriorityQueue() {
    PriorityQueue newPriorityQueue = new PriorityQueueStr;
    newPriorityQueue -> capacity = 1;
    newPriorityQueue -> trees = new HuffmanTree[newPriorityQueue -> capacity + 1];
    newPriorityQueue -> trees[0] = leaf('a', 0);
    newPriorityQueue -> position = 0;
    return newPriorityQueue;
}

void deletePriorityQueue(PriorityQueue& q) {
    for(int i = 0; i < q -> capacity; i++)
        deleteHuffmanTree(q -> trees[i]);

    delete(q);
}

int size(PriorityQueue q) {
    return q -> position;
}

void resize(PriorityQueue& q) {
    q -> capacity = q -> capacity * 2;
    HuffmanTree* newTrees = new HuffmanTree[q -> capacity + 1];

    for(int i = 1; i < (q -> capacity / 2 + 1); i++)
        newTrees[i] = q -> trees[i];

    delete[] q -> trees;
    q -> trees = newTrees;
}

void enqueue(PriorityQueue& q, HuffmanTree tree) {
    if(q -> capacity == q -> position)
        resize(q);

    int i = ++(q -> position);

    while(weight(q -> trees[i/2]) > weight(tree)) {
		q -> trees[i] = q -> trees[i/2];
		i = i/2;
	}

	q -> trees[i] = tree;
}

//precondicion: La cola no debe ser vacia
HuffmanTree dequeue(PriorityQueue& q) {
    int i, child;
    HuffmanTree minElem = q -> trees[1];
	HuffmanTree lastElem = q -> trees[q -> position--];

	for(i = 1; i * 2 <= q -> position; i = child){
        child = i * 2;
        if(child != q -> position && weight(q -> trees[child + 1]) < weight(q -> trees[child]))
            child++;

        if(weight(lastElem) > weight(q -> trees[child])){
            q -> trees[i] = q -> trees[child];
        } else {
            break;
        }
    }

	q -> trees[i] = lastElem;

	return minElem;
}
