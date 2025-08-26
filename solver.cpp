#include <stdio.h>
#include <assert.h>
#include "solver.h"
#include "color.h"

void SquareSolver(double coeff_1, double coeff_2, double coeff_3, double *x1_ptr, double *x2_ptr)
{
    assert (x1_ptr != NULL);
    assert (x2_ptr != NULL);

    if (fabs(coeff_1) > ACCURACY)
    {
        *x1_ptr = NAN;
        *x2_ptr = NAN;

        if (!isfinite(coeff_1) || !isfinite(coeff_2) || !isfinite(coeff_3))
        {
            printf(COLOR_RED "Error: incorrect coefficients." RESET_COLOR "\n");

            return;
        }

        double D = coeff_2 * coeff_2 - 4.0 * coeff_1 * coeff_3;

        if (D < 0)
        {
            printf("A quadratic equation has no real roots\n");
        }
        else if (fabs(D) <= ACCURACY)
        {
            *x1_ptr = *x2_ptr = -coeff_2 / (2 * coeff_1);
            printf("The root of the equation is: ");
            printf ("%lf\n", *x1_ptr);
        }
        else // D > 0
        {
            *x1_ptr = (-coeff_2 + sqrt(D)) / (2.0 * coeff_1);
            *x2_ptr = (-coeff_2 - sqrt(D)) / (2.0 * coeff_1);

            printf("The first root is: ");
            printf("%lf\n", *x1_ptr);
            printf("The second root is: ");
            printf("%lf\n", *x2_ptr);
        }

        return;
    }

    else
    {
        LinearSolver(coeff_2, coeff_3, x1_ptr, x2_ptr);
    }
}

void LinearSolver(double coeff_2, double coeff_3, double *x1_ptr, double *x2_ptr)
{
    assert (x1_ptr != NULL);
    assert (x2_ptr != NULL);

    *x1_ptr = NAN;
    *x2_ptr = NAN;

    if (!isfinite(coeff_2) || !isfinite(coeff_3))
    {
        printf(COLOR_RED "Error: incorrect coefficients." RESET_COLOR "\n");

        return;
    }

    if ((fabs(coeff_2) <= ACCURACY) && !(fabs(coeff_3) <= ACCURACY))
    {
        printf("The quadratic equation has no solutions\n");
    }
    else if (fabs(coeff_2) <= ACCURACY && fabs(coeff_3) <= ACCURACY)
    {
        printf("A quadratic equation has an infinite number of solutions\n");
    }
    else
    {
        *x1_ptr = *x2_ptr = -coeff_3 / coeff_2;
        printf("The root of the equation is: ");
        printf("%f\n", *x1_ptr);
    }

    return;
}
