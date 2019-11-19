#include "libft.h"

char	*ft_strrmchr(const char *s, char c)
{
	size_t		new_len;
	char		*res;
	char		*begin;
	const char	*curr;

	curr = s;
	new_len = ft_strlen(s);
	while (*curr)
		if (*curr++ == c)
			new_len--;
	if (!(res = (char *)malloc(new_len + 1)))
		return (NULL);
	begin = res;
	while (*s)
	{
		if (*s != c)
			*res++ = *s;
		s++;
	}
	*res = '\0';
	return (begin);
}

