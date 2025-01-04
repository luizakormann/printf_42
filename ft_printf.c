/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:47:52 by lukorman          #+#    #+#             */
/*   Updated: 2025/01/04 02:05:17 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	paramcases(va_list args, char c);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += paramcases(args, str[i + 1]);
			i++;
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

static int	paramcases(va_list args, char c)
{
	int	param_count;

	param_count = 0;
	if (c == '%')
		param_count += ft_putchar('%');
	else if (c == 'c')
		param_count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		param_count += ft_putstr(va_arg(args, const char *));
	else if (c == 'd' || c == 'i')
		param_count = putnbr(va_arg(args, int));
	else if (c == 'p')
		param_count += ft_putpnt(va_arg(args, unsigned long));
	else if (c == 'u')
		param_count += putnbr_unsigned(va_arg(args, unsigned int));
	else if (c == 'X')
		param_count += puthexa_up(va_arg(args, unsigned int));
	else if (c == 'x')
		param_count += puthexa_low(va_arg(args, unsigned int));
	return (param_count);
}
