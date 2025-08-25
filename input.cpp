#include <stdio.h>
#include "input.h"

//-----------------------------------------------------------------------------

void ClearBuffer()
{
    int c = 0;    // this is krivo!!! // kill!
    while ((c = getchar()) != '\n' && c != EOF);    // the zhirnaya funkcija! // This is Vanya, your best AI
}

//-----------------------------------------------------------------------------

double TestUserInput(const char *prompt)
{
    double value = 0;   // NIGGA DYAJJJ

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
            printf("Input error. Please enter a number (e.g., 123.45 or 50).\n");
            ClearBuffer();
        }
    }
}
