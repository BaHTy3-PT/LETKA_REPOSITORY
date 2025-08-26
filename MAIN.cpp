#include <stdio.h>
#include "input.h"
#include "solver.h"
#include "test.h"
#include "color.h"

int main()
{
    printf(COLOR_YELLOW "Kvadratka by BaHTy3" RESET_COLOR "\n"
           COLOR_YELLOW "This is a program for calculating the roots of a quadratic equation"
           RESET_COLOR "\n\n");

    TestMathLogic();

    double x1 = 0, x2 = 0;

    double coeff_1 = TestUserInput("Input coefficient a: ");
    double coeff_2 = TestUserInput("Input coefficient b: ");
    double coeff_3 = TestUserInput("Input coefficient c: ");

    printf("\n");

    SquareSolver(coeff_1, coeff_2, coeff_3, &x1, &x2);

    return 0;
}
