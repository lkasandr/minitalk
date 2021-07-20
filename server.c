#include <signal.h>
#include <unistd.h>

void				*ft_memset(void *s, int c, size_t n)
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void process_signal(int signal)
{
	static char	c;
	static int	i;
	
	

	if (signal == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			c = '\n';
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int main()
{
	int pid;

	pid = -1;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);

	struct sigaction act;
	ft_memset(&act, 0, sizeof(act));

	act.sa_handler = process_signal;
	// act.sa_sigaction = process_signal;
	sigset_t   set; 
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	act.sa_mask = set;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
}