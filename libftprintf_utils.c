/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:57:00 by luiza             #+#    #+#             */
/*   Updated: 2024/12/22 00:42:01 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int paramtype(char c, va_list args)
{
    int     res;

    res = 0;
    
    if (c == 'c')
        res = ft_putchar(va_arg(args, int), STDOUT);
}

int ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

static char *paramcases(va_list args, char c)
{
    char    *param;
    
    param = NULL;
    if (c == '%')
        param = "%";
    else if (c == 's')
        param = checkstr(va_arg(args, char *));
    else if (c == 'd' || c == 'i')
        param = ft_itoa(va_arg(args, int));
    /* 
    faltam:
    p -> imprime endereço do ponteiro void em formato hexa
    u -> imprime numero decimal (base 10) sem sinal
    X -> imprime número formato hexadecimal (base 16) em maiúsculas.
    x -> imprime número formato hexadecimal (base 16) em minúsculas.
    VER COMO IMPLEMENTASR MINHA LIBFT AQUI ITOA ESTÁ ATOA
     */
    return (param);
}

static char *checkstr(char *str)
{
    if (!str)
        return (NULL);
    else
        return (str);
}
