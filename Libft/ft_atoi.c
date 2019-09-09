static int ft_isdigit(int c)
{
  return (c >= '0' && c <= '9');
}

static long atol(const char *num)
{
	long value = 0;
	int neg = 0;

    while (ft_isspace(num))
    if (num[0] == '-') 
    {
        neg = 1;
        num++;
    }
    while (*num && ft_isdigit(*num))
        value = value * 10 + *num++  - '0';
	if (neg)
		value = -value;
	return value;
}

int atoi(const char *num)
{
	return atol(num);
}