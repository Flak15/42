/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:16:23 by nventres          #+#    #+#             */
/*   Updated: 2019/09/22 15:24:49 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>//
#include "get_next_line.h"
#include "libft.h"
int check_line(char *str)
{
	while (*str)
		if (*str == '\n')
			return (1);
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static char *file = "";
	int res;
	char str[BUFF_SIZE + 1];
	// char *tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	// tmp = (char *)malloc(BUFF_SIZE + 1);
	while (res != 0)
	{
		res = read(fd, str, BUFF_SIZE);

		file = ft_strjoin(file, str);
		
	}

	*line = file;
	if (res == -1)
		return (-1);


	return (res < BUFF_SIZE ? 0 : 1);
}



int main(void)
{
	int fd;
	char *s;
	int res;

	fd = open("test.txt", O_RDONLY);

 	get_next_line(fd, &s);
	printf("%s", s);
	return (0);
}
