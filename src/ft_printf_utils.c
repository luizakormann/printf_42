/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:57:00 by luiza             #+#    #+#             */
/*   Updated: 2025/02/01 02:13:23 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	count;

	if (!str)
		return (ft_putstr("(null)"));
	count = 0;
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int		count;
	long	number;

	count = 0;
	number = n;
	if (number < 0)
	{
		count += ft_putchar('-');
		number = -number;
	}
	if (number >= 10)
		count += ft_putnbr(number / 10);
	count += ft_putchar((number % 10) + '0');
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	pnt;

	pnt = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + ft_puthexa(pnt, 0));
}

int	ft_puthexa(unsigned long n, int is_upper)
{
	int			count;
	const char	*hex_chars;

	count = 0;
	if (is_upper == 1)
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthexa(n / 16, is_upper);
	count += ft_putchar(hex_chars[n % 16]);
	return (count);
}

