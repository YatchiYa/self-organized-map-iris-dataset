
#include "../../includes/get_line.h"
#include "get_line_tools.c"

/***
 * The idea of my get_line function is : 
 * i define a buffer_size : 5 or whatever we want
 * 
 * if we try to read a line example : "hello world from test file"
 * 
 * with ou buffer size = 5, on the first try we will read only "hello"
 * and then we verify if we are in the end of the line ? if not we will call it again and join then previous one with the next one
 * so it will be : "hello worl", same goes here, if we find that we are at the end of the line ? no we call it again 
 * and join all the previous one,
 * we repeat this untill we are at the end of the line and 
 * finnaly : we update our complete line and return the size of line we read 
 * 
 * */


/***
 * in this function it's made to just check if we are at the end of the line or not
 * end of line = \n
 * 
 * */
int		ft_line_break(char *stock)
{
	while (*stock)
		if (*(stock++) == '\n')
			return (1);
	return (0);
}

/**
 * this function is to fill our static variable and free the tmp buff to delete all the leaks 
 * 
 * */

void	ft_fill_static(char **stock, char *buff)
{
	char	*to_free;

	to_free = *stock;
	*stock = strdup(buff);
	free(to_free);
	free(buff);
}

/***
 * in this function we will read the line with a specified malloc size that i defined
 * we will read untill we find the end of the line \n 
 * and fill the static variable each time
 * 
 * */
int		ft_read_file(char **stock, int fd)
{
	char		*buffer;
	int			ret;

	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)))
	|| read(fd, buffer, 0) < 0)
		return (-1);
	if (*stock == NULL)
		*stock = strdup("");
	while (!ft_line_break(*stock) && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		ft_fill_static(stock, ft_strjoin(*stock, buffer));
	}
	free(buffer);
	return (ret);
}


/***
 * main function to read our data
 * the errors we need to handle : 
 *      fd < 0 : file does not exist
 *      line == Null : line witch i send from the main function
 *      ft_read_file(&stock[fd], fd) < 0 : means he couldn't read anything due to file error or privilége 
 * 
 * */

int		get_line(int fd, char **line)
{
	static char		*stock;
	int				ret;
	int				i;

	if (fd < 0 || line == NULL
	|| (ret = ft_read_file(&stock, fd)) < 0)
		return (-1);
	i = 0;
	while (stock[i] != '\n' && stock[i])
		i++;
	*line = ft_substr(stock, 0, i);
	if ((ret == 0 && strlen(stock) > strlen(*line)) || ret > 0)
		ret = 1;
	ft_fill_static(&stock,
			ft_substr(stock, ++i, strlen(stock)));
	if (ret <= 0)
	{
		free(stock);
		stock = NULL;
	}
	return (ret);
}