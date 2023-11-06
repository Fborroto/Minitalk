/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:38:12 by fborroto          #+#    #+#             */
/*   Updated: 2023/03/16 13:38:12 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
		i += ft_putchar(n + 48);
	else if (n < 16)
	{
		i += ft_putchar('a' + (n - 10));
	}
	else
	{
		i += ft_hexa(n / 16);
		i += ft_hexa(n % 16);
	}
	return (i);
}
