
#ifndef GET_LINE_H
# define GET_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

// define the buffer size of main function that read my data
# define BUFFER_SIZE 42

int				get_line(int fd, char **line);
int				ft_line_break(char *stock);
int				ft_read_file(char **stock, int fd);
void			ft_fill_static(char **stock, char *buff);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);

#endif