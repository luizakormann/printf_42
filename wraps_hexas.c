/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps_hexas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:02:45 by luiza             #+#    #+#             */
/*   Updated: 2025/01/04 04:03:25 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	wrap_ptr(va_list *args)
{
	return (ft_putpnt(va_arg(*args, void *)));
}

int	wrap_hex_low(va_list *args)
{
	return (puthexa_low(va_arg(*args, unsigned int)));
}

int	wrap_hex_up(va_list *args)
{
	return (puthexa_up(va_arg(*args, unsigned int)));
}
