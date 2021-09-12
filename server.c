#include "minitalk.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	k;
	size_t			i;
	char			*str;

	k = (unsigned char)c;
	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = k;
		i++;
	}
	return (str);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if ((n / 10) > 0)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	hdl(int sig, siginfo_t *info, void *oldact)
{
	static int	counter;
	static char	outchar;
	void		*norm_param;
	static int	norm_pid;

	if (info->si_pid != 0)
		norm_pid = info->si_pid;
	if (info->si_pid == 0)
		info->si_pid = norm_pid;
	norm_param = oldact;
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

int	main(void)
{
	int					pid;
	struct sigaction	act;

	sigset_t   set; 

	pid = getpid();
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
	ft_memset(&act, 0, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = hdl;
	
	sigemptyset(&set);                                                             
	sigaddset(&set, SIGUSR1); 
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;

	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
