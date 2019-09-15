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


static int count_words(char *str, char delim)
{
    int state = 0; 
    unsigned wc = 0;

    while (*str) 
    {
        if (*str == delim) 
            state = 0;
        else if (state == 0) 
        { 
            state = 1; 
            ++wc; 
        }
        ++str; 
    } 
    return (wc); 
}

// char **ft_strsplit(char const *s, char c)
// {
//     char **ss;

//     if (!s)
//         return (NULL);

    

//     ss = malloc((count_words(s, c) + 1) * sizeof(char *));
//     if (!ss)
//         return 0;
//     while(*s == c)
//         s++;
    
//     printf("%c", *s);
//     return (ss);
// }

char	**ft_strsplit(char *str, char c)
{
	int		strlen;
	char	*temp_str;
	char	**s;
	char	**save_s;

	temp_str = str;
	strlen = 0;
	s = (char **)malloc((count_words(str, c) + 1) * sizeof(char *));
	save_s = s;
	while (1)
	{
		temp_str = (*str != c && strlen == 0) ? str : temp_str;
		if ((*str == c || *str == '\0') && strlen > 0)
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

// int main(void)
// {
//     // char **r;
//     // r = ft_split_whitespaces(":::::abc:::ggg::ooo:xxx", ':');
//     for (int i= 0; i < 4; i++)
   
//         printf("%s\n", ft_split_whitespaces("aaa:::::bbb:::cc", ':')[i]);
//     return (0);
// }