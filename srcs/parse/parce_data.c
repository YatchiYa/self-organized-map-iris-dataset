#include "../../includes/som.h"

/***
 * we fill our struct with the differents data
 * strtod used to convert string to double 
 * for each type we set : 
 * if type = setasa then type = X
 * if type = versicolor then type = y
 * if type = virginica then type = z
 * 
 * */
void			parse_data_file(char *line, t_iris_database *iris_data, int nb)
{
	char		**tmp_tab;	

	tmp_tab = ft_split(line, ',');
	iris_data->data[nb].spal_petal_data[0] = strtod(tmp_tab[0], NULL);
	iris_data->data[nb].spal_petal_data[1] = strtod(tmp_tab[1], NULL);
	iris_data->data[nb].spal_petal_data[2] = strtod(tmp_tab[2], NULL);
	iris_data->data[nb].spal_petal_data[3] = strtod(tmp_tab[3], NULL);
	if (strcmp("Iris-setosa", tmp_tab[4]) == 0)
		iris_data->data[nb].variety = strdup("X");
	if (strcmp("Iris-versicolor", tmp_tab[4]) == 0)
		iris_data->data[nb].variety = strdup("Y");
	if (strcmp("Iris-virginica", tmp_tab[4]) == 0)
		iris_data->data[nb].variety = strdup("Z");

}

/***
 * function where we read open our file and we read it
 * malloc our data
 * function to get each line
 * and parse eah line we get
 * */

void      read_file(char *path, t_iris_database *iris_data)
{
  char        *line;
	int					fd;
	int					ret;
	int					i;

	if ((fd = open(path, O_RDONLY)) < 0)
		exit_1("can't open the file", iris_data);
	iris_data->nb_vector = ft_get_nb_lines(path, iris_data);
	if (!(iris_data->data = (t_data*)malloc(sizeof(t_data) * (iris_data->nb_vector + 1))))
		exit_1("couldn't malloc size", iris_data);
	i = 0;
	while ((ret = get_line(fd, &line)))
	{
		parse_data_file(line, iris_data, i); // parse each line
		i++;
		free(line); // free our line to avoid leaks
	}
	// parse the last line after we ur out of our while loop
	if (line)
	{
		parse_data_file(line, iris_data, i);
		free(line); // free our line to avoid leaks
	}
	// close the file
	close(fd);
	printf ("\033[31m--->>> loading data...\033[0m \n");
	printf ("\033[32m------------------- \033[0m \n");
	printf ("\033[32mIris data loaded !! \033[0m \n");
	printf ("\033[32m------------------- \033[0m \n");
}
