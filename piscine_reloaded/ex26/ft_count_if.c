int	ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (tab[i])
	{
		cnt = (*f)(tab[i]) == 1 ? cnt + 1 : cnt;
		i++;
	}
	return (cnt);
}
