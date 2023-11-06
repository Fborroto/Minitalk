/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 02:14:23 by fborroto          #+#    #+#             */
/*   Updated: 2023/03/16 02:14:23 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
		i += ft_putchar(n + 48);
	else
	{
		i += ft_unsigned(n / 10);
		i += ft_unsigned(n % 10);
	}
	return (i);
}
