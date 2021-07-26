#include "minitalk.h"


static int check_j(int j)
{
	if (j == 1)
		return (-1);
	if (j != 1)
		return (0);
	return (0);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int					ft_atoi(const char *str)
{
	size_t			i;
	int				j;
	long int		f;

	i = 0;
	j = 1;
	f = 0;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
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

static int check_argv(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int send_signal(char c, int pid)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		i++;
		usleep(2000);
	}
	return (1);
}

void get_signal(int signum)
{
	write(1, "ok!\n", 4);
}

int main(int argc, char **argv)
{
	int pid;
	int i;
	int count;

	i = 0;
	count = 128;
	if (argc != 3)
	{
		write(2, "Wrong number of arguments!\n", 27);
		exit(EXIT_FAILURE);
	}
	if (!check_argv(argv[1]))
	{
		write(2, "Wrong PID-number!\n", 18);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		write(2, "Wrong PID-number!\n", 18);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, get_signal);
	while(argv[2][i])
	{
		if (!send_signal(argv[2][i], pid))
		{
			write(2, "Wrong PID-number!\n", 18);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
