#include "PriorityQueue.h"
#include <iostream>
#include <stdlib.h>

//Invariante de representacion:
//- El campo capacity es la cantidad de elementos que soporta el array, por lo tanto esta no varia.
//- El campo position es la posicion donde va a ser alojado en memoria el siguiente elemento
//  que se agregue a la cola. La primera vez que se quiera agregar algo a la cola
//  va a ser alojado en la posicion 1, ya que en la 0 se guarda el elemento con el
//  valor mas chico a comparar.
//- El tamanio de la cola siempre va a ser dado por el campo position.
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
    //Se genera el elemento con valor a comparar mas chico para alojar en la posicion 0
    newPriorityQueue -> trees[0] = leaf('a', 0);
    return newPriorityQueue;
}

void deletePriorityQueue(PriorityQueue& q) {
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

    //Si la cola esta llena, lanza un "error"
    if(isFull(q)) {
        std::cout << "ERROR: " << size(q) << " == " << q -> capacity << std::endl;
        exit(1);
    }

    //Suma uno a la posicion, y lo guarda en una variable. Es la posicion donde se alojara el elemento
    i = ++(q -> position);

    //Se recorre de atras para adelante, hasta que encuentre un elemento que tenga un valor
    //mas chico del elemento que se quiere agregar
    while(weight(q -> trees[i/2]) > weight(tree)) {
        q -> trees[i] = q -> trees[i/2];
        i = i/2;
    }

    //Cuando lo encuentra, lo guarda en esa posicion
    q -> trees[i] = tree;
}

HuffmanTree dequeue(PriorityQueue& q) {
    int i, child;

    //Si la cola esta vacia, lanza un "error"
    if(size(q) == 0) {
        std::cout << "ERROR: Size == " << size(q) << std::endl;
        exit(1);
    }

    //Se guardan los elementos con valor mas chico y mas grande
    //Tambien se decrementa la posicion donde se va a alojar el siguiente elemento
    HuffmanTree minElem = q -> trees[1];
    HuffmanTree lastElem = q -> trees[q -> position--];

    //Se recorre de adelante para atras, hasta que se encuentra la posicion donde meter el ultimo elemento
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

    //Agrego el ultimo elemento en la posicion encontrada anteriormente
    q -> trees[i] = lastElem;

    return minElem;
}
