/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsonmez <dsonmez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:32:43 by dsonmez           #+#    #+#             */
/*   Updated: 2024/10/30 00:11:48 by dsonmez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_for_unsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_putptr(unsigned long long n, char *hex);

#endif