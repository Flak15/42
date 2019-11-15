#include "fillit.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


int ft_pow(int base, int n) //дописать проверки переполнения и тд
{
	int i;
	int p;

	p = 1;
	i = 1;
	while (i++ <= n)
		p = p * base;
	return (p);	
}

short tetromino_parse(char *tetr_str)
{
	short tetromino;
	int i;

	tetromino = 0;
	while (i < 19)
	{
		if (tetr_str[i] == '#')
		{
			tetromino = tetromino | ((short)ft_pow(2, 15 - i));
		}
		
			
		i++;
	}

	return (tetromino);
}

int main(int argc, char **argv)
{
	int fd;
	char buf[20];

	if (argc != 2)
	{
		printf("err\n");
		return (1);
	}
	
	fd = open(argv[1], O_RDONLY, 0);
	read(fd, buf, 19);
	buf[19] = '\0';
	// printf("short %d\n", tetromino_parse(buf));
	printf("%s\n", buf);
	return (0);
}