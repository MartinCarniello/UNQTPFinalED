#include "LinkedListForTree.h"

struct ListForTreeStr {
    ELEM_TYPE elem;
    ListForTree next;
};

ListForTree singleton(ELEM_TYPE x, ListForTree xs) {
    ListForTree nuevaLista = new ListForTreeStr;
    nuevaLista -> elem = x;
    nuevaLista -> next = xs;
    return nuevaLista;
}

ListForTree NilForTree() {
    return NULL;
}

bool isNil(ListForTree xs) {
    return xs == NULL;
}

void tkTail(ListForTree& xs) {
    ListForTree listaARemover = xs;
    xs = xs -> next;
    delete(listaARemover);
}

ELEM_TYPE head(ListForTree xs) {
    return xs -> elem;
}

void mkSnoc(ELEM_TYPE x, ListForTree& xs) {
    xs = singleton(x, xs);
}

struct RecorridoForTreeStr {
    ListForTree current;
};

RecorridoForTree initialize(ListForTree xs) {
    RecorridoForTree recorrido = new RecorridoForTreeStr;
    recorrido -> current = xs;
    return recorrido;
}

ELEM_TYPE getCurrent(RecorridoForTree r) {
    return head(r -> current);
}

bool finished(RecorridoForTree r) {
    return isNil(r -> current);
}

void next(RecorridoForTree& r) {
    r -> current = r -> current -> next;
}

void finish(RecorridoForTree& r) {
    delete(r);
}

int size(ListForTree xs) {
    RecorridoForTree recorrido = initialize(xs);
    int size = 0;
    while(!finished(recorrido)) {
        size++;
        next(recorrido);
    }

    finish(recorrido);
    return size;
}

void printList(ListForTree xs) {
    RecorridoForTree recorrido = initialize(xs);
    if(!finished(recorrido)) {
        cout << "[" << getCurrent(recorrido);
        next(recorrido);
        while(!finished(recorrido)) {
            cout << ", " << getCurrent(recorrido);
            next(recorrido);
        }
        cout << "]";
    } else {
        cout << "[]";
    }

    finish(recorrido);
}

void deleteList(ListForTree xs) {
    RecorridoForTree recorrido = initialize(xs);
    while(!finished(recorrido)) {
        ListForTree listaARemover = recorrido -> current;
        next(recorrido);
        delete(listaARemover);
    }

    finish(recorrido);
}

