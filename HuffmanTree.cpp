#include "HuffmanTree.h"
#include "LinkedListForTree.h"
#include "ZipTable.h"

//Invariante de representacion:
//Puede ser hoja, por lo cual tiene un caracter asociado.
//Puede no ser hoja, por lo cual no tiene un caracter asociado.
//Si es hoja, entonces "leftTree" y "rightTree" deben ser NULL.
//Si no es hoja, entonces "leftTree" y "rightTree" deben ser distintos de NULL.
struct HuffmanTreeStr {
    int weight;
    char character;
    HuffmanTree leftTree;
    HuffmanTree rightTree;
};

HuffmanTree singletonWithoutCharacter(int w, HuffmanTree left, HuffmanTree right) {
    HuffmanTree newTree = new HuffmanTreeStr;
    newTree -> weight = w;
    newTree -> leftTree = NULL;
    newTree -> rightTree = NULL;
    return newTree;
}

bool isNil(HuffmanTree tree) {
    return tree == NULL;
}

bool isLeaf(HuffmanTree tree) {
    return tree -> leftTree == NULL && tree -> rightTree == NULL;
}

HuffmanTree leaf(char c, int w) {
    HuffmanTree treeToRet = singletonWithoutCharacter(w, NULL, NULL);
    treeToRet -> character = c;
    return treeToRet;
}

//Precondicion: Los arboles no deben ser NULL
HuffmanTree binary(HuffmanTree a, HuffmanTree b) {
    return singletonWithoutCharacter(weight(a) + weight(b), a, b);
}

void deleteHuffmanTree(HuffmanTree& t) {
    HuffmanTree current = t;
    ListForTree pendientes = NilForTree();
    mkSnoc(current, pendientes);

    while(not isNil(pendientes)) {
        current = head(pendientes);
        tkTail(pendientes);

        if(not isNil(current -> leftTree))
            mkSnoc(current -> leftTree, pendientes);

        if(not isNil(current -> rightTree))
            mkSnoc(current -> rightTree, pendientes);

        delete(current);
    }
}

int weight(HuffmanTree t) {
    return t -> weight;
}

//ZipTable buildTable(HuffmanTree t) {
//    BitChain bitChain = emptyBitChain();
//    ZipTable table = emptyZipTable();
//
//    if(isLeaf(t)) {
//        add(table, t -> character, bitChain);
//    } else {
//        if(!isNil(t -> leftTree)) {
//            append(bitChain, false);
//            buildTable(t -> leftTree);
//        }
//
//        if(!isNil(t -> rightTree)) {
//            append(bitChain, true);
//            buildTable(t -> rightTree);
//        }
//    }
//}
