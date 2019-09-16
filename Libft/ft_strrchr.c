char *ft_strrchr(const char *p, int ch)
{
	char *save;

	save = 0;
	while (1)
  	{
		if (*p == (char) ch)
			save = (char *)p;
		if (!*p)
			return(save);
    ++p;
	}
}
