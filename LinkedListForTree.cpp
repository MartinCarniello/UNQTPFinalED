#include "LinkedListForTree.h"

//ACLARACION: Es el mismo codigo que las LinkedList para char, con sus mismas funcionalidades.
//La diferencia es que en vez de ser listas de caracteres, estas
//son listas de arboles. Se tuvo que hacer de esta manera ya que con lo que vimos
//no podemos hacer que las listas sean "polimorficas"

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
