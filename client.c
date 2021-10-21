/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:25:15 by lkasandr          #+#    #+#             */
/*   Updated: 2021/10/21 18:47:35 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			ft_error("Wrong PID-number!\n", 1);
	}
	return (1);
}

int	get_flag(int pid, int signum)
{
	int	flag;

	flag = 0;
	if (kill(pid, signum) == -1)
		flag = 1;
	return (flag);
}

int	send_signal(char c, int pid)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < 8 && !flag)
	{
		if (c & (1 << i))
		{
			if (get_flag(pid, SIGUSR1) == 1)
				return (0);
		}
		else
		{
			if (get_flag(pid, SIGUSR2) == 1)
				return (0);
		}
		i++;
		usleep(1500);
	}
	if (i != 8)
		ft_error("can't send msg\n", 0);
	return (1);
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
		ft_error("Wrong number of arguments!\n", 1);
	check_argv(argv[1]);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_error("Wrong PID-number!\n", 1);
	signal(SIGUSR1, get_signal);
	while (argv[2][i])
	{
		if (!send_signal(argv[2][i], pid))
			ft_error("Wrong PID-number!\n", 1);
		i++;
	}
	if (!send_signal('\0', pid))
		ft_error("Wrong PID-number!\n", 1);
	write(1, "message delivered!\n", 19);
	return (0);
}
