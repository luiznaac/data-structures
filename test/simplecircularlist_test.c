#include <stdio.h>
#include <stdlib.h>
#include "../src/simplecircularlist.h"

void test(void) {
    Node* current = NULL;
    current = includeValueBeforeCurrentNode(current, 123);
    includeValueBeforeCurrentNode(current, 2345);
    printList(current);
}
