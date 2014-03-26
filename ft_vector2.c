/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:54:08 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/26 11:22:39 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_vect				*ft_project(t_vect *dir, t_vect *axis)
{
	t_vect			*new;
	double			cos1;
	double			cos2;
	double			scalar;

	if ((new = ft_vectornew(0, 0, 0)) == NULL)
		return (NULL);
	cos1 = ft_getangle(dir, axis);
	cos2 = ft_getangle(dir, dir);
	scalar = cos1 / cos2;
	new->x = axis->x * scalar;
	new->y = axis->y * scalar;
	new->z = axis->z * scalar;
	ft_normalize(new);
	return (new);
}

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
