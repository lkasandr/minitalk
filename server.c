/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:39:13 by lkasandr          #+#    #+#             */
/*   Updated: 2021/10/21 18:41:54 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	hdl(int sig, siginfo_t *info, void *oldact)
{
	static int	counter;
	static char	outchar;
	static int	norm_pid;

	if (info->si_pid != 0)
		norm_pid = info->si_pid;
	if (info->si_pid == 0)
		info->si_pid = norm_pid;
	oldact = NULL;
	if (sig == SIGUSR1)
		outchar += 1 << counter;
	counter++;
	if (counter == 8)
	{
		write(1, &outchar, 1);
		counter = 0;
		outchar = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	print_pid(int pid)
{
	if (pid <= 0)
	{
		write(2, "Wrong PID-number!\n", 18);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(1, "PID = ", 6);
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	print_pid(pid);
	ft_memset(&act, 0, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = hdl;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
