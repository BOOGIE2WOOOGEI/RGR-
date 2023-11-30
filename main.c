#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "quadratic_solver.h"
#include "list_operations.h"

int main() {

    Node* resultsList = NULL;
    bool Menu = true;
    while (Menu)
    {
        printf("Enter 1 to solve quadratic equation\nEnter 0 to exit ");
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 1)
        {
            QuadraticEquation equation = inputQuadraticEquation();
            EquationResult result = solveQuadraticEquation(equation);
            insertNode(&resultsList, result);
        }
        else if (tmp == 0)
        {
            break;
        }
    }

    printEquationsResultsVariant(resultsList);

    freeList(resultsList);

    return 0;
}
