
#include "./includes/som.h"

/***
 * main function where we specify our iris data and we start our differents functions
 * the exec is : ./som iris.data 
 * 
 * **/

int			main(int argc, char **argv)
{
    t_iris_database     *iris_data;
	
		// check errors
	if (!(iris_data = malloc(sizeof(t_iris_database))))
		exit_1("malloc error", iris_data);
    if (argc != 2)
		exit_1("please specify your iris data.", iris_data);
    if (ft_endwith(argv[1], "data") == 0)
		exit_1("please specify your iris data with enxtension .data", iris_data);

		// init data / normalize / get differents vectors
	init_data(iris_data, argv[1]);

		// init neurone map
	init_neurone(MAP_COLS, MAP_ROWS, iris_data);

		// init learning network
	init_learning_network(iris_data);

		// diplay map on file
	display_neurone_map(iris_data, iris_neuronal_map_path, iris_neuronal_map_msg);
	printf ("\n\033[31m--->>> ecriture sur l'ensemble des fichiers...\033[0m \n");
	printf ("\033[32m  Ensembles de fichiers créer \033[0m \n");
	printf ("\033[32m 	- Depot des graphs : /graphs \033[0m \n");
	printf ("\033[32m 	- Depot des fichiers .txt : /data_after_treatment \033[0m \n");

  // liberer la memoire
  free_memoire(iris_data);
	
	return (1);
}