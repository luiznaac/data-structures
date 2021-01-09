#ifndef SIMPLECIRCULARLIST_H
#define SIMPLECIRCULARLIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* includeValueBeforeCurrentNode(Node* current, int value);
Node* includeValueInCurrentNode(Node* current, int value);
Node* deleteCurrentNode(Node* current);
Node* deleteBeforeCurrentNode(Node* current);
void freeList(Node* current);
void printList(Node* current);

#endif
