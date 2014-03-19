/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:54:08 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/19 19:58:44 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

double				ft_get_dot(t_vect *ldir, t_vect *norm, t_vect *dir)
{
	t_vect			refl;
	double			ret;
	double			cosa;

	cosa = ft_getangle(ldir, norm);
	refl.x = ldir->x - 2 * cosa * norm->x;
	refl.y = ldir->y - 2 * cosa * norm->y;
	refl.z = ldir->z - 2 * cosa * norm->z;
	ret = ft_getangle(dir, &refl);
	return (ret);
}
