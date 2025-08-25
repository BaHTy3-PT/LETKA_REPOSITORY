#include <stdio.h>
#include <assert.h>
#include "solver.h"

const double accuracy = 0.0001; // //Constant for comparing doubles

void SquareSolver(double coeff_1, double coeff_2, double coeff_3, double *x1_ptr, double *x2_ptr)
{
    assert (isfinite (coeff_1));
    assert (isfinite (coeff_2));
    assert (isfinite (coeff_3));

    if (!isfinite(coeff_1) || !isfinite(coeff_2) || !isfinite(coeff_3))
    {
        printf("Error: incorrect coefficients.\n");

        *x1_ptr = NAN;
        *x2_ptr = NAN;

        return;
    }

    double D = coeff_2 * coeff_2 - 4.0 * coeff_1 * coeff_3;

    if (D < 0)
    {
        printf("A quadratic equation has no real roots\n");

        *x1_ptr = NAN;
        *x2_ptr = NAN;
    }
    else if (fabs(D) <= accuracy)
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

void LinearSolver(double coeff_1, double coeff_2, double coeff_3, double *x1_ptr, double *x2_ptr)
{
    assert (isfinite (coeff_1));
    assert (isfinite (coeff_2));
    assert (isfinite (coeff_3));

    if (!isfinite(coeff_1) || !isfinite(coeff_2) || !isfinite(coeff_3))
    {
        printf("Error: incorrect coefficients.\n");

        *x1_ptr = NAN;
        *x2_ptr = NAN;

        return;
    }

    if (fabs(coeff_1) <= accuracy)
    {
        if ((fabs(coeff_2) <= accuracy) && !(fabs(coeff_3) <= accuracy))
        {
            printf("The quadratic equation has no solutions\n");
            *x1_ptr = NAN;
            *x2_ptr = NAN;
        }
        else if (fabs(coeff_2) <= accuracy && fabs(coeff_3) <= accuracy)
        {
            printf("A quadratic equation has an infinite number of solutions\n");
            *x1_ptr = NAN;
            *x2_ptr = NAN;
        }
        else
        {
            *x1_ptr = *x2_ptr = -coeff_3 / coeff_2;
            printf("The root of the equation is: ");
            printf("%f\n", *x1_ptr);
        }

    }

    else
    {
        SquareSolver(coeff_1, coeff_2, coeff_3, x1_ptr, x2_ptr);
    }

    return;
}
