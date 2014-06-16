#include "CharBag.h"
#include "LinkedList.h"

struct CharBagStr {
    int* allCharacters;
    List charactersToIterate;
};

CharBag emptyCharBag(int n) {
    CharBag newCharBag = new CharBagStr;
    newCharBag -> allCharacters = new int[n];
    for(int i = 0; i < n; i++)
        newCharBag -> allCharacters[i] = 0;
    newCharBag -> charactersToIterate = Nil();
    return newCharBag;
}

void deleteCharBag(CharBag& b) {
    delete[] b -> allCharacters;
    deleteList(b -> charactersToIterate);
    delete(b);
}

void add(CharBag& b, char c) {
    int position = (int)c - 97;
    b -> allCharacters[position] = b -> allCharacters[position] + 1;
    if(b -> allCharacters[position] == 1)
        mkSnoc(c, b -> charactersToIterate);
}

int get(CharBag& b, char c) {
    int position = (int)c - 97;
    return b -> allCharacters[position];
}


struct CharBagIteratorStr {
    Recorrido iterator;
    int* allCharacters;
};

typedef CharBagIteratorStr* CharBagIterator;

CharBagIterator iterate(CharBag b) {
    CharBagIterator newCharBagIterator = new CharBagIteratorStr;
    newCharBagIterator -> iterator = initialize(b -> charactersToIterate);
    newCharBagIterator -> allCharacters = b -> allCharacters;
    return newCharBagIterator;
}

void deleteCharBagIterator(CharBagIterator& it) {
    finish(it -> iterator);
    delete(it);
}

bool valid(CharBagIterator it) {
    return !finished(it -> iterator);
}

void next(CharBagIterator it) {
    next(it -> iterator);
}

char currentChar(CharBagIterator it) {
    return getCurrent(it -> iterator);
}

int currentCount(CharBagIterator it) {
    int position = (int)currentChar(it) - 97;
    return it -> allCharacters[position];
}
