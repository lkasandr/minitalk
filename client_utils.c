#include "minitalk.h"

static int	check_j(int j)
{
	if (j == 1)
		return (-1);
	if (j != 1)
		return (0);
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			j;
	long int	f;

	i = 0;
	j = 1;
	f = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			j = -1 * j;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((f > 2147483647 && j == 1) || (f > 2147483648 && j == -1))
			return (check_j(j));
		f = f * 10 + (str[i] - '0');
		i++;
	}
	return (j * f);
}
