#include <signal.h>
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

int	ft_isdigit(int c)
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
			return (j == 1 ? -1 : 0);
		f = f * 10 + (str[i] - '0');
		i++;
	}
	return (j * f);
}

void process_signal(int signal)
{
	(void)signal;
}

static	int	send_msg(int pid, char c)
{
	int		i;
	int		check_connect;

	i = 0;
	check_connect = 0;
	while (i <= 7 && check_connect >= 0)
	{
		if (c & (1 << i))
			check_connect = kill(pid, SIGUSR1);
		else
			check_connect = kill(pid, SIGUSR2);
		i++;
		usleep(30000);
	}
	if (check_connect == -1)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int pid;
	char *str;
	int send;
	int i;

	send = 0;
	i = 0;

	pid = -1;
	if (argc != 3)
	{
		ft_putstr_fd("Error: wrong argumens!\n", 2);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];

	signal(SIGUSR1, process_signal);
	while(send == 0)
	{
		send = send_msg(pid, str[i]);
		i++;
	}
}