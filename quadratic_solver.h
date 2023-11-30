#ifndef QUADRATIC_SOLVER_H
#define QUADRATIC_SOLVER_H

typedef struct {
    double a, b, c;
} QuadraticEquation;

typedef struct {
    double real, imaginary;
} ComplexNumber;

typedef struct {
    int isComplex;
    ComplexNumber root1;
    ComplexNumber root2;
} EquationResult;

EquationResult solveQuadraticEquation(QuadraticEquation equation);
QuadraticEquation inputQuadraticEquation();
void printEquationResults(EquationResult* results);
int inputNumEquations();
void printEquationRoots(EquationResult result, int equationNumber);
#endif
