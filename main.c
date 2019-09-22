/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 13:02:49 by nventres          #+#    #+#             */
/*   Updated: 2019/09/22 15:12:04 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "ft_display_file.h"

#define BUF_SIZE 10

int		main(int argc, char **argv)
{
	int		fd;
	char	str[BUF_SIZE + 1];
	int		res;

	if (argc == 1)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while ((res = read(fd, str, BUF_SIZE)))
	{
		str[res] = '\0';
		ft_putstr(str);
	}
	close(fd);
	return (0);
}
