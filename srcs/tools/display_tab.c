
#include "../../includes/tools.h"

/**
 * display the table of doubles if we need it
 * */
void				display_tab_double(double *tab)
{
    int         i;

    i = 0;
    printf("tab = [ ");
    while (i < 4)
    {
        printf ("%f, ", tab[i]);
        i++;
    }
    printf("]\n");
}