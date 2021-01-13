
#include "../../includes/som.h"

/**
 * this function is used to calculate how many line are on our file
*/
int			ft_get_nb_lines(char *path, t_iris_database *iris_data)
{
    char                *line;
	int					ret;
    int                 nb;
    int                 fd;

	if ((fd = open(path, O_RDONLY)) < 0)
		exit_1("can't open the file", iris_data);
    nb = 0;
	while ((ret = get_line(fd, &line)))
	{
        nb++;
		free(line);
	}
	if (line)
	{
		nb++;
		free(line);
	}
    close(fd);
    return (nb);
}