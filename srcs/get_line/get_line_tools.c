
#include "../../includes/get_line.h"


/***
 * this function is just used to join two string s1 and s2 
 * with the right size of malloc
 * and return then joined string 
 * 
 * */

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	s1_len;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	total_len = strlen(s1) + strlen(s2);
	s1_len = strlen(s1);
	if (!(str = malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	i = 0;
	while (i < total_len)
	{
		str[i] = (i < s1_len) ? s1[i] : s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/****
 * this function is used to extract to string from another 
 * with a start position and how many letter or length we extract 
 * 
 * */
char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s || !(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[i + start] && !(start > strlen(s)))
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

