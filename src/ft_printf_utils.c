/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:57:00 by luiza             #+#    #+#             */
/*   Updated: 2025/01/04 04:37:09 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	putnbr(int n)
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
		count += putnbr(number / 10);
	count += ft_putchar((number % 10) + '0');
	return (count);
}

int	putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += putnbr_u(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
