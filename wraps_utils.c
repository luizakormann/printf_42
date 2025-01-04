/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:01:05 by luiza             #+#    #+#             */
/*   Updated: 2025/01/04 04:02:28 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (putnbr_unsigned(va_arg(*args, unsigned int)));
}
