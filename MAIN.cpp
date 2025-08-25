#include <stdio.h>

#include "input.h"
#include "solver.h"
#include "test.h"

int main()
{
    printf("Kvadratka by BaHTy3\n"
           "This is a program for calculating the roots of a quadratic equation\n"
           "\n");

    TestMathLogic();

    double x1 = 0, x2 = 0;

    double coeff_1 = TestUserInput("Input coefficient a: ");
    double coeff_2 = TestUserInput("Input coefficient b: ");
    double coeff_3 = TestUserInput("Input coefficient c: ");

    printf("\n");

    SquareSolver(coeff_1, coeff_2, coeff_3, &x1, &x2);

    return 0;
}
