#include <iostream>

#define ELEM_TYPE char

using namespace std;

struct ListStr;

typedef ListStr* List;

List Nil();
bool isNil(List xs);
void tkTail(List& xs);
ELEM_TYPE head(List xs);
void mkSnoc(ELEM_TYPE x, List& xs);
int size(List xs);
void printList(List xs);
void deleteList(List xs);


struct RecorridoStr;
typedef RecorridoStr* Recorrido;

Recorrido initialize(List xs);
ELEM_TYPE getCurrent(Recorrido r);
bool finished(Recorrido r);
void nextList(Recorrido& r);
void finish(Recorrido& r);

