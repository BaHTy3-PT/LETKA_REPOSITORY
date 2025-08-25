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

    double coeff_1 = 0, coeff_2 = 0, coeff_3 = 0;
    double x1 = 0, x2 = 0;

    TestUserInput("Input coefficient a: ", 1, &coeff_1);
    TestUserInput("Input coefficient b: ", 1, &coeff_2);
    TestUserInput("Input coefficient c: ", 1, &coeff_3);

    printf("\n");

    LinearSolver(coeff_1, coeff_2, coeff_3, &x1, &x2);

    printf("\nTap Enter to enter ...");

    TestUserInput("", 0, &x1);

    return 0;
}
