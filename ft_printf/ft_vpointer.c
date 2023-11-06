/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:27:28 by fborroto          #+#    #+#             */
/*   Updated: 2023/03/16 14:27:28 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vpointer_print(uintptr_t n)
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
		i += ft_vpointer_print(n / 16);
		i += ft_vpointer_print(n % 16);
	}
	return (i);
}

int	ft_vpointer(uintptr_t n)
{
	ft_putstring("0x");
	return (ft_vpointer_print(n) + 2);
}
