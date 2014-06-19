#include "LinkedList.h"

#include <iostream>
#include <stdlib.h>
#include <assert.h>

int testNil() {
    List lista = Nil();
    assert(size(lista) == 0);
    std::cout << "testNil - OK" << std::endl;
    return 1;
}

int testIsNil() {
    List lista = Nil();
    assert(isNil(lista));
    mkSnoc('a', lista);
    assert(!isNil(lista));
    std::cout << "testIsNil - OK" << std::endl;
    return 1;
}

int testTkTail() {
    List lista = Nil();
    mkSnoc('a', lista);
    tkTail(lista);
    assert(isNil(lista));
    std::cout << "testTkTail - OK" << std::endl;
    return 1;
}

int testHead() {
    List lista = Nil();
    mkSnoc('a', lista);
    mkSnoc('b', lista);
    assert(head(lista) == 'b');
    std::cout << "testHead - OK" << std::endl;
    return 1;
}

int testMkSnoc() {
    List lista = Nil();
    mkSnoc('a', lista);
    mkSnoc('b', lista);
    mkSnoc('c', lista);
    assert(head(lista) == 'c');
    std::cout << "testMkSnoc - OK" << std::endl;
    return 1;
}

int testSizeList() {
    List lista = Nil();
    assert(size(lista) == 0);
    mkSnoc('a', lista);
    assert(size(lista) == 1);
    mkSnoc('b', lista);
    assert(size(lista) == 2);
    std::cout << "testSizeList - OK" << std::endl;
    return 1;
}

int testGetCurrent() {
    List lista = Nil();
    mkSnoc('a', lista);
    Recorrido recorrido = initialize(lista);
    assert(getCurrent(recorrido) == 'a');
    std::cout << "testGetCurrent - OK" << std::endl;
    return 1;
}

int testFinished() {
    List lista = Nil();
    mkSnoc('a', lista);
    Recorrido recorrido = initialize(lista);
    assert(!finished(recorrido));
    next(recorrido);
    assert(finished(recorrido));
    std::cout << "testFinished - OK" << std::endl;
    return 1;
}

int testNext() {
    List lista = Nil();
    mkSnoc('a', lista);
    mkSnoc('b', lista);
    Recorrido recorrido = initialize(lista);
    assert(getCurrent(recorrido) == 'b');
    next(recorrido);
    assert(getCurrent(recorrido) == 'a');
    std::cout << "testNext - OK" << std::endl;
    return 1;
}
