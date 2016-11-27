/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 15:33:32 by afaucher          #+#    #+#             */
/*   Updated: 2014/01/19 17:01:51 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

double		ft_abs(double nb)
{
	float	abs;

	abs = (nb > 0) ? nb : -nb;
	return (abs);
}

double		ft_getrad(double rad)
{
	if (rad < 0)
		return (ft_getrad(rad + 2 * PI));
	if (rad > 2 * PI)
		return (ft_getrad(rad - 2 * PI));
	return (rad);
}
