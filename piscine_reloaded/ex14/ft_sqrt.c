int ft_sqrt(int nb)
{
	int rslt = nb;
	int div = nb;
	if (nb <= 0) return 0;
	while (1)
	{
		div = (nb / div + div) / 2;
		if (rslt > div)
      rslt = div;
		else
      if (rslt * rslt == nb)
        return rslt;
      else return (0);
	}
}
