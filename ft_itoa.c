/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiza <luiza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 00:32:54 by luiza             #+#    #+#             */
/*   Updated: 2024/12/22 00:34:42 by luiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	numlen(long num);
static char		*writenums(long num, char *res, size_t i);

char	*ft_itoa(int n)
{
	char	*res;
	size_t	nlen;
	long	num;

	num = n;
	nlen = numlen(num);
	res = (char *)malloc((nlen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[nlen] = '\0';
	return (writenums(num, res, nlen - 1));
}

static size_t	numlen(long num)
{
	size_t	nlen;

	nlen = 0;
	if (num < 0)
	{
		nlen++;
		num = -num;
	}
	if (num == 0)
		nlen++;
	while (num != 0)
	{
		num /= 10;
		nlen++;
	}
	return (nlen);
}

static char	*writenums(long num, char *res, size_t i)
{
	if (num == 0)
		res[i] = '0';
	else
	{
		if (num < 0)
		{
			res[0] = '-';
			num = -num;
		}
		while (num != 0)
		{
			res[i--] = (num % 10) + '0';
			num /= 10;
		}
	}
	return (res);
}