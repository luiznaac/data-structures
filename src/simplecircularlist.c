#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "simplecircularlist.h"

Node* includeValueBeforeCurrentNode(Node* current, int value) {
	Node* p;
	p = (Node*)malloc(sizeof(Node));
	p->data = value;
	if(current == NULL) {
		current = p;
		p->next = p;
	}
	else {
		Node* aux = current;
		do {
			aux = aux->next;
		} while(current != aux->next);
		aux->next = p;
		p->next = current;
	}
	return current;
}

Node* includeValueInCurrentNode(Node* current, int value) {
	Node* p;
	p->data = value;

	if(current == NULL) {
		current = p;
		p->next = p;
	}

    Node* aux = current;
    do {
        aux = aux->next;
    } while(current != aux->next);
    aux->next = p;
    p->next = current;
    current = p;

	return current;
}

Node* deleteCurrentNode(Node* current) {
	if(current == NULL) {
		return NULL;
	}

	if(current == current->next) {
		free(current);
		return NULL;
	}

    Node* aux;
    aux = current;

    do {
        aux = aux->next;
    } while(aux->next != current);

    aux->next = current->next;
    free(current);
    current = aux->next;

    return current;
}

Node* deleteBeforeCurrentNode(Node* current) {
	if(current == NULL){
		printf("\nLista vazia");
		return NULL;
	}

	if(current == current->next){
		free(current);
		return NULL;
	}

    Node* aux;
    Node* aux2;
    aux = NULL;
    aux = current;

    do {
        aux = aux->next;
    } while(aux->next != current);

    aux2 = aux;

    do {
        aux2 = aux2->next;
    } while(aux2->next != aux);

    aux2->next = aux->next;
    free(aux);

    return current;
}

void freeList(Node* current) {
    if(current == NULL) {
        return;
    }

    Node* aux;
    Node* aux2;
    aux = current;
    aux2 = aux;

    do {
        aux = aux2;
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    } while(aux != current);
}

void printList(Node* current) {
    if(current == NULL) {
		printf("\nThere are no elements.\n");
		return;
	}

    Node* aux = current;
    printf("\nAddress: %p | Value: %p\n", &current, current);
    do {
        printf("\n%p | %11d | %p", aux, aux->data, aux->next);
        aux = aux->next;
    } while(aux != current);
    printf("\n");
}
