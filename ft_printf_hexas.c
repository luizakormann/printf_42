/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 02:07:54 by luiza             #+#    #+#             */
/*   Updated: 2025/01/06 21:09:03 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	pnt;

	pnt = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (2 + puthexa(pnt, 0));
}

int	puthexa(unsigned long n, int is_upper)
{
	int			count;
	const char	*hex_chars;

	count = 0;
	if (is_upper == 1)
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";
	if (n >= 16)
		count += puthexa(n / 16, is_upper);
	count += ft_putchar(hex_chars[n % 16]);
	return (count);
}
