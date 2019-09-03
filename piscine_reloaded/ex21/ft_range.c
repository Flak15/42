#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *res;
	int i;

	if (min >= max)
		return (0);
	res = (int *)malloc((max - min) * sizeof(int));
	if (res == NULL)
		return (res);
	i = 0;
	while (min < max)
	{
		res[i++] = min;
		++min;
	}
	return (res);
}
