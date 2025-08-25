#include <stdio.h>
#include "input.h"

void TestUserInput(const char *prompt, int is_double, void *result)
{
    int c;

    while (1)
    {
        printf("%s", prompt);

        if (is_double)
        {
            double *value_double = (double*)result;

            if (scanf("%lf", value_double) == 1)
            {
                while ((c = getchar()) != '\n' && c != EOF);

                return;
            }
            else
            {
                printf("Input error. Please enter a number (for example, 123.45 or 50).\n");

                while ((c = getchar()) != '\n' && c != EOF);
            }
        }

        else
        {
            int* value_int = (int*)result;

            if (scanf("%d", value_int) == 1)
            {
                while ((c = getchar()) != '\n' && c != EOF);

                return;
            }
            else
            {
                printf("Input error. Please enter an integer (for example 123).\n");

                while ((c = getchar()) != '\n' && c != EOF);
            }
        }
    }
}
