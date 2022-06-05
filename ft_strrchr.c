#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;
	int	len_s_tmp;
	int	i;
	char	*new_s;

	new_s = (char *) s;
	len_s = ft_strlen(s);
	len_s_tmp = len_s;
	i = 0;
	if ((char) c == '\0' || c == 0)
		return (new_s + len_s_tmp);
	while (len_s--)
	{
		if (new_s[len_s] == (char) c)
			return (new_s + len_s_tmp - i - 1);
		i++;
	}
	return (0);
}

//L19 -1 -> address back due to while(len_s--)

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[] = "tripouille";
	int b = 'l';

	printf("%s\n", ft_strrchr(a, b));

	char c[] = "tripouille";
	int d = 'l';

	printf("%s\n", strrchr(c, d));
}
*/