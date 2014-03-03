/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 13:23:28 by afaucher          #+#    #+#             */
/*   Updated: 2014/01/07 15:20:46 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "../libft.h"

double		ft_pow(double nb, int p)
{
	if (p == 0)
		return (1);
	return (nb * ft_pow(nb, p - 1));
}

long	ft_fact(long nb)
{
	if (nb == 0)
		return (1);
	if (nb < 20 && nb > 0)
		return (nb * ft_fact(nb - 1));
	return (0);
}

double		ft_cos(double rad)
{
	double	acc;
	int		con;
	int		nb;
	double	cos;

	nb = 0;
	con = -1;
	cos = 1;
	acc = 0.001;
	if (rad > PI / 2)
		return (-ft_cos(rad - PI));
	if (rad > PI / 4)
		return (ft_sin((PI / 2) - rad));
	while (ft_abs(ft_pow(rad, 1 + nb) / ft_fact(1 + nb)) >= acc)
	{
		cos += con * (ft_pow(rad, 2 + nb) / ft_fact(2 + nb));
		con *= -1;
		nb += 2;
	}
	return (cos);
}

double		ft_sin(double rad)
{
	double	acc;
	int		con;
	int		nb;
	double	sin;

	nb = 1;
	con = -1;
	acc = 0.001;
	sin = rad;
	if (rad > PI / 2)
		return (-ft_sin(rad - PI));
	if (rad > PI / 4)
		return (ft_cos((PI / 2) - rad));
	while (ft_abs(ft_pow(rad, 1 + nb) / ft_fact(1 + nb)) >= acc)
	{
		sin += con * (ft_pow(rad, 2 + nb) / ft_fact(2 + nb));
		con *= -1;
		nb += 2;
	}
	return (sin);
}

double		ft_tan(double rad)
{
	return (ft_sin(rad) / ft_cos(rad));
}
