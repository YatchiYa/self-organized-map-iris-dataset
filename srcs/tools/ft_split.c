
#include "../../includes/tools.h"

/***
 * this function is counting how many index we will be spliting
 * so each time we found our character which is a paramettre of our function 
 * we increment our index
 * and of course we need to that our character is not at the end of the line
 *  and then the next one is not the same character to split too
 * */
int		ft_count_index(char const *s, char c)
{
	unsigned int	index;

	index = 0;
	while (*s)
	{
		if (*s != c && *s != '\0' && (*(s + 1) == c || *(s + 1) == '\0'))
			index++;
		s++;
	}
	return (index);
}

/**
 * here, we malloc of each index of our tab[i] the right amount of characters
 * */
int		ft_malloc_index(char **tab, char const *s, char c, unsigned int index)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(tab[index] = malloc(sizeof(char) * (i + 1))))
	{
		i = 0;
		while (i < index)
			free(tab[i++]);
		free(tab);
		return (0);
	}
	return (1);
}

/**
 * split function to split our line (string) into **tab or into a tab of string with the right amount of malloc
 * 
 * */
char	**ft_split(char const *s, char c)
{
	char				**tab;
	unsigned int		i;
	unsigned int		index;
	unsigned int		words;

	index = 0;
	if (!s || !(tab = malloc(sizeof(char *) * (ft_count_index(s, c) + 1))))
		return (NULL);
	words = ft_count_index(s, c);
	while (*s && index < words)
	{
		while (*s && *s == c)
			s++;
		if (!ft_malloc_index(tab, s, c, index))
			return (NULL);
		i = 0;
		while (*s && *s != c)
			tab[index][i++] = *s++;
		tab[index++][i] = '\0';
	}
	tab[index] = 0;
	return (tab);
}