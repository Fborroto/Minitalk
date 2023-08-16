/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 16:01:50 by fborroto          #+#    #+#             */
/*   Updated: 2023/08/13 19:34:48 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <signal.h>

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int  ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (ret > INT_MAX)
			return (-1);
		else if (ret < INT_MIN)
			return (0);
	}
	return ((int)ret);
}

static void	action(int sig)
{
	static int	i = 0;

	if (sig == SIGUSR1)
		++i;
	else
	{
		printf("%i\n",i);
		exit(0);
	}
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
			usleep(1000);
		}
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		usleep(1000);
	}
}

int	main(int argc, char **argv)
{
 	if (argc != 3 || !strlen(argv[2]))
	{
		printf("Usage: ./client [PID] [message]\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Invalid PID\n");
		return (1);
	}
	printf("Sent    : ");
	printf("%i\n",(int)strlen(argv[2]));
	printf("Received: ");
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	sig_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
