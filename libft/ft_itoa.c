/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:09:56 by afaucher          #+#    #+#             */
/*   Updated: 2014/01/06 19:00:32 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	negative(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char		*ft_itoa(int n)
{
	int		digit;
	long	numb;
	int		isnegative;
	char	*str;

	digit = 0;
	isnegative = negative(n);
	numb = (long) n * isnegative;
	while (n >= 10 || n <= -10)
	{
		digit++;
		n /= 10;
	}
	str = ft_strnew(digit + (isnegative == -1));
	str[digit + 1 + (isnegative == -1)] = '\0';
	if (isnegative == -1)
		str[0] = '-';
	while (digit >= 0)
	{
		str[digit + (isnegative == -1)] = (numb % 10) + '0';
		digit--;
		numb /= 10;
	}
	return (str);
}
