/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 18:58:57 by nventres          #+#    #+#             */
/*   Updated: 2019/12/26 19:16:14 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_input(char *str)
{
	int	ch;
	int	rows;

	ch = 0;
	rows = 0;
	while (*str)
	{
		if (*str == '\n')
			if (ch == 4)
			{
				ch = 0;
				rows++;
			}
			else if (ch == 0 && rows == 4)
				rows = 0;
			else
				return (1);
		else if (*str == '#' || *str == '.')
			ch++;
		else
			return (1);
		str++;
	}
	return (0);
}
