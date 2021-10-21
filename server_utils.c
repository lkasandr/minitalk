/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:45:53 by lkasandr          #+#    #+#             */
/*   Updated: 2021/10/12 18:48:04 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
