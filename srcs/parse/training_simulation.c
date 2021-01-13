#include "../../includes/som.h"

/**
 * 
 * update our memory vector with the alpha calculated befor and our ancient memory vector
 * with the right start and end position for row and cols calculated just befor on function update_best_match_unit
 * where we verify each time the right distance between rows and cols and radius_distance
 * 
 * */
void				update_vector(t_iris_database *iris_data, double *vec, double alpha, int x_start, int x_end, int y_start, int y_end)
{
    int 			k;
    int 			j;
    int 			i;

	i = x_start;
	while (i <= x_end){
		j = y_start;
		while (j <= y_end){
			k = 0;
			while (k < 4){
				iris_data->network[i][j].vecteur_memoire[k] +=  alpha*(vec[k] - iris_data->network[i][j].vecteur_memoire[k]);
				k++;
			}
			j++;
		}
		i++;
	}
}

/**
 * we update the best match unit according to the radius distance so :
 * if (row of my best match unit - radius distance) < 0 then we will start from 0 otherwise we will start from the difference between them
 * if (col of my best match unit - radius distance) < 0 then we will start from 0 otherwise we will start from the difference between them
 * the same goes for when we do row + radius_distance 
 * and then update our memory vector with the alpha calculated befor and our ancient memory vector
 * */
void				update_best_match_unit(double radius_distance, t_iris_database *iris_data, double alpha, double *vec)
{
    int 			x_start, x_end;
    int				y_start, y_end;

    while ( radius_distance >= 0 )
	{
		// check for row of bmu - radius distance
		if(iris_data->best_match_unit->row - radius_distance < 0)
			x_start = 0;
		else
			x_start = iris_data->best_match_unit->row - radius_distance;
			
		// check for col of bmu - radius distance
		if(iris_data->best_match_unit->col - radius_distance < 0)
			y_start = 0;
		else
			y_start=iris_data->best_match_unit->col - radius_distance;
			
		// check for row of bmu + radius distance
		if(iris_data->best_match_unit->row + radius_distance > MAP_ROWS - 1)
			x_end = MAP_ROWS - 1 ;
		else
			x_end=iris_data->best_match_unit->row + radius_distance;
			
		// check for row of bmu + radius distance
		if(iris_data->best_match_unit->col + radius_distance >  MAP_COLS - 1)
			y_end = MAP_COLS - 1;
		else
			y_end = iris_data->best_match_unit->col + radius_distance;
			
		// update our vector
		update_vector(iris_data, vec, alpha, x_start, x_end, y_start, y_end);
		radius_distance--;
	}
}

/**
 * for each data of our normalized data
 * we will calculate the euclidiene distance between the captors (data vector that were generated from the shuffle)
 * and the memory vector of our neuronal network
 * 
 * */
void				set_bmu_with_eucl_distance(t_iris_database *iris_data, int i, int j, int k, double *minimum_distance, 
	t_best_match_unit	*tmp)
{
	double				dist;

	dist = euc_distance(iris_data->data[iris_data->vectors.vec_index[k]].spal_petal_data , iris_data->network[i][j].vecteur_memoire, 4);
	iris_data->network[i][j].eucl_dist = dist;
	if(dist < *minimum_distance)
	{
		*minimum_distance = dist;
		iris_data->best_match_unit->eucl_distance = dist;
		iris_data->best_match_unit->row = i;
		iris_data->best_match_unit->col = j;
		iris_data->best_match_unit->next = NULL;
		iris_data->best_match_unit_head = iris_data->best_match_unit;
		iris_data->bmu_activated = 0;
    clear_list(iris_data);
	}
	else if(dist == *minimum_distance)
	{
		iris_data->bmu_activated += 1;
		tmp->eucl_distance = dist;
		tmp->row = i;
		tmp->col = j;
		iris_data->best_match_unit->next = tmp;
		iris_data->best_match_unit = iris_data->best_match_unit->next;
	}
}

/**
 * for each data of our normalized data
 * we will calculate the euclidiene distance between the captors (data vector that were generated from the shuffle)
 * and the memory vector of our neuronal network
 * we set and init minimum  distance for the only use of when we loop for the first time to set our bmu[0]
 * and then we make and strcpy to copy the right variety (type X,Y or Z) we found with the etiquette of our neuronal map
 * and last, we update the best match unit with the right values acording to the distance calculated
 * */
void                traitement_best_match_unit(t_iris_database *iris_data, double radius_distance, double alpha, 
	t_best_match_unit	*tmp)
{
	int				i;
	int				k;
	int				j;
	double			minimum_distance;

    k = 0;
    while (k < iris_data->nb_vector)
    {
		// set the first variable of our distance just to us it next time
		// we will update the minimum distance once we enter the first time on the loop in function set_bmu_with_eucl_distance
        minimum_distance = 1000.;
        i = 0;
        while (i < MAP_ROWS)
        {
            j = 0;
            while (j < MAP_COLS)
            {
				set_bmu_with_eucl_distance(iris_data, i, j, k, &minimum_distance, tmp);
                j++;
            }
            i++;
        }
		    random_bmu(iris_data);
        strcpy(iris_data->network[iris_data->best_match_unit->row][iris_data->best_match_unit->col].etiquette,
				iris_data->data[iris_data->vectors.vec_index[k]].variety);
        update_best_match_unit(radius_distance, iris_data, alpha, iris_data->data[iris_data->vectors.vec_index[k]].spal_petal_data);
        k++;
    }
}

/**
 * begin our training simulation
 * malloc our best match unit
 * for each iteration that we defined
 * we calculate the alpha variable
 * we make a shuffle of our table
 * and we begin our function to get best match unit vector
 * 
 * **/
void				training_simulation(int nb_it, double radius_distance, double alpha, t_iris_database *iris_data)
{
	int             	i;
	t_best_match_unit	*tmp;

 	iris_data->best_match_unit = malloc( sizeof (t_best_match_unit));
 	tmp = malloc(sizeof (t_best_match_unit));
 	iris_data->best_match_unit_head = malloc( sizeof (t_best_match_unit));
    i = 0;
    while (i < nb_it)
    {
        alpha = get_alpha(i, nb_it, alpha);
        init_shuffle(iris_data->nb_vector, iris_data);
        traitement_best_match_unit(iris_data, radius_distance, alpha, tmp);
        i++;
    }
	free(tmp);
}