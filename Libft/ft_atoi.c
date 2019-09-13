// static int ft_isdigit(int c)
// {
//   return (c >= '0' && c <= '9');
// }

static int ft_isspace(int c)
{
  return (c == '\t' || c == '\n' ||
	    c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);
}

// static long atol(const char *num)
// {
// 	long value = 0;
// 	int neg = 0;

// 	while (ft_isspace(*num))
// 		num++;
// 	if (num[0] == '-') 
// 	{
// 		neg = 1;
// 		num++;
// 	}
// 	while (*num && ft_isdigit(*num))
// 		value = value * 10 + *num++ - '0';
// 	if (neg)
// 		value = -value;
// 	return value;
// }

// int atoi(const char *num)
// {
// 	return ((int)atol(num));
//     // return (int)strtol(str, NULL, 10);
// }

// long strtol(const char * __restrict nptr, char ** __restrict endptr, int base)
// {
//     do {
// 		c = *s++;
// 	} while (isspace_l((unsigned char)c, locale));
// 	if (c == '-') {
// 		neg = 1;
// 		c = *s++;
// 	} else {
// 		neg = 0;
// 		if (c == '+')
// 			c = *s++;
// 	}
// 	return strtol_l(nptr, endptr, base, __get_locale());
// }
#include <limits.h>
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
#include <stdio.h>

#include <stdlib.h>
int main(void)
{
    char *str = "9223372036854775809";
    printf("Lng max: %ld\n", LONG_MAX);
    printf("Lng max: %lld\n", LLONG_MAX);
    printf("my: %d\n", ft_atoi(str));
    printf("or: %d\n", atoi(str));
    return (0);
}