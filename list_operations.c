#include "list_operations.h"
#include <stdio.h>
#include <stdlib.h>

struct Node* createNode(EquationResult data) {
    struct Node* newNode = (Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertNode(Node** head, EquationResult data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void printEquationRootsVariant(EquationResult result, int equationNumber) {
    printf("Equation %d:\n", equationNumber);

    if (result.isComplex == 1) {
        printf("Root 1: %.2lf + %.2lfi\n", result.root1.real, result.root1.imaginary);
        printf("Root 2: %.2lf - %.2lfi\n", result.root2.real, result.root2.imaginary);
    }
    else {
        printf("This quadratic equation has no complex roots \n");
    }

    printf("\n");
}

void printEquationResultVariant(Node* head) {
    printf("Quadratic equations with complex roots:\n");
    int equationNumber = 1;
    while (head != NULL) {
        printEquationRootsVariant(head->data, equationNumber);
        head = head->next;
        equationNumber++;
    }
}
