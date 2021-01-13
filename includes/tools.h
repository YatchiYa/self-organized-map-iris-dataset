
#ifndef TOOLS_H
# define TOOLS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>

char				**ft_split(char const *s, char c);
int					ft_endwith(char *str, char *end);
void				display_tab_double(double *tab);
#endif