/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:40:59 by lukorman          #+#    #+#             */
/*   Updated: 2024/12/23 17:24:27 by lukorman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

# ifndef STDOUT
#  define STDOUT 1
# endif

# include "libftprintf.h"

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int paramtype(char c, va_list args);
int ft_putchar(char c, int fd);
static char *paramcases(va_list args, char c);
char	*ft_itoa(int n);

#endif
