/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:57:00 by luiza             #+#    #+#             */
/*   Updated: 2025/01/04 02:10:25 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	str_count;

	str_count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[str_count])
		ft_putchar(str[str_count++]);
	return (str_count);
}

int	putnbr_unsigned(unsigned int nbr)
{
	int	nbr_count;

	nbr_count = 0;
	if (nbr >= 10)
		nbr_count += putnbr_unsigned(nbr / 10);
	nbr_count += ft_putchar((nbr % 10) + '0');
	return (nbr_count);
}

int	putnbr(int num)
{
	int		count;
	long	number;

	count = 0;
	number = num;
	if (num < 0)
	{
		count += ft_putchar('-');
		number *= -1;
	}
	if (number >= 10)
		count += putnbr(number / 10);
	count += ft_putchar((number % 10) + '0');
	return (count);
}
