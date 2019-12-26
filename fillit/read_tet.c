/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:58:04 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:16:58 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_tet(int fd)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tet;
	char	*ftet;
	int		res;

	tet = ft_strnew(1);
	while ((res = read(fd, tmp, BUFF_SIZE)))
	{
		tmp[res] = '\0';
		ftet = tet;
		tet = ft_strjoin(tet, tmp);
		free(ftet);
	}
	return (tet);
}
