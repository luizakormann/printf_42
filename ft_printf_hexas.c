/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:07:54 by luiza             #+#    #+#             */
/*   Updated: 2025/01/04 03:51:55 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calc_hex_size(unsigned long number)
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

static char	*to_hex(unsigned long pnt, char *hex_chars)
{
	char	*hex_str;
	int		size;

	size = calc_hex_size(pnt);
	hex_str = (char *)malloc(size + 1);
	if (!hex_str)
		return (NULL);
	hex_str[size] = '\0';
	while (size--)
	{
		hex_str[size] = hex_chars[pnt % 16];
		pnt = pnt / 16;
	}
	return (hex_str);
}

int	ft_putpnt(void *ptr)
{
	unsigned long	pnt;
	char			*hex_str;
	int				hex_size;

	pnt = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	hex_str = to_hex(pnt, "0123456789abcdef");
	if (!hex_str)
		return (0);
	hex_size = calc_hex_size(pnt);
	ft_putstr("0x");
	write(1, hex_str, hex_size);
	free(hex_str);
	return (hex_size + 2);
}

int	puthexa_low(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += puthexa_low(n / 16);
	if ((n % 16) < 10)
		count += ft_putchar((n % 16) + '0');
	else
		count += ft_putchar((n % 16) - 10 + 'a');
	return (count);
}

int	puthexa_up(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += puthexa_up(n / 16);
	if ((n % 16) < 10)
		count += ft_putchar((n % 16) + '0');
	else
		count += ft_putchar((n % 16) - 10 + 'A');
	return (count);
}
