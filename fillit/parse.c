#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>

int ft_pow(int base, int n)
{
	int p;

	p = 1;
	while (n > 0)
	{
		p = p * base;
		n--;
	}
	return (p);
}

char *read_tet(int fd)
{
	char tmp[BUFF_SIZE + 1];
	char *tet;
	char *ftet;
	int res;

	tet = ft_strnew(1);
	while(res = read(fd, tmp, BUFF_SIZE))
	{
		tmp[res] = '\0';
		ftet = tet;
		tet = ft_strjoin(tet, tmp);
		free(ftet);
	}
	
	return (tet);
}

int check_input(char *str)
{
	int ch;
	int rows;

	ch = 0;
	rows = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			if (ch == 4)
			{
				ch = 0;
				rows++;
			}
			else if (ch == 0 && rows == 4)
				rows = 0;
			else 
			{
				printf("wrong row or col size\n");
				printf("chs: %d, rows: %d\n", ch, rows);
				return (1);
			}
		}
		else if (*str == '#' || *str == '.')
			ch++;
		else
		{
			printf("unknown symbol\n");
			return (1);
		}
			
		printf("%c", *str);
		str++;
	}
	return (0);
}

short *parse_tet(char *tet)
{
	int rows;
	int cols;
	char *tmp;

	rows = 0;
	cols = 0;

}

int main(void)
{
	int fd;
	char *tet;
	int res;

	fd = 10;

	// fd = open("test.txt", O_RDONLY, 0);
	// tet = read_tet(fd);
	// res = check_input(tet);
	// printf("res %d\n", res);
	printf("%d", fd | ft_pow(2, 7) );
	return (0);
}
