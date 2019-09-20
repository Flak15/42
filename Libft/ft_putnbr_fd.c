#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    long ln;

	ln = n;
	if (n < 0)
	{
        ln = -(long)n;
		ft_putchar_fd('-', fd);
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putchar_fd(ln % 10 + '0', fd);
	}
	else
		ft_putchar_fd(ln + '0', fd);
}
