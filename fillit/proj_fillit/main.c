/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:55:34 by nventres          #+#    #+#             */
/*   Updated: 2019/12/28 14:20:53 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	get_solution(unsigned long *tets)
{
	unsigned long	f;
	int				i;

	f = 0;
	i = get_lfig_length(tets[0]) > get_lfig_height(tets[0]) ?
		get_lfig_length(tets[0]) : get_lfig_height(tets[0]);
	while (i <= 8)
	{
		f = proccess(&f, tets, 0, i);
		if (f != 1)
			break ;
		i++;
	}
	if (i > 8)
		ft_putstr("error\n");
	else
		render_f(tets, i);
}

int			main(int argc, char **argv)
{
	int				fd;
	char			*tet;
	unsigned short	*tets_arr;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit <file>\n");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY, 0)) == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (!(tet = parse(argv[1])) ||
	check_tet(tets_arr = parse_tet(tet), tet))
	{
		ft_putstr("error\n");
		return (1);
	}
	shift_tets(tets_arr);
	get_solution(convert_all(tets_arr));
	return (0);
}
