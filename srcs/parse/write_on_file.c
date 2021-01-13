#include "../../includes/som.h"

/**
 * display data on file for narmal data and normalized data
 * 
 * */
void				display_data(t_iris_database *iris_data, char *path, char *msg)
{
	int			i;
    FILE		*inputFile;

	i = 0;
	// remove the previous file
	char *tmp_path = ft_strjoin("rm ", path);
	system(tmp_path);
    inputFile = fopen(path, "a+");
	fprintf(inputFile, msg, " \n ----------------------------------------------- \n ");
	while (i < iris_data->nb_vector)
	{
		fprintf(inputFile, "iris data[%d] => [%f],[%f],[%f],[%f],[%s]\n", i, iris_data->data[i].spal_petal_data[0], iris_data->data[i].spal_petal_data[1],
				iris_data->data[i].spal_petal_data[2], iris_data->data[i].spal_petal_data[3], iris_data->data[i].variety);
		i++;
	}
    fclose( inputFile );
}

/**
 * display neuronal map on file
*/
void				display_neurone_map(t_iris_database *iris_data, char *path, char *msg)
{
	int			i;
	int			j;
    FILE		*inputFile;

	i = 0;
	// remove the previous file
	char *tmp_path = ft_strjoin("rm ", path);
	system(tmp_path);
    inputFile = fopen(path, "a+");
	fprintf(inputFile, "%s ", msg);
	fprintf(inputFile, "  ----------------------------------------------- \n ");
	
	fprintf (inputFile, "--->>> learning neuronal network... \n");
	fprintf (inputFile, "  - nb itération : 500  \n");
	fprintf (inputFile, "  - Radius neighbours : 3  \n");
	fprintf (inputFile, "  - Alpha : 0.9  \n");
	
	fprintf (inputFile, "--->>> Rafine neuronal network... \n");
	fprintf (inputFile, "  - nb itération : 2000  \n");
	fprintf (inputFile, "  - Radius neighbours : 1  \n");
	fprintf (inputFile, "  - Alpha : 0.09  \n");
	fprintf(inputFile, " ----------------------------------------------- \n ");
	fprintf(inputFile, " legende :  \n ");
	fprintf(inputFile, "         X: Iris-setosa, Y: Iris-versicolor, Z: Iris-virginica  \n ");
	fprintf(inputFile, " ----------------------------------------------- \n");

	while (i < MAP_ROWS)
	{
		j = 0;
		while (j < MAP_COLS)
		{
			fprintf (inputFile, "%s ", iris_data->network[i][j].etiquette);
			j++;
		}
		fprintf (inputFile, "\n");
		i++;
	}
    fclose(inputFile);
}
