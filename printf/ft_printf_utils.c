/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:43:44 by dsonmez           #+#    #+#             */
/*   Updated: 2024/11/01 21:25:07 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	counter;

	counter = 0;
	write(1, &c, 1);
	counter += 1;
	return (counter);
}

int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
	{
		counter += ft_putchar(*str);
		str++;
	}
	return (counter);
}

int	ft_putnbr(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		counter += ft_putnbr(n / 10);
		counter += ft_putchar(n % 10 + '0');
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}

int	ft_putnbr_for_unsigned(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n > 9)
	{
		counter += ft_putnbr_for_unsigned(n / 10);
		counter += ft_putchar(n % 10 + '0');
	}
	else
		counter += ft_putchar(n + '0');
	return (counter);
}

int	ft_putptr(unsigned long long n, char *hex)
{
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		counter += ft_putptr(n / 16, hex);
		counter += ft_putchar(hex[n % 16]);
	}
	else
		counter += ft_putchar(hex[n % 16]);
	return (counter);
}
