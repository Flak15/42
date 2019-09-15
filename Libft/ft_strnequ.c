#include <string.h>

static int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0)
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

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2 || !n)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
}