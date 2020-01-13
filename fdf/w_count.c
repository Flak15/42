int	count_words(char *str, char delim)
{
	int			state;
	unsigned	wc;

	state = 0;
	wc = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == delim)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			++wc;
		}
		++str;
	}
	return (wc);
}