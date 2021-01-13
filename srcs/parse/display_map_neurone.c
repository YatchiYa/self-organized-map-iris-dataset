
#include "../../includes/som.h"

/**
 * function to display neuronal map on console
 * 
 * */

void				display_map_neurone(int cols, int rows, t_iris_database *iris_data)
{
	int				i;
	int				j;

	i = 0;
	printf ("\033[32m------------------- \033[0m \n");
	printf ("\033[32 Neurone map display [ 15 x 10 ] \033[0m \n");
	printf ("\033[32m------------------- \033[0m \n");
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf ("%s ", iris_data->network[i][j].etiquette);
			j++;
		}
		printf ("\n");
		i++;
	}
}