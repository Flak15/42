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

#include "get_next_line.h"

int check_line(char *str)
{
	while (*str)
		if (*str == '\n')
			return (1);
	return (0);
}

int get_next_line(const int fd, char **line)
{

	int res;
	char str[BUFF_SIZE + 1];
	char *tmp;
	
	if (fd < 0 || line == NULL)
		return (-1);

	while (res != 0)
	{
		res = read(fd, str, BUFF_SIZE);
		tmp = (char *)malloc(BUFF_SIZE + 1);
		line = ft_strjoin();
	}
		
	if (res == -1)
		return (-1);

	*line = str;
	return (res < BUFF_SIZE ? 0 : 1);
}

#include <stdio.h>

int main(void)
{
	int fd;
	char *s;
	int res;

	fd = open("test.txt", O_RDONLY);
	while (res > 0)
	{
		res = get_next_line(fd, &s);
		
	}
	printf("%s", s);
	return (0);
}
