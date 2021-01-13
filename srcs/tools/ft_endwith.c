
#include "../../includes/tools.h"

/**
 * this function is just to check if the our file is with extension .data or not
 * 
 * 
 * */
int		ft_endwith(char *str, char *end)
{
	int	length;
	int	end_length;

	length = strlen(str);
	end_length = strlen(end);
	if (end_length > length)
		return (0);
	while (end_length >= 0)
	{
		if (str[length] != end[end_length])
			return (0);
		end_length--;
		length--;
	}
	return (1);
}
