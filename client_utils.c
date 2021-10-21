/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:35:49 by lkasandr          #+#    #+#             */
/*   Updated: 2021/10/18 18:18:12 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *str, int i)
{
	write(2, str, ft_strlen(str));
	if (i == 1)
		exit(EXIT_FAILURE);
}
