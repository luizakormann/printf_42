/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:47:52 by lukorman          #+#    #+#             */
/*   Updated: 2025/02/01 02:08:50 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	handle_case(va_list *args, char specifier);
static void	init_cases(t_cases *cases);

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
			count += handle_case(&args, str[i + 1]);
			if (str[i + 1] == '%')
				count++;
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	count++;
	va_end(args);
	return (count);
}

static int	handle_case(va_list *args, char specifier)
{
	t_cases	cases[8];
	int		i;

	init_cases(cases);
	if (specifier == '%')
	{
		ft_putchar('%');
		return (0);
	}
	i = 0;
	while (i < 8)
	{
		if (cases[i].specifier == specifier)
			return (cases[i].func(args));
		i++;
	}
	return (0);
}

static void	init_cases(t_cases *cases)
{
	cases[0].specifier = 'c';
	cases[0].func = wrap_char;
	cases[1].specifier = 's';
	cases[1].func = wrap_str;
	cases[2].specifier = 'd';
	cases[2].func = wrap_int;
	cases[3].specifier = 'i';
	cases[3].func = wrap_int;
	cases[4].specifier = 'u';
	cases[4].func = wrap_uint;
	cases[5].specifier = 'p';
	cases[5].func = wrap_ptr;
	cases[6].specifier = 'x';
	cases[6].func = wrap_hex_low;
	cases[7].specifier = 'X';
	cases[7].func = wrap_hex_up;
}
