#include "minitalk.h"

#include <stdio.h>

static int	check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
		{
			write(2, "Wrong PID-number!\n", 18);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

int	send_signal(char c, int pid)
{
	// char *buf;
	// int signum;
	// int	i;
	// int j;

	// i = 7;
	// j = 0;
	// buf = (char *)malloc(sizeof(char) * 8);
	// if (!buf)
	// {
	// 	write(2, "error: malloc!\n", 15);
	// 	return (0);
	// }
	// while(i >= 0 && j < 8)
	// {
		
	// 	buf[i] = c & (1 << j);
	// 	if (buf[i] != 0)
	// 		buf[i] /= buf[i];
	// 	i--;
	// 	j++;
	// }
	

	// j = 0;
	// while (j < 8)
	// {
	// 	// printf("%d: %d\n", j, buf[j]);
	// 	if (buf[j] == '0')
	// 		signum = SIGUSR1;
	// 	else if (buf[j] == '1')
	// 		signum = SIGUSR2;
	// 	if (kill(pid, signum) == -1)
	// 		return (0);
	// 	j++;
	// 	usleep(500);
	// }

	// free(buf);

	// i = pid;


	int i;
	int flag;

	i = 0;
	flag = 0;

	while (i < 8 && !flag)
	{
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				flag = 1;
				return (0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				flag = 1;
				return (0);
			}
		}
		i++;
		usleep(500);
		// pause();
	}
	if (i != 8)
		printf("can't send msg\n");
	return (1);
}

static int	check_pid(int pid)
{
	if (pid <= 0)
	{
		write(2, "Wrong PID-number!\n", 18);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	get_signal(int signum)
{
	int	i;

	i = signum;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(2, "Wrong number of arguments!\n", 27);
		exit(EXIT_FAILURE);
	}
	check_argv(argv[1]);
	pid = ft_atoi(argv[1]);
	check_pid(pid);
	signal(SIGUSR1, get_signal);
	while (argv[2][i])
	{
		if (!send_signal(argv[2][i], pid))
		{
			write(2, "Wrong PID-number!\n", 18);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (!send_signal('\0', pid))
	{
		write(2, "Wrong PID-number!\n", 18);
		exit(EXIT_FAILURE);
	}
	if (signal(SIGUSR1, get_signal))
		write(1, "message delivered!\n", 19);
	return (0);
}

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab
