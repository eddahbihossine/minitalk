/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:05:48 by heddahbi          #+#    #+#             */
/*   Updated: 2023/03/10 00:18:57 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>

void	ft_write_bits(int x);
void	my_function(int pid, char *str);
void	signal_control(int x, siginfo_t *info, void *ucontext);
int		ft_atoi( const char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	check_arguments(char *str);
int		ft_isdigit(int c);
void	ft_error(void);
void	ft_bzero(void *s, size_t n);

typedef struct s_unicode
{
	int		i;
	int		nbytes;
	char	p[4];
}				t_unicode;
#endif