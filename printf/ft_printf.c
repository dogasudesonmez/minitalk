/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:34:11 by dsonmez           #+#    #+#             */
/*   Updated: 2024/11/01 21:22:59 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list arg, char *str)
{
	int	counter;

	counter = 0;
	if (*str == 'c')
		counter = ft_putchar(va_arg(arg, int));
	else if (*str == 's')
		counter = ft_putstr(va_arg(arg, char *));
	else if (*str == 'd' || *str == 'i')
		counter = ft_putnbr(va_arg(arg, int));
	else if (*str == 'u')
		counter = ft_putnbr_for_unsigned(va_arg(arg, unsigned int));
	else if (*str == 'p')
	{
		counter += write(1, "0x", 2);
		counter += ft_putptr(va_arg(arg, unsigned long long), HEX_LOW_BASE);
	}
	else if (*str == 'x')
		counter += ft_putptr(va_arg(arg, unsigned int), HEX_LOW_BASE);
	else if (*str == 'X')
		counter += ft_putptr(va_arg(arg, unsigned int), HEX_UPP_BASE);
	else if (*str == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			counter += ft_format(arg, (char *)str);
		}
		else
			counter += ft_putchar(*str);
		str++;
	}
	va_end(arg);
	return (counter);
}
