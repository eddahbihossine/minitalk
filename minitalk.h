/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:47:09 by heddahbi          #+#    #+#             */
/*   Updated: 2023/03/10 00:10:53 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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

#endif
