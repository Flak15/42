/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:54:33 by nventres          #+#    #+#             */
/*   Updated: 2019/09/04 17:54:34 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_file(char const *name)
{
	int		fd;
	char	buf[1];

	fd = open(name, O_RDONLY);
	while (read(fd, buf, sizeof(buf)))
	{
		write(1, buf, sizeof(buf));
	}
	close(fd);
}

int		main(int argc, char const *argv[])
{
	if (argc == 2)
		print_file(argv[1]);
	else if (argc < 2)
		write(2, "File name missing.\n", 19);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
