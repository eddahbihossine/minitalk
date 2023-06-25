/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:05:53 by heddahbi          #+#    #+#             */
/*   Updated: 2023/03/10 00:09:28 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handle(unsigned	char set, siginfo_t *info);

int	return_x(int x)
{
	if (x == SIGUSR1)
		x = 1;
	else
		x = 0;
	return (x);
}

void	handle_unicode(unsigned	char byte, siginfo_t *info)
{
	static t_unicode	params;
	static int			client_pid;

	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		params.i = 0;
		params.nbytes = 0;
		ft_bzero(params.p, 4);
	}
	if (byte >= 192 && byte <= 223)
		params.nbytes = 2 ;
	else if (byte >= 224 && byte <= 239)
		params.nbytes = 3;
	else if (byte >= 240 && byte <= 255)
		params.nbytes = 4 ;
	params.p[params.i++] = byte;
	if (params.i == params.nbytes)
	{
		write(1, params.p, params.nbytes);
		params.i = 0;
		params.nbytes = 0;
		bzero(params.p, 4);
	}
}

void	signal_control(int x, siginfo_t *info, void *ucontext)
{
	static int				bits = 7;
	static unsigned char	set = 0;
	static int				client_pid;
	static int				current_pid;

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
		ft_handle(set, info);
		set = 0;
		bits = 7;
	}
	else
		bits--;
}

void	ft_handle(unsigned	char set, siginfo_t *info)
{
	if (set == '\0')
		kill(info->si_pid, SIGUSR1);
	if (set >= 0 && set < 128)
		ft_putchar(set);
	else
		handle_unicode(set, info);
}

int	main(int ac, char *av[])
{
	int						pid;
	struct sigaction		sa;

	(void)av;
	if (ac > 1)
	{
		ft_putstr("error while enteringthe params\n");
		ft_putstr("     **HINT : ./server \n");
		exit(1);
	}
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
