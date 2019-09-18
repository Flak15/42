#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	flen;
	int		lastresult;

	if (*find == '\0')
		return ((char*)s);
	flen = ft_strlen(find);
	lastresult = 1;
	while (flen <= slen && *s != '\0' && lastresult)
	{
		lastresult = ft_strncmp(s, find, flen);
		slen--;
		s++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)s);
}
