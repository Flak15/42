#include  "libft.h"
#include <stdlib.h>

static int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}
#include <stdio.h>
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
	// if (!*start)			
	// 	return (*ns = '\0');
	while (ft_isspace(*end))
		end--;
	len = end - start > 0 ? end - start + 1 : 1;
	ns = (char *)malloc(len);
	if (!ns)
		return (NULL);
	ft_strncpy(ns, start, len);
	*(ns + len) = '\0';
	return (ns);
}
