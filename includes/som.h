
#ifndef SOM_H
# define SOM_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <time.h>

# include "./get_line.h"
# include "./tools.h"
# include "../pbplot/pbPlots.h"
# include "../pbplot/supportLib.h"

# define iris_data_normal_path_txt "data_after_treatment/iris_data_normal.txt"
# define iris_data_normal_path_graph "graphs/iris_data_normal.png"
# define iris_data_normal_path_msg "Iris data befor normalized\n"
# define iris_data_normalized_path_txt "data_after_treatment/iris_data_normalized.txt"
# define iris_data_normalized_path_graph "graphs/iris_data_normalise.png"
# define iris_data_normalized_path_msg "Iris data after normalized\n"
# define iris_neuronal_map_path "data_after_treatment/iris_neuronal_map.txt"
# define iris_neuronal_map_msg "Neuronal Map Network : dim ( 10 x 6 ) \n"

# define MIN_MAX_VEC 0.005
# define MAP_COLS 10
# define MAP_ROWS 6
# define LEARNING_NB_ITER 500
# define LEARNING_RADIUS 3
# define LEARNING_ALPHA 0.9
# define RAFINE_NB_ITER 2000
# define RAFINE_RADIUS 1
# define RAFINE_ALPHA 0.09


// data struct with variety and tab
typedef struct		s_data
{
	char			*variety;
	double			spal_petal_data[4];
	double			norm;
}					t_data;

// the different vectors that i need
typedef struct		s_vector
{
	double			*vec_moyen;
	double			*vec_min;
	double			*vec_max;
	int				*vec_index;
}					t_vector;

// my map network
typedef struct 		s_network 
{
	double			eucl_dist;
	char			*etiquette;
	double			*vecteur_memoire;
}					t_network;

// best match unit vector
typedef struct 		s_best_match_unit
{
	double						eucl_distance;
	int							row;
	int							col;
	struct s_best_match_unit	*next;
}					t_best_match_unit;

// my global struct of my database
typedef struct		s_iris_database
{
	int						nb_vector;
	int						bmu_activated;
	t_vector				vectors;
	t_data					*data;
	t_network				**network;
	t_best_match_unit		*best_match_unit;
	t_best_match_unit		*best_match_unit_head;
}					t_iris_database;


int					ft_get_nb_lines(char *path, t_iris_database *iris_data);
void        read_file(char *path, t_iris_database *iris_data);
void				exit_1(char *str, t_iris_database *iris_data);
void				display_data(t_iris_database *iris_data, char *path, char *msg);
void				normalize_data(t_iris_database *iris_data);
void        		draw_data_simple(t_iris_database *iris_data, char *path);
void				calcule_vect_min_max_moy(t_iris_database *iris_data);
void				init_neurone(int cols, int rows, t_iris_database *iris_data);
void				display_map_neurone(int cols, int rows, t_iris_database *iris_data);
void				init_data(t_iris_database *iris_data, char *path);
void				training_simulation(int nb_it, double nhd_r, double alpha, t_iris_database *iris_data);
void				display_neurone_map(t_iris_database *iris_data, char *path, char *msg);
void				init_learning_network(t_iris_database *iris_data);
double				euc_distance(double *t1, double *t2, int n);
void				init_shuffle(int n, t_iris_database *iris_data);
double				get_alpha(int i, int j, double alpha);
void       			clear_list(t_iris_database *iris_data);
void        random_bmu(t_iris_database *iris_data);
void    free_memoire(t_iris_database *iris_data);

#endif