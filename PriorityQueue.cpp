#include "PriorityQueue.h"

struct PriorityQueueStr {
    HuffmanTree* trees;
    int capacity;
    int position;
};

PriorityQueue emptyPriorityQueue() {
    PriorityQueue newPriorityQueue = new PriorityQueueStr;
    newPriorityQueue -> capacity = 1;
    newPriorityQueue -> trees = new HuffmanTree[newPriorityQueue -> capacity];
    //ES NECESARIO ASIGNAR NULL A TODAS LAS POSICIONES CUANDO INICIALIZO?
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
    HuffmanTree* newTrees = new HuffmanTree[q -> capacity];
    //ES NECESARIO ASIGNAR NULL EN TODAS LAS POSICIONES
    //QUE NO TIENEN UN ARBOL ASIGNADO?
    for(int i = 0; i < (q -> capacity / 2); i++)
        newTrees[i] = q -> trees[i];
    delete[] q -> trees;
    q -> trees = newTrees;
}

void enqueue(PriorityQueue& q, HuffmanTree t) {
    if(q -> capacity == q -> position)
        resize(q);

    q -> trees[q -> position] = t;
    int positionToPut = q -> position;

    if(positionToPut != 0) {
        int parentPosition = (positionToPut) / 2;
        while(weight(t) < weight(q -> trees[parentPosition])) {
            HuffmanTree parent = q -> trees[parentPosition];
            q -> trees[parentPosition] = t;
            q -> trees[positionToPut] = parent;
            if(parentPosition == 0)
                break;
            positionToPut = parentPosition;
            parentPosition = parentPosition / 2;
        }
    }

    q -> position = q -> position + 1;
}

//precondicion: La cola no debe ser vacia
HuffmanTree dequeue(PriorityQueue& q) {
    HuffmanTree ret = q -> trees[0];

    for(int i = 0; i < q -> position; i++)
        q -> trees[i] = q -> trees[i + 1];

    q -> position = q -> position - 1;
    //ES NECESARIO ASIGNAR NULL EN LA ULTIMA POSICION
    //QUE ANTES TENIA UN ELEMENTO Y SE MOVIO HACIA LA IZQUIERDA?

    return ret;
}
