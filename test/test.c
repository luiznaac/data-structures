#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../src/simplecircularlist.h"

int main(void) {
    int value_1 = 123;
    int value_2 = 2345;
    Node* current = includeValueBeforeCurrentNode(current, value_1);

    includeValueBeforeCurrentNode(current, value_2);

    assert(current->data == value_1);
    assert(current->next->data == value_2);
    assert(current->next->next == current);
}
