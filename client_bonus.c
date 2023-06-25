/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:05:45 by heddahbi          #+#    #+#             */
/*   Updated: 2023/03/10 00:11:48 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minitalk_bonus.h"

void	ft_error(void);

void	my_function(int pid, char *str)
{
	unsigned char	c;
	int				i;
	int				len;

	len = strlen(str);
	while (len >= 0)
	{
		i = 8;
		c = *str++;
		while (--i >= 0)
		{
			if ((c >> i) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error();
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_error();
			}	
			usleep(500);
		}
		len--;
	}
}

void	receive_message(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("SIGNAL SENT SUCCESSFULLY\n");
	exit(0);
}

int	main(int ac, char *av[])
{
	int		server_pid;

	signal(SIGUSR1, receive_message);
	if (ac != 3)
		ft_error();
	else
	{
		server_pid = ft_atoi(av[1]);
		check_arguments(av[1]);
		if (server_pid <= 0)
			ft_error();
		my_function(server_pid, av[2]);
	}
	while (1)
		pause();
}
