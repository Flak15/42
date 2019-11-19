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
			
		// printf("%c", *str);
		str++;
	}
	return (0);
}

short *parse_tet(char *tet_str)
{
	int tets_len;
	char *tmp;
	unsigned short *tets;
	int i;

	tmp = tet_str;
	tet_str = ft_strrmchr(tet_str, '\n');
	free(tmp);
	tets_len = ft_strlen(tet_str) / 4;
	tets = (unsigned short *)ft_memalloc(sizeof(short) * (tets_len) + 1);
	tets[tets_len] = 0;
	i = 0;
	while (tet_str[i])
	{
		if (tet_str[i] == '#')
			tets[i / 16] = tets[i / 16] | 1 << (15 - i % 16);
		i++;
	}
	return (tets);
}

int check_tet(unsigned short *tets, int i)
{

	if (i <= 0 || i > 15)
		return (0);
	if (tets[0] & 1 << i)
		return (1 + check_tet(&tets[0], i - 1) + check_tet(&tets[0], i + 1) + check_tet(&tets[0], i - 4));
	else
		check_tet(tets, --i);
	
	
}

void render(unsigned short *tets)
{
	int i;

	i = 15;	 
	while (*tets)
	{
		while (i >= 0)
		{
			if ((i + 1) % 4  == 0)
				printf("\n");
			if ((i + 1) % 16  == 0)
				printf("\n");
			if (*tets & 1 << i--)
				printf("#");
			else
				printf(".");
		}
		tets++;
		i = 15;
	}
}



int main(void)
{
	int fd;
	char *tet;
	int res;
	unsigned short *tets_arr;
	unsigned short test = 61440;
	fd = 10;

	fd = open("test.txt", O_RDONLY, 0);
	tet = read_tet(fd);
	res = check_input(tet);
	tets_arr = parse_tet(tet);
	// printf("res %d\n", tets_arr[0]);
	// printf("res %d\n", tets_arr[1]);
	// printf("res %d\n", tets_arr[2]);
	// printf("res %d\n", tets_arr[3]);
	// render(&test);
	check_tet(&test, 15);
	return (0);
}
