/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:02:47 by fborroto          #+#    #+#             */
/*   Updated: 2023/11/08 12:36:43 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

void	action(int sig, siginfo_t *info, void *context)
{
	static int	bit;
	static int	clientpid;
	static char	c;

	(void)context;
	clientpid = info->si_pid;
	bin_to_char(sig, &c);
	if (++bit == 8)
	{
		bit = 0;
		if (!c)
		{
			kill(clientpid, SIGUSR1);
			clientpid = 0;
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	kill(clientpid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = &action;
	if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &s_sigaction, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
	while (1)
		pause();
	return (0);
}
