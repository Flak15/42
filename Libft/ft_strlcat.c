#include "libft.h"

size_t ft_strlcat(char *dest, const char *src, size_t size)
{
    const char	*savedest;
	size_t	    n;
	size_t		handled_len;

	savedest = dest;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	handled_len = dest - savedest;
	n = size - handled_len;
	if (n == 0)
		return (ft_strlen(src) + handled_len);
	n--;
	while (*src && n)
	{
		*dest = *src;
		n--;
		dest++;
		src++;
	}
	handled_len = dest - savedest;
	*dest = '\0';
	return (ft_strlen(src) + handled_len);
}
