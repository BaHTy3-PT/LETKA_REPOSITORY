#include <stdio.h>
#include "input.h"
#include "color.h"

void ClearBuffer()
{
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

double TestUserInput(const char *prompt)
{
    double value = 0;

    while (1)
    {
        printf("%s", prompt);

        if (scanf("%lf", &value) == 1)
        {
            ClearBuffer();
            return value;
        }
        else
        {
            printf(COLOR_RED "Input ERROR. Please enter a number (e.g., 123.45 or 50)." \
                   RESET_COLOR "\n");

            ClearBuffer();
        }
    }
}
