#include "HuffmanTree.h"

#include <iostream>
#include <stdlib.h>
#include <assert.h>

int testLeaf() {
    HuffmanTree leaf1 = leaf('a', 4);
    assert(weight(leaf1) == 4);
    std::cout << "testLeaf - OK" << std::endl;
    return 1;
}

int testBinary() {
    HuffmanTree leaf1 = leaf('a', 4);
    HuffmanTree leaf2 = leaf('b', 5);
    HuffmanTree tree1 = binary(leaf1, leaf2);
    assert(weight(tree1) == 9);
    std::cout << "testBinary - OK" << std::endl;
    return 1;
}

int testWeight() {
    HuffmanTree leaf1 = leaf('a', 4);
    HuffmanTree leaf2 = leaf('b', 5);
    HuffmanTree tree1 = binary(leaf1, leaf2);

    HuffmanTree leaf3 = leaf('c', 2);
    HuffmanTree leaf4 = leaf('d', 3);
    HuffmanTree tree2 = binary(leaf3, leaf4);

    HuffmanTree tree3 = binary(tree1, tree2);

    assert(weight(tree3) == 14);
    std::cout << "testWeight - OK" << std::endl;
    return 1;
}

int testBuildTable() {
    HuffmanTree leaf1 = leaf('a', 4);
    HuffmanTree leaf2 = leaf('b', 5);
    HuffmanTree leaf3 = leaf('c', 5);
    HuffmanTree leaf4 = leaf('d', 5);
    HuffmanTree tree1 = binary(leaf1, leaf2);
    HuffmanTree tree2 = binary(leaf3, leaf4);
    HuffmanTree tree3 = binary(tree1, tree2);

    buildTable(tree3);

//    BitChain bitChain = getBitChain(zipTable);
//
//    bitChain[0]

    std::cout << "testBuildTable - OK" << std::endl;

    return 0;
}
