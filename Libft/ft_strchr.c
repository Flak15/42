char *ft_strchr(const char *p, int ch)
{
	while (1) {
		if (*p == (char) ch)
			return((char *)p);
		if (!*p)
			return(0);
    p++;
	}
}
