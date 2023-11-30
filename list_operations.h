#ifndef LIST_OPERATIONS_H
#define LIST_OPERATIONS_H

#include "quadratic_solver.h"
#include <stdio.h>

typedef struct Node {
    EquationResult data;
    struct Node* next;
}Node;

Node* createNode(EquationResult data);
void insertNode(Node** head, EquationResult data);
void freeList(Node* head);
void printEquationRootsVariant(EquationResult result, int equationNumber);
void printEquationsResultsVariant(Node* head);

#endif
