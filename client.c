/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:01:50 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/07 23:35:52 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sig)
{
	(void)sig;
	ft_printf("Message received\n");
	exit(0);
}

static void	sig_kill(int pid, char *str)
{
	int	bit;
	int	c;

	while (*str)
	{
		bit = 8;
		c = *str++;
		while (bit--)
		{
			if (c >> bit & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("Usage: ./client [PID] [message]\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	ft_printf("Message sent\n");
	signal(SIGUSR2, action);
	sig_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
