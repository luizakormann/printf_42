/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:07:54 by luiza             #+#    #+#             */
/*   Updated: 2025/01/04 02:19:20 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_size(unsigned long number)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= 16;
		len++;
	}
	return (len);
}

static char	*to_hex(unsigned long pnt)
{
	char	*hex_pnt;
	char	*hex;
	int		size_hex;

	hex = "0123456789abcdef";
	size_hex = calc_size(pnt);
	hex_pnt = (char *)malloc(size_hex + 1);
	if (!hex_pnt)
		return (NULL);
	hex_pnt[size_hex] = '\0';
	while (size_hex--)
	{
		hex_pnt[size_hex] = hex[pnt % 16];
		pnt = pnt / 16;
	}
	return (hex_pnt);
}

int	ft_putpnt(unsigned long pnt)
{
	char	*hex_pnt;
	int		hex_size;

	if (pnt == 0)
		return (write(1, "(nil)", 5));
	hex_pnt = to_hex(pnt);
	if (!hex_pnt)
		return (0);
	hex_size = calc_size(pnt);
	write(1, "0x", 2);
	write(1, hex_pnt, hex_size);
	free(hex_pnt);
	return (hex_size + 2);
}

int	puthexa_up(unsigned int nbr)
{
	int	hexa_count;

	hexa_count = 0;
	if (nbr >= 16)
		hexa_count += puthexa_up(nbr / 16);
	if ((nbr % 16) < 10)
		hexa_count += ft_putchar((nbr % 16) + '0');
	else
		hexa_count += ft_putchar((nbr % 16) - 10 + 'A');
	return (hexa_count);
}

int	puthexa_low(unsigned int nbr)
{
	int	hexa_count;

	hexa_count = 0;
	if (nbr >= 16)
		hexa_count += puthexa_low(nbr / 16);
	if ((nbr % 16) < 10)
		hexa_count += ft_putchar((nbr % 16) + '0');
	else
		hexa_count += ft_putchar((nbr % 16) - 10 + 'a');
	return (hexa_count);
}
