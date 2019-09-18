#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	flen;
	int		res;

	if (!*find)
		return ((char *)s);
	flen = ft_strlen(find);
	res = 1;
	while (*s && flen <= slen && (res = ft_strncmp(s, find, flen)))
	{
		slen--;
		s++;
	}
	return (res ? NULL : (char *)s);
}
