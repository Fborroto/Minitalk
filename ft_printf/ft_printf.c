/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:15:56 by fborroto          #+#    #+#             */
/*   Updated: 2023/03/09 19:15:56 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_args(char c, va_list pf)
{
	if (c == 'c')
		return (ft_putchar(va_arg(pf, int)));
	if (c == 's')
		return (ft_putstring(va_arg(pf, char *)));
	if (c == 'i')
		return (ft_putnbr(va_arg(pf, int)));
	if (c == 'd')
		return (ft_putnbr(va_arg(pf, int)));
	if (c == 'u')
		return (ft_unsigned(va_arg(pf, unsigned int)));
	if (c == 'x')
		return (ft_hexa(va_arg(pf, unsigned long)));
	if (c == 'X')
		return (ft_bighexa(va_arg(pf, size_t)));
	if (c == 'p')
		return (ft_vpointer(va_arg(pf, uintptr_t)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	pf;
	int		sum;
	int		i;

	i = 0;
	sum = 0;
	va_start(pf, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			sum += ft_args(s[i + 1], pf);
			i += 2;
		}
		else
		{
			sum += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(pf);
	return (sum);
}
