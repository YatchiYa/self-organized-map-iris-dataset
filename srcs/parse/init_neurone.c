
#include "../../includes/som.h"

/**
 * random function to get a  random number 0 - 1
 * */

double				get_random()
{
    double			number;

    srand(time(NULL));
	number = 0;
    number = (double) rand()/RAND_MAX;
    return (number);
}

/**
 * get random vector 
 * malloc the vec
 * call the random function
 * and for each element of our vector min and max 
 * we calculate a random value and set it on our vec that we return
 * */
double				*get_random_vec(t_iris_database *iris_data)
{
	double			val;
	int				i;
	double			*tmp_vec;
	double			norm;

	val = 0;
	i = 0;
	norm = 0;
	tmp_vec = malloc(4 * sizeof(double));
	while (i < 4)
	{
		val = get_random();
		tmp_vec[i] = val * (iris_data->vectors.vec_max[i] - iris_data->vectors.vec_min[i]) + iris_data->vectors.vec_min[i];
		norm += pow(tmp_vec[i],2);
		i++;
	}
	return tmp_vec ;
}

/**
 * init our neuronal map
 * malloc the network
 * allocat memory vector
 * get a random vector and set on the memory vector
 * init our etiquettes into null or . or something we want to
 * */
void				init_neurone(int cols, int rows, t_iris_database *iris_data)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
    if (!(iris_data->network = malloc(rows * sizeof(t_network*))))
		exit_1("error malloc \n", iris_data);
	while (i < rows)
	{
		iris_data->network[i] = malloc(sizeof(t_network) * cols);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (!(iris_data->network[i][j].vecteur_memoire = malloc(sizeof(double) * 4)))
				exit_1("error malloc \n", iris_data);
			iris_data->network[i][j].vecteur_memoire = get_random_vec(iris_data);
			iris_data->network[i][j].etiquette = malloc(20 * sizeof(char));
			strcpy(iris_data->network[i][j].etiquette, ".");			
			j++;
		}
		i++;
	}
}