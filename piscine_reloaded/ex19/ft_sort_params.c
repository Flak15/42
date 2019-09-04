/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nventres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 17:09:00 by nventres          #+#    #+#             */
/*   Updated: 2019/09/04 17:09:01 by nventres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	swap(char **tab, int i, int j)
{
	char *temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
	}
	return (*s1 - *(s2 - 1));
}

void	print_param(char *param)
{
	while (*param)
	{
		ft_putchar(*param);
		param++;
	}
}

void	f_qsort(char **tab, int left, int right)
{
	int i;
	int	last;

	if (left >= right)
		return ;
	swap(tab, left, (left + right) / 2);
	last = left;
	i = left + 1;
	while (i <= right)
	{
		if (ft_strcmp(tab[i], tab[left]) > 0)
			swap(tab, ++last, i);
		i++;
	}
	swap(tab, left, last);
	f_qsort(tab, left, last - 1);
	f_qsort(tab, last + 1, right);
}

int		main(int argc, char **argv)
{
	int count;

	if (argc == 0)
		return (0);
	f_qsort(argv, 1, argc - 1);
	count = argc - 1;
	while (count >= 1)
	{
		print_param(argv[count]);
		ft_putchar('\n');
		count--;
	}
	return (0);
}
