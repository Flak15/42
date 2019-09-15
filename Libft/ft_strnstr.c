#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	char c;
    char save_c;
	size_t len;

    c = *find;
    len = ft_strlen(find);
	if (c != '\0')
    {
        find++;
		do 
        {
			do
            {
				if ((save_c = *s++) == '\0' || slen-- < 1)
                    return (NULL);
                s++;
			} while (save_c != c);
			if (len > slen)
				return (NULL);
		} while (ft_strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}
