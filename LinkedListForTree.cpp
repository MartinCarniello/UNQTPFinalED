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
