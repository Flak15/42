#define LONG_MAX 9223372036854775807
#define LONG_MIN -9223372036854775808

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
    int cutlim;

    i = 0;
    n = 0;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+') 
		sign = str[i++] == '-' ? 1 : 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        n = 10 * n + (str[i] - '0');
        cutoff = sign ? (unsigned long)LONG_MIN : LONG_MAX;
        cutlim = cutoff % 10;
        if (n > cutoff || (n == cutoff && str[i] > cutlim))
            return (sign ? (int)LONG_MIN : (int)LONG_MAX);
        i++;
    }
 	if (sign)
		n = -n;
    return ((int)n);
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