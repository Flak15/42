#include <stdio.h>
#include <stdlib.h>



static char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *ns;
    char *res;

    if (!len)
        return (NULL);
    ns = (char *)malloc(len + 1);
    res = ns;
    if (!ns)
        return (NULL);
    while(start--)
        s++;
    while(len--)
        *ns++ = *s++;
    return (res);
}

char **ft_strsplit(char const *s, char c)
{
    char **ss;

    if (!s)
        return (NULL);

    ss = NULL;
    while(*s == c)
        s++;
    
    printf("%c", *s);
    return (ss);
}

char	**ft_split_whitespaces(char *str, char c)
{
	int		strlen;
	char	*temp_str;
	char	**s;
	char	**save_s;

	temp_str = str;
	strlen = 0;
	while (*temp_str++)
		;
	s = (char **)malloc(sizeof(char *) * ((temp_str - str) / 2 + 1));
	save_s = s;
	while (1)
	{
		temp_str = (*str != c && strlen == 0) ? str : temp_str;
		if (*str == c && strlen > 0)
		{
			*s++ = ft_strsub(temp_str, 0, strlen);
			strlen = 0;
		}
		strlen = *str == c ? strlen : strlen + 1;
		if (!*str++)
			break ;
	}
	*s = 0;
	return (save_s);
}

static int count_words(char *s, char delim)
{
    static int wcount = 0;

    while (*s)
    {
        
    }

}

int main(void)
{
    // char **r;
    // r = ft_split_whitespaces(":::::abc:::ggg::ooo:xxx", ':');
    // for (int i= 0; i < 4; i++)
    printf("%d\n", count_words(":::::abc:::ggg::ooo:xxx", ':'));
    return (0);
}