
#include "../../includes/som.h"

/**
 * read data and display them on file and draw the differents graphs
 * calculate victor moy min max 
 * */
void				init_data(t_iris_database *iris_data, char *path)
{
	// reading file and display data on file in folder : data_after_treatement and draw the data on a graph in folder graphs
	read_file(path, iris_data);
	display_data(iris_data, iris_data_normal_path_txt, iris_data_normal_path_msg);
	draw_data_simple(iris_data, iris_data_normal_path_graph);
	
	// normalize file and display data on file in folder : data_after_treatement and draw the data on a graph in folder graphs
	normalize_data(iris_data);
	display_data(iris_data, iris_data_normalized_path_txt, iris_data_normalized_path_msg);
	draw_data_simple(iris_data, iris_data_normalized_path_graph);
	
	// calculate vector min, max, moy
	calcule_vect_min_max_moy(iris_data);

}