#include "libft.h"

size_t	count_array(char *str, char word)
{
	size_t	i;
	size_t	num_array;

	i = 0;
	num_array = 0;
	while (str[i] != '\0')
	{
		while (str[i] == word && str[i] != '\0')
			i++;
		if (str[i] != word && str[i] != '\0')
		{
			while (str[i] != word && str[i] != '\0')
				i++;
			num_array++;
		}
	}
	return (num_array);
}

char	*ft_mystrdup(char *str, size_t len)
{
	size_t	i;
	char	*rtn_str;

	rtn_str = (char *) malloc (sizeof(char) * (len + 1));
	if (rtn_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && str[i] != '\0')
	{
		rtn_str[i] = str[i];
		i++;
	}
	rtn_str[i] = '\0';
	return (rtn_str);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn_str;
	size_t	i;
	size_t	j;
	size_t	array;

	array = count_array((char *)s, c);
	rtn_str = (char **) malloc (sizeof(char *) * (array + 1));
	if (rtn_str == NULL)
		return (NULL);
	j = 0;
	while (j < array)
	{
		i = 0;
		while (((char *)s)[i] != '\0' && ((char *)s)[i] == c)
			i++;
		s = s + i;
		i = 0;
		while (((char *)s)[i] != '\0' && ((char *)s)[i] != c)
			i++;
		rtn_str[j++] = ft_mystrdup((char *)s, i);
		s = s + i;
	}
	rtn_str[j] = NULL;
	return (rtn_str);
}

//if_null_func -> return string only

/*#include <stdio.h>

int main(void)
{
	char	a[] = "tripouille";
	char	b = 0;

	char	**c = ft_split(a, b);
	printf("%s\n", c[0]);
	printf("%s\n", c[1]);
	printf("%s\n", c[2]);
	printf("%s\n", c[3]);
	printf("%s\n", c[4]);
	free (*c);
}*/

/*#include <stdio.h>

int	main(void)
{
	char	src[] = "      ";
	char	c = ' ';
	char	**sep_str;
	char	**tmp_sep_str;
	char	**tmp2_sep_str;

	if (!(sep_str = ft_split(src, c)))
		return (0);
	tmp_sep_str = sep_str;
	tmp2_sep_str = sep_str;
	while (*sep_str)
		printf("%s\n", *sep_str++);
	while (*tmp_sep_str)
		free(*tmp_sep_str++);
	free(*tmp_sep_str);
	free(tmp2_sep_str);
	return (0);
}*/
