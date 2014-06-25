#include <iostream>
#include "HuffmanTree.h"

#define ELEM_TYPE HuffmanTree

using namespace std;

struct ListForTreeStr;

typedef ListForTreeStr* ListForTree;

ListForTree NilForTree();
bool isNil(ListForTree xs);
void tkTail(ListForTree& xs);
ELEM_TYPE head(ListForTree xs);
void mkSnoc(ELEM_TYPE x, ListForTree& xs);
int size(ListForTree xs);
void printList(ListForTree xs);
void deleteList(ListForTree xs);
