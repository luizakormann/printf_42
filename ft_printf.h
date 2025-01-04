/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:40:59 by lukorman          #+#    #+#             */
/*   Updated: 2025/01/04 00:23:11 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	putnbr(int n);
int	putnbr_u(unsigned int n);
int	ft_putpnt(void *ptr);
int	puthexa_low(unsigned int n);
int	puthexa_up(unsigned int n);
int	wrap_char(va_list *args);
int	wrap_str(va_list *args);
int	wrap_int(va_list *args);
int	wrap_uint(va_list *args);
int	wrap_ptr(va_list *args);
int	wrap_hex_low(va_list *args);
int	wrap_hex_up(va_list *args);

typedef struct s_format
{
	char	specifier;
	int		(*func)(va_list *);
}	t_format;

#endif
