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
int	puthexa_low(unsigned int nbr);
int	puthexa_up(unsigned int nbr);
int	putnbr_unsigned(unsigned int nbr);
int	ft_putstr(const char *str);
int	ft_putchar(int c);
int	putnbr(int num);
int	ft_putpnt(unsigned long pnt);

#endif
