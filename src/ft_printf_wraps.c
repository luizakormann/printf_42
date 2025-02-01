/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_wraps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:02:45 by luiza             #+#    #+#             */
/*   Updated: 2025/02/01 01:44:05 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	wrap_char(va_list *args)
{
	return (ft_putchar(va_arg(*args, int)));
}

int	wrap_str(va_list *args)
{
	return (ft_putstr(va_arg(*args, char *)));
}

int	wrap_int(va_list *args)
{
	return (putnbr(va_arg(*args, int)));
}

int	wrap_uint(va_list *args)
{
	return (putnbr_u(va_arg(*args, unsigned int)));
}

int	wrap_ptr(va_list *args)
{
	return (ft_putptr(va_arg(*args, void *)));
}

int	wrap_hex_low(va_list *args)
{
	return (puthexa(va_arg(*args, unsigned int), 0));
}

int	wrap_hex_up(va_list *args)
{
	return (puthexa(va_arg(*args, unsigned int), 1));
}
