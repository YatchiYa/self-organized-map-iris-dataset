
#include "../../includes/som.h"

// free data to avoid leaks
void			free_iris_data(t_iris_database *iris_data)
{
    int			i;

	i = 0;
    if (iris_data)
    {
        if (iris_data->data)
		{
			free(iris_data->data[i].variety);
        	free(iris_data->data);
		}
        free(iris_data);
    }
}

// exit function with free data
void			exit_1(char *str, t_iris_database *iris_data)
{
    printf("error : %s \n", str);
	free_iris_data(iris_data);
	exit(-1);
}

void    clear_map(t_iris_database *iris_data, int rows, int cols)
{
  int     i;
  int     j;

  i = 0;
  j = 0;
  while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
      free(iris_data->network[i][j].vecteur_memoire);
      free(iris_data->network[i][j].etiquette);			
			j++;
		}
    free(iris_data->network[i]);
		i++;
	}
    free(iris_data->network);
}

void    free_memoire(t_iris_database *iris_data)
{
  clear_list(iris_data);
  clear_map(iris_data, MAP_ROWS, MAP_COLS);
  free(iris_data->vectors.vec_min);
  free(iris_data->vectors.vec_max);
  free(iris_data->vectors.vec_moyen);
  free(iris_data->vectors.vec_index);
  free_iris_data(iris_data);
}