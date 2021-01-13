#include "../../includes/som.h"

/**
 * set the alpha we need on each iteration 
 * init our alpha to 0.5 and get each time the right alpha 
 * */

double				get_alpha(int i, int j, double alpha)
{
	double alpha_initial;
	
	alpha_initial = 0.5;
	alpha = alpha_initial * (1 - ((double)i/(double)j));
	return (alpha);
}

/**
 * shuffle our tab 
 * malloc our table,
 * for each place memory we init with each position from 1 to 150
 * and then one more time for each value of our table, we get a random index and then swap the values
 * */

void				init_shuffle(int n, t_iris_database *iris_data)
{  
	int				i;
	int				tmp;
	int				j;

    srand(time(NULL));
	iris_data->vectors.vec_index = malloc (n * sizeof(int));
	i = 0;
	while (i < n)
	{
		iris_data->vectors.vec_index[i]=i;
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = rand() % n;
		tmp = iris_data->vectors.vec_index[i];
		iris_data->vectors.vec_index[i] = iris_data->vectors.vec_index[j];
		iris_data->vectors.vec_index[j] = tmp;
		i++;
	}
}

/**
 * get he euclidienne distance between our values of the the vector we need
 * pow 2, of each difference of the values
 * get the somme of the differents values
 * return sqrt of the last value we get
 * */
double				euc_distance(double *t1, double *t2, int n)
{       
	int				i; 
	double			somme;

	somme = 0;
	i = 0;
	while (i < n)
	{
		somme += pow((t1[i] - t2[i]), 2);
		i++;
	}
	return sqrt(somme);
}
