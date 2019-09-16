
#include <limits.h>

static int ft_isspace(int c)
{
  return (c == '\t' || c == '\n' ||
	    c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

int ft_atoi(char *str) {
    int i;
    int sign;
    unsigned long n;
    unsigned long cutoff;
    int any;
    int cutlim;

    i = 0;
    n = 0;
    
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-') 
    {
		sign = 1;
		i++;
    } 
    else 
    {
		sign = 0;
		if (str[i] == '+')
			i++;
	}
    while (str[i] >= '0' && str[i] <= '9')
    {
        n = 10 * n + (str[i] - '0');
        cutoff = sign ? (unsigned long)-(LONG_MIN + LONG_MAX) + LONG_MAX
	    : LONG_MAX;
        cutlim = cutoff % 10;
        if (n > cutoff || (n == cutoff && str[i] > cutlim))
            any = -1;
        i++;
    }
    if (any < 0)
		n = sign ? LONG_MIN : LONG_MAX;
    else if (sign)
		n = -n;

    return (n);
}
// #include <stdio.h>

// #include <stdlib.h>
// int main(void)
// {
//     char *str = "9223372036854775809";
//     printf("Lng max: %ld\n", LONG_MAX);
//     printf("Lng max: %lld\n", LLONG_MAX);
//     printf("my: %d\n", ft_atoi(str));
//     printf("or: %d\n", atoi(str));
//     return (0);
// }