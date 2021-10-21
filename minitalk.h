/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkasandr <lkasandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 18:36:24 by lkasandr          #+#    #+#             */
/*   Updated: 2021/10/18 18:18:09 by lkasandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);
void	*ft_memset(void *s, int c, size_t n);
int		ft_strlen(char *str);
void	ft_error(char *str, int i);

#endif