#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n)
	{
		if (*s1 != *s2++)
			return (*s1 - *(s2 - 1));
		if (!*s1)
			return (0);
		s1++;
		n--;
	}
	return (0);
}
