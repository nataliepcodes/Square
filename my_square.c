#include <stdio.h>
#include <stdlib.h>


//my_isdigit returns 1 is the character sent as an arg is a digit (0 to 9), it returns 0 otherwise
int my_isdigit(char a)
{
    if (a >= 48 && a <= 57)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int ac, char **av)
{
    // if user enters incorrect number of arguments 1)./a.out 2) <width> 3) <height>
    if (ac != 3)
    {
        printf("Usage: %s <width> <height>\n", av[0]);
        exit(1);
    }

    int x = atoi(av[1]); //an inner loop
    int y = atoi(av[2]); //an outer loop

    // if user enters something else rather than a number (ascii 48 - 57 for 0-9)
    int has_error = 0; // initialize error flag to 0
    // Check if the width argument is a number
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (!my_isdigit(av[1][i])) {
            printf("Error: %c is not a valid width\n", av[1][i]);
            has_error = 1;
        }
    }

    // Check if the height argument is a number
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (!my_isdigit(av[2][i])) {
            printf("Error: %c is not a valid height\n", av[2][i]);
            has_error = 1;
        }
    }
    
    if (has_error) 
    { // if there were any errors
        return 1;
    }

    for (int i = 1; i <= y; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if ((i == 1 && j == 1) || (i == 1 && j == x) || (i == y && j == 1) || i == y && j == x)
            {
                printf("o");
            }
            else if ((i == 1 && (j > 1 && j < x)) || (i == y && (j > 1 && j < x)))
            {
                printf("-");
            }
            else if ((j == 1 && (i > 1 && i < y)) || (j == x && (i > 1 && i < y)))
            {
                printf("|");
            }
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
