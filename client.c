/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:05:38 by heddahbi          #+#    #+#             */
/*   Updated: 2023/03/10 00:11:06 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void);

void	my_function(int pid, char *str)
{
	unsigned char	c;
	int				i;

	while (*str)
	{
		i = 7;
		c = *str++;
		while (i >= 0)
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
		i--;
		}
	}
}

int	main(int ac, char *av[])
{
	int	server_pid;

	if (ac != 3)
	{
		ft_error();
	}
	else
	{
		server_pid = ft_atoi(av[1]);
		check_arguments(av[1]);
		if (server_pid <= 0)
			ft_error();
		my_function(server_pid, av[2]);
	}
}
