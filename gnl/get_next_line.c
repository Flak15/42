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
#include "libft.h"

int get_next_line(const int fd, char **line)
{

	int res;
	char str[BUFF_SIZE];

	(void)line;
	while ((res = read(fd, str, BUFF_SIZE)))
	{
		str[res] = '\0';
		ft_putstr(str);
	}
	return (0);
}

#include <stdio.h>

int main(void)
{
	int fd;
	char *s;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd, &s);
	// printf("%s", s);
	return (0);
}
