#include "list_operations.h"
#include "quadratic_solver.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

QuadraticEquation inputQuadraticEquation() {
    QuadraticEquation equation;

    printf("Enter coefficients (a b c) for the quadratic equation: ");
    scanf("%lf %lf %lf", &equation.a, &equation.b, &equation.c);

    return equation;
}

void printEquationRoots(EquationResult result, int equationNumber) {
    printf("Equation %d:\n", equationNumber);

    if (result.isComplex == 1) {
        printf("Root 1: %.2lf + %.2lfi\n", result.root1.real, result.root1.imaginary);
        printf("Root 2: %.2lf - %.2lfi\n", result.root2.real, result.root2.imaginary);
    }
    else {
        printf("Root 1: %.2lf\n", result.root1.real);
        printf("Root 2: %.2lf\n", result.root2.real);
    }

    printf("\n");
}


void printEquationResult(Node* head) {
    printf("Quadratic equations with complex roots:\n");
    int equationNumber = 1;
    while (head != NULL) {
        printEquationRoots(head->data, equationNumber);
        head = head->next;
        equationNumber++;
    }
}

int inputNumEquations() {
    int num_equations;

    printf("Enter the number of quadratic equations: ");
    scanf("%d", &num_equations);

    return num_equations;
}


EquationResult solveQuadraticEquation(QuadraticEquation equation) {
    EquationResult result;
    double discriminant = pow(equation.b, 2) - 4 * (equation.a * equation.c);
    printf("Discriminant: %.2lf\n", discriminant);
    if (discriminant >= 0) {
        result.isComplex = 0;
        result.root1.real = (-equation.b + sqrt(discriminant)) / (2 * equation.a);
        result.root2.real = (-equation.b - sqrt(discriminant)) / (2 * equation.a);
    }
    else {
        result.isComplex = 1;
        result.root1.real = -equation.b / (2 * equation.a);
        result.root2.real = result.root1.real;
        result.root1.imaginary = sqrt(fabs(discriminant)) / (2 * equation.a);
        result.root2.imaginary = -sqrt(fabs(discriminant)) / (2 * equation.a);
    }

    return result;
}
