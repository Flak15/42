/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 16:57:52 by nventres          #+#    #+#             */
/*   Updated: 2019/09/04 16:57:53 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int rslt;
	int div;

	rslt = nb;
	div = nb;
	if (nb <= 0)
		return (0);
	while (1)
	{
		div = (nb / div + div) / 2;
		if (rslt > div)
			rslt = div;
		else
		{
			if (rslt * rslt == nb)
				return (rslt);
			else
				return (0);
		}
	}
}
