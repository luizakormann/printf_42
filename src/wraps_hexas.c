/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraps_hexas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:02:45 by luiza             #+#    #+#             */
/*   Updated: 2025/01/06 20:52:03 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
