/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:05:42 by heddahbi          #+#    #+#             */
/*   Updated: 2023/03/10 00:06:41 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	return_x(int x)
{
	if (x == SIGUSR1)
		x = 1;
	else
		x = 0;
	return (x);
}

void	signal_control(int x, siginfo_t *info, void *ucontext)
{
	static int	bits = 7;
	static char	set = 0;
	static int	client_pid;
	static int	current_pid;

	(void)ucontext;
	if (!client_pid)
		client_pid = info->si_pid;
		current_pid = info->si_pid;
	if (client_pid != current_pid)
	{
		client_pid = current_pid;
		set = 0;
		bits = 7;
	}
	x = return_x(x);
	set += (x << bits);
	if (bits == 0)
	{
		ft_putchar(set);
		set = 0;
		bits = 7;
	}
	else
		bits--;
}

int	main(int ac, char *av[])
{
	int						pid;
	struct sigaction		sa;

	(void)av;
	if (ac > 1)
		ft_error();
	pid = getpid();
	ft_putnbr(pid);
	ft_putstr("\n");
	sa.sa_sigaction = signal_control;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
