#include "CharBag.h"
#include "LinkedList.h"

struct CharBagStr {
    int* allCharacters;
    List charactersToIterate;
};

CharBag emptyCharBag(int n) {
    CharBag newCharBag = new CharBagStr;
    newCharBag -> allCharacters = new int[n];
    //Se recorre el array e inicializa todas las posiciones en cero
    for(int i = 0; i < n; i++)
        newCharBag -> allCharacters[i] = 0;
    //Se crea una LinkedList para poder recorrer los chars que se fueron metiendo al bag
    newCharBag -> charactersToIterate = Nil();
    return newCharBag;
}

void deleteCharBag(CharBag& b) {
    delete[] b -> allCharacters;
    deleteList(b -> charactersToIterate);
    delete(b);
}

void add(CharBag& b, unsigned char c) {
    //Suma uno en la posicion indicada por el char
    b -> allCharacters[(int)c] = b -> allCharacters[(int)c] + 1;
    //Agrega uno a la lista para recorrer solo si el char no estaba agregado
    if(b -> allCharacters[(int)c] == 1)
        mkSnoc(c, b -> charactersToIterate);
}

int get(CharBag& b, unsigned char c) {
    return b -> allCharacters[(int)c];
}

struct CharBagIteratorStr {
    //Recorrido es el struct de iterador de las LinkedList
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

//De aca en adelante se delegan todos los metodos al iterador de LinkedList
void deleteCharBagIterator(CharBagIterator& it) {
    finish(it -> iterator);
    delete(it);
}

bool valid(CharBagIterator it) {
    return !finished(it -> iterator);
}

void next(CharBagIterator it) {
    nextList(it -> iterator);
}

char currentChar(CharBagIterator it) {
    return getCurrent(it -> iterator);
}

int currentCount(CharBagIterator it) {
    return it -> allCharacters[(int)currentChar(it)];
}
