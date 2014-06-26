#include "HuffmanTree.h"
#include "LinkedListForTree.h"
#include "ZipTable.h"

#include <iostream>

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

//Crea un HuffmanTree sin caracter asociado
HuffmanTree singletonWithoutCharacter(int w, HuffmanTree left, HuffmanTree right) {
    HuffmanTree newTree = new HuffmanTreeStr;
    newTree -> weight = w;
    newTree -> leftTree = left;
    newTree -> rightTree = right;
    return newTree;
}

bool isNil(HuffmanTree tree) {
    return tree == NULL;
}

//Retorna true si ambos hijos del HuffmanTree son NULL
bool isLeaf(HuffmanTree tree) {
    return (isNil(tree -> leftTree)) && (isNil(tree -> rightTree));
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
    //Para no usar la recursion, se iteran los arboles borrandose y guardando los
    //hijos en una lista auxiliar de pendientes para poder iterarlos luego
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

ZipTable buildTableAux(ZipTable zipTable, HuffmanTree tree, BitChain bitChain) {
    //Si es hoja, termino el recorrido y agrego el caracter con su cadena a la tabla
    if(isLeaf(tree)) {
        add(zipTable, tree -> character, bitChain);
    } else {
        //Recorro el arbol izquierdo
        append(bitChain, false);
        buildTableAux(zipTable, tree -> leftTree, bitChain);
        remove(bitChain);
        //Recorro el arbol derecho
        append(bitChain, true);
        buildTableAux(zipTable, tree -> rightTree, bitChain);
        remove(bitChain);
    }

    return zipTable;
}

ZipTable buildTable(HuffmanTree t) {
    ZipTable zipTable = emptyZipTable();
    BitChain bitChain = emptyBitChain();
    //Llamo a una funcion auxiliar para que sea recursiva
    return buildTableAux(zipTable, t, bitChain);
}

