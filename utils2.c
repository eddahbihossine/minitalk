/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:03:37 by heddahbi          #+#    #+#             */
/*   Updated: 2023/03/10 00:11:57 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "minitalk_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

void	check_arguments(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
		{
			ft_error();
			exit(0);
		}
		i++;
	}
}

void	ft_error(void)
{
	ft_putstr("error while sending the signal");
	exit(1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	s = str;
}
