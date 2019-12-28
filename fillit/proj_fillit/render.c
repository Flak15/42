/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 19:05:13 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:17:07 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	render_f(unsigned long *tets, int f_size)
{
	int	i;
	int	tet;
	int	printed;

	i = 63;
	while (i >= 0)
	{
		tet = 0;
		printed = 0;
		if ((i + 1) % 8 == 0 && (i / 8 >= 8 - f_size) && i != 63)
			ft_putchar('\n');
		while (tets[tet])
		{
			if (tets[tet++] & ((unsigned long)1 << (i)))
			{
				ft_putchar('A' + tet - 1);
				printed = 1;
				break ;
			}
		}
		if (!printed && (i % 8 >= 8 - f_size) && (i / 8 >= 8 - f_size))
			ft_putchar('.');
		i--;
	}
	ft_putchar('\n');
}
