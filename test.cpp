#include <stdio.h>
#include <math.h>
#include "test.h"
#include "solver.h"

void TestMathLogic()
{
    double coeff_1[5] = { 1,  1, 1,  0,  2};
    double coeff_2[5] = {-3, -2, 1,  2,  5};
    double coeff_3[5] = { 2,  1, 1, -4, -3};

    double true_x1[5] = {2, 1, NAN, 2, 0.5};
    double true_x2[5] = {1, 1, NAN, 2,  -3};

    const char *test_num[5] =
    {
        "x^2 - 3x + 2 = 0",
        "x^2 - 2x + 1 = 0",
        "x^2 + x + 1 = 0",
        "2x - 4 = 0",
        "2x^2 + 5x - 3 = 0"
    };

    double x1 = 0, x2 = 0;
    int i = 0;
    int errors = 0;

    printf("========== Running tests ==========\n\n");

    while (i < 5)
    {
        printf("Test %d: %s\n", i + 1, test_num[i]);
        printf("The coefficients you entered: ");
        printf("coeff_1 = %lf, coeff_2 = %lf, coeff_3 = %lf\n",
               coeff_1[i], coeff_2[i], coeff_3[i]);

        SquareSolver(coeff_1[i], coeff_2[i], coeff_3[i], &x1, &x2);

        int nan_searcher = !(fabs(true_x1[i] - true_x1[i]) <= ACCURACY) &&
            !(fabs(true_x2[i] - true_x2[i]) <= ACCURACY);

        int nan_result = !(fabs(x1 - x1) <= ACCURACY) && !(fabs(x2 - x2) <= ACCURACY);

        if (nan_searcher)
        {
            if (nan_result)
            {
                printf("Expected no solutions (NAN)\n");
                printf("Received: x1 = NAN, x2 = NAN\n");
                printf("Expected: x1 = NAN, x2 = NAN\n");
                printf("OPERATION ACCEPTED\n\n");
            }
            else
            {
                printf("Received: %lf, %lf\n", x1, x2);
                printf("Expected: x1 = NAN, x2 = NAN\n");
                printf("ERROR: Expected no solutions (NAN), but got roots!\n");
                errors++;
            }
        }
        else
        {
            int correct_order = (fabs(x1 - true_x1[i]) <= ACCURACY) &&
                                (fabs(x2 - true_x2[i]) <= ACCURACY);

            int switch_x = (fabs(x1 - true_x2[i]) <= ACCURACY) &&
                           (fabs(x2 - true_x1[i]) <= ACCURACY);

            if (correct_order || switch_x)
            {
                printf("OPERATION ACCEPTED\n\n");

                if (fabs(true_x1[i] - true_x2[i]) <= ACCURACY)
                {
                    printf("Single root: %lf\n\n", x1);
                }
                else
                {
                    printf("Roots: %lf, %lf\n\n", x1, x2);
                }
            }
            else
            {
                printf("ERROR: Roots don't match expected values!\n");

                    if (x1 == NAN && x2 == NAN)
                    {
                        printf("Received: x1 = NAN, x2 = NAN");
                    }
                    else
                    {
                        printf("Received: x1 = %lf, x2 = %lf\n", x1, x2);
                    }

                printf("Expected: x1 = %lf, x2 = %lf\n", true_x1[i], true_x2[i]);

                if (fabs(true_x1[i] - true_x2[i]) <= ACCURACY)
                {
                    printf("Reason: Should have single root at x = %lf\n\n", true_x1[i]);
                }
                else
                {
                    printf("Reason: Quadratic formula calculation error\n\n");
                }

                errors++;
            }
        }

        i++;
    }

    printf("========== Test Results ==========\n");

    if (!errors)
    {
        printf("All 5 tests passed successfully!\n");
    }
    else
    {
        printf("%d out of 5 tests failed\n", errors);
    }

    printf("\n");

    return;

}
