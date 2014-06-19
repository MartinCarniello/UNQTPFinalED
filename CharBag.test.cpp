#include "CharBag.h"

#include <iostream>
#include <stdlib.h>
#include <assert.h>

int testEmptyCharBag() {
    CharBag bag = emptyCharBag(256);
    assert(get(bag, 'a') == 0);
    assert(get(bag, 'b') == 0);
    std::cout << "testEmptyCharBag - OK" << std::endl;
    return 1;
}

int testAddGet() {
    CharBag bag = emptyCharBag(256);
    add(bag, 'a');
    assert(get(bag, 'a') == 1);
    add(bag, 'a');
    assert(get(bag, 'a') == 2);
    add(bag, 'b');
    assert(get(bag, 'b') == 1);
    std::cout << "testAddGet - OK" << std::endl;
    return 1;
}

int testValid() {
    CharBag bag = emptyCharBag(256);
    add(bag, 'a');
    add(bag, 'b');
    add(bag, 'a');

    CharBagIterator iterator = iterate(bag);
    assert(valid(iterator));
    next(iterator);
    assert(valid(iterator));
    next(iterator);
    assert(!valid(iterator));
    std::cout << "testValid - OK" << std::endl;
    return 1;
}

int testCurrentChar() {
    CharBag bag = emptyCharBag(256);
    add(bag, 'a');
    add(bag, 'b');
    add(bag, 'a');
    add(bag, 'c');

    CharBagIterator iterator = iterate(bag);
    assert(currentChar(iterator) == 'c');
    next(iterator);
    assert(currentChar(iterator) == 'b');
    next(iterator);
    assert(currentChar(iterator) == 'a');
    std::cout << "testCurrentChar - OK" << std::endl;
    return 1;
}

int testCurrentCount() {
    CharBag bag = emptyCharBag(256);
    add(bag, 'a');
    add(bag, 'b');
    add(bag, 'a');
    add(bag, 'c');

    CharBagIterator iterator = iterate(bag);
    assert(currentCount(iterator) == 1);
    next(iterator);
    assert(currentCount(iterator) == 1);
    next(iterator);
    assert(currentCount(iterator) == 2);
    std::cout << "testCurrentCount - OK" << std::endl;
    return 1;
}
