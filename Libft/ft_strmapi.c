#include <string.h>
#include <stdlib.h>

static size_t ft_strlen(const char *str)
{
    const char *s;

    s = str;
    while (*s)
        s++;
    return (s - str);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t len;
	char *ns;
	char *save_ns;
	unsigned int cnt;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ns = (char *)malloc(len + 1);
	if (!ns)
		return (NULL);
	cnt = 0;
	save_ns = ns;
	while(*s)
	{
		*ns = (*f)(cnt++, *s++);
		ns++;
	}
	return (save_ns);
}
