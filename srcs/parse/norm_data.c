#include "../../includes/som.h"

/**
 * get the norm of the differents lines on each colone
 * set the norm value for each line
 * 
 * */
void				set_norm_value(t_iris_database *iris_data)
{
	double		somme;
	int			i;
	int			j;
	i = 0;
	while (i < 150)
	{
		j = 0;
		somme = 0;
		while (j < 4)
		{
			somme += pow(iris_data->data[i].spal_petal_data[j],2);
			j++;
		}
		iris_data->data[i].norm = sqrt(somme);
		i++;
	}
}

/**
 * normalize our data
 * for each value of our data we normalize the value with the right norm of the line
 * ex : value = value / norm
 * */

void			normalize_data(t_iris_database *iris_data)
{
	int			i;
	int			j;

	i = 0;
	set_norm_value(iris_data);
	
	while (i < 150)
	{
		j = 0;
		while (j < 4)
		{
			iris_data->data[i].spal_petal_data[j] = iris_data->data[i].spal_petal_data[j] / iris_data->data[i].norm;
			j++;
		}
		i++;
	}

	printf ("\033[31m--->>> normalizing data...\033[0m \n");
	printf ("\033[32m-----------------------\033[0m \n");
	printf ("\033[32mIris data normalized !! \033[0m \n");
	printf ("\033[32m----------------------- \033[0m \n");
}