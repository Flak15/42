#include  "libft.h"
#include <stdlib.h>

static int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char *ft_strtrim(char const *s)
{
	char *ns;
	char *start;
	char *end;
	size_t len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	start = (char *)s;
	end = (char *)s + len - 1;
	while (ft_isspace(*start))
		start++;
	if (!*start)			
		return (start);
	while (ft_isspace(*end))
		end--;
	ns = (char *)malloc(end - start + 2);
	if (!ns)
		return (NULL);
	ft_strncpy(ns, start, end - start + 1);
	return (ns);
}
