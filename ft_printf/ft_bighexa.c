/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bighexa                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:03:02 by fborroto          #+#    #+#             */
/*   Updated: 2023/03/16 14:03:02 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bighexa(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
		i += ft_putchar(n + 48);
	else if (n < 16)
	{
		i += ft_putchar('A' + (n - 10));
	}
	else
	{
		i += ft_bighexa(n / 16);
		i += ft_bighexa(n % 16);
	}
	return (i);
}
