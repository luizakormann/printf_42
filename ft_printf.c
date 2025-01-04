/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:47:52 by lukorman          #+#    #+#             */
/*   Updated: 2025/01/04 04:18:59 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_formats(t_format *formats);
static int	handle_format(va_list *args, char specifier);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += handle_format(&args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

static void	init_formats(t_format *formats)
{
	formats[0].specifier = 'c';
	formats[0].func = wrap_char;
	formats[1].specifier = 's';
	formats[1].func = wrap_str;
	formats[2].specifier = 'd';
	formats[2].func = wrap_int;
	formats[3].specifier = 'i';
	formats[3].func = wrap_int;
	formats[4].specifier = 'u';
	formats[4].func = wrap_uint;
	formats[5].specifier = 'p';
	formats[5].func = wrap_ptr;
	formats[6].specifier = 'x';
	formats[6].func = wrap_hex_low;
	formats[7].specifier = 'X';
	formats[7].func = wrap_hex_up;
}

static int	handle_format(va_list *args, char specifier)
{
	t_format	formats[8];
	int			i;

	init_formats(formats);
	if (specifier == '%')
		return (ft_putchar('%'));
	i = 0;
	while (i < 8)
	{
		if (formats[i].specifier == specifier)
			return (formats[i].func(args));
		i++;
	}
	return (0);
}
