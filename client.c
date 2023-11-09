/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:01:50 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/09 15:12:46 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiving = 0;

void	action(int sig)
{
	static int	i;

	g_receiving = 1;
	if (sig == SIGUSR2)
		i++;
	else if (sig == SIGUSR1)
		ft_printf("Message received: %d bytes\n", i);
}

int	sig_kill(pid_t pid, char c)
{
	int	bit;
	int	itr;

	bit = 7;
	while (bit >= 0)
	{
		itr = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiving == 0)
		{
			if (itr == 50)
				handle_errors("No response from server\n");
			itr++;
			usleep(100);
		}
		g_receiving = 0;
		bit--;
	}
	return (0);
}

void	checker(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
		handle_errors("Usage: ./client [PID] [message]\n");
	if (ft_atoi(argv[1]) < 1)
		handle_errors("Invalid PID");
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			handle_errors("Invalid PID");
}

int	main(int argc, char **argv)
{
	struct sigaction	signal;
	int					c;
	pid_t				pid;

	checker(argc, argv);
	c = -1;
	pid = ft_atoi(argv[1]);
	signal.sa_handler = action;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = 0;
	if (sigaction(SIGUSR1, &signal, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &signal, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
	while (argv[2][++c])
		sig_kill(pid, argv[2][c]);
	sig_kill(pid, '\0');
	return (0);
}
