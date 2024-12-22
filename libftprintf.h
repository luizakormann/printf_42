/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:40:59 by lukorman          #+#    #+#             */
/*   Updated: 2024/12/22 00:36:17 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

# ifndef STDOUT
#  define STDOUT 1
# endif

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
int paramtype(char c, va_list args);
int ft_putchar(char c, int fd);
static char *paramcases(va_list args, char c);
char	*ft_itoa(int n);

#endif
