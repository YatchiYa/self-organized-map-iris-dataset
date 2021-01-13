
#include "../../includes/som.h"

/**
 * get avrage vector using our data
 * malloc  our vector
 * loop of all the different lines, and for each colone we calculate the avrage value we get
 * and creat our avreage vector
 * */
void				get_vec_moyen(t_iris_database *iris_data)
{
	int			i;
	int			j;
	double		somme;

	j = 0;
	if (!(iris_data->vectors.vec_moyen = malloc(sizeof(double) * 4)))
	{
		exit_1("malloc error", iris_data);
	}
	while (j < 4)
	{
		i = 0;
		somme = 0;
		while (i < iris_data->nb_vector){
			somme += iris_data->data[i].spal_petal_data[j];
			i++;
		}
		iris_data->vectors.vec_moyen[j] = somme / iris_data->nb_vector;
		
		j++;
	}
	
}

/**
 * calculate the minimum vector from our avreage vector
 * for each value of our vector we minus a constant we defined on our som.h file
 * */

void				get_vect_min(t_iris_database *iris_data)
{
	int			j;

	j = 0;
	if (!(iris_data->vectors.vec_min = malloc(sizeof(double) * 4)))
	{
		exit_1("malloc error", iris_data);
	}
	while (j < 4)
	{
		iris_data->vectors.vec_min[j] = iris_data->vectors.vec_moyen[j] - MIN_MAX_VEC;
		j++;
	}
}

/**
 * calculate the maximum vector from our avreage vector
 * for each value of our vector we add a constant we defined on our som.h file
 * */

void				get_vect_max(t_iris_database *iris_data)
{
	int			j;

	j = 0;
	if (!(iris_data->vectors.vec_max = malloc(sizeof(double) * 4)))
	{
		exit_1("malloc error", iris_data);
	}
	while (j < 4)
	{
		iris_data->vectors.vec_max[j] = iris_data->vectors.vec_moyen[j] + MIN_MAX_VEC;
		j++;
	}
}

/**
 * function to call all the differents functions and display 
 * moy and min and max vector
 * */

void				calcule_vect_min_max_moy(t_iris_database *iris_data)
{
	
	printf ("\033[31m--->>> calcule du vecteur moyen...\033[0m \n");
	get_vec_moyen(iris_data);
	printf ("\033[35m");
	display_tab_double(iris_data->vectors.vec_moyen);
	printf ("\033[0m \n");

	printf ("\033[31m--->>> calcule du vecteur min...\033[0m \n");
	get_vect_min(iris_data);
	printf ("\033[35m");
	display_tab_double(iris_data->vectors.vec_min);
	printf ("\033[0m \n");

	printf ("\033[31m--->>> calcule du vecteur max...\033[0m \n");
	get_vect_max(iris_data);
	printf ("\033[35m");
	display_tab_double(iris_data->vectors.vec_max);
	printf ("\033[0m \n");
}
