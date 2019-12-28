/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:58:57 by nventres          #+#    #+#             */
/*   Updated: 2019/12/28 14:20:36 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		checkconsist(char *buf)
{
	int		i;
	int		hashcount;

	i = 0;
	hashcount = 0;
	while (i < 20)
	{
		if (buf[i] != '\n' && buf[i] != '.' && buf[i] != '#')
			return (0);
		if (buf[i] == '\n' && !(i % 5))
			return (0);
		if (buf[i] == '#')
			hashcount++;
		i++;
	}
	if (hashcount != 4 || (buf[i] != '\0' && buf[i] != '\n'))
		return (0);
	return (1);
}

static int		validate(char *buf, int bytesread)
{
	int		i;
	int		tetramcount;

	i = 0;
	tetramcount = 0;
	while (i <= bytesread)
	{
		if (!checkconsist(buf + i))
			return (0);
		i += 21;
		tetramcount++;
	}
	return (tetramcount);
}

char			*parse(char *argv)
{
	int		fd;
	int		bytesread;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * 545);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	bytesread = read(fd, buf, 545);
	close(fd);
	if (bytesread > 544 || bytesread < 19)
		return (0);
	buf[bytesread] = '\0';
	if (!(validate(buf, bytesread)))
		return (0);
	return (buf);
}
