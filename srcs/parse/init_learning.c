
#include "../../includes/som.h"

/**
 * set the training part and refine neuronal network with the right data
 * */

void				init_learning_network(t_iris_database *iris_data)
{
	// learning neuronal network
	printf ("\033[31m--->>> learning neuronal network...\033[0m \n");
	printf ("\033[32m - nb itération : 500 \033[0m \n");
	printf ("\033[32m - Radius neighbours : 3 \033[0m \n");
	printf ("\033[32m - Alpha : 0.9 \033[0m \n");
	training_simulation(LEARNING_NB_ITER, LEARNING_RADIUS, LEARNING_ALPHA, iris_data);

	// rafine neuronal network
	printf ("\033[31m--->>> Rafine neuronal network...\033[0m \n");
	printf ("\033[32m - nb itération : 2000 \033[0m \n");
	printf ("\033[32m - Radius neighbours : 1 \033[0m \n");
	printf ("\033[32m - Alpha : 0.09 \033[0m \n");
	training_simulation(RAFINE_NB_ITER, RAFINE_RADIUS, RAFINE_ALPHA, iris_data);
}