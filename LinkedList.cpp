#include "LinkedList.h"

struct ListStr {
    ELEM_TYPE elem;
    List next;
};

List singleton(ELEM_TYPE x, List xs) {
    List nuevaLista = new ListStr;
    nuevaLista -> elem = x;
    nuevaLista -> next = xs;
    return nuevaLista;
}

List Nil() {
    return NULL;
}

bool isNil(List xs) {
    return xs == NULL;
}

void tkTail(List& xs) {
    List listaARemover = xs;
    xs = xs -> next;
    delete(listaARemover);
}

ELEM_TYPE head(List xs) {
    return xs -> elem;
}

void mkSnoc(ELEM_TYPE x, List& xs) {
    xs = singleton(x, xs);
}

struct RecorridoStr {
    List current;
};

Recorrido initialize(List xs) {
    Recorrido recorrido = new RecorridoStr;
    recorrido -> current = xs;
    return recorrido;
}

ELEM_TYPE getCurrent(Recorrido r) {
    return head(r -> current);
}

bool finished(Recorrido r) {
    return isNil(r -> current);
}

//Aunque se tiene una funcion "tkTail()" en las listas,
//la misma no se utiliza para no destruirla, de esta manera
//gano por el lado de que
//logro avanzar al siguiente nodo sin romper la estructura
//pero pierdo rompiendo la barrera de abstraccion
void nextList(Recorrido& r) {
    r -> current = r -> current -> next;
}

void finish(Recorrido& r) {
    delete(r);
}

int size(List xs) {
    Recorrido recorrido = initialize(xs);
    int size = 0;
    while(!finished(recorrido)) {
        size++;
        nextList(recorrido);
    }

    finish(recorrido);
    return size;
}

void printList(List xs) {
    Recorrido recorrido = initialize(xs);
    if(!finished(recorrido)) {
        cout << "[" << getCurrent(recorrido);
        nextList(recorrido);
        while(!finished(recorrido)) {
            cout << ", " << getCurrent(recorrido);
            nextList(recorrido);
        }
        cout << "]";
    } else {
        cout << "[]";
    }

    finish(recorrido);
}

void deleteList(List xs) {
    Recorrido recorrido = initialize(xs);
    while(!finished(recorrido)) {
        List listaARemover = recorrido -> current;
        nextList(recorrido);
        delete(listaARemover);
    }

    finish(recorrido);
}
