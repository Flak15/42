/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <nventres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:48:00 by nventres          #+#    #+#             */
/*   Updated: 2019/09/20 16:48:30 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int			ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
