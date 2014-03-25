/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 10:16:51 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/25 14:45:06 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"
#include <stdio.h>

t_cylinder		*ft_cylindernew(t_point *center, t_vect *axis, double radius)
{
	t_cylinder	*new;

	if ((new = (t_cylinder*)malloc(sizeof(t_cylinder))) == NULL)
		return (NULL);
	new->center = center;
	new->axis = axis;
	new->radius = radius;
	ft_get_rotate_matrix(axis->x, axis->y, axis->z, new->rot);
	ft_get_translate_matrix(center, new->rot);
	return (new);
}

void			ft_clearcylinder(void **ptr_cylinder)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder*)*ptr_cylinder;
	free(cylinder->center);
	free(cylinder->axis);
	free(cylinder);
	*ptr_cylinder = NULL;
}

double			ft_intercylinder(void *ptr_cylinder,
								t_point *origin, t_vect *dir)
{
	double		a;
	double		b;
	double		c;
	double		det;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder*)ptr_cylinder;
	dir = ft_rotate_vect(dir, cylinder->rot);
	origin = ft_rotate_point(origin, cylinder->center, cylinder->rot);
	a = dir->x * dir->x + dir->z * dir->z;
	b = 2 * ((dir->x * (origin->x - cylinder->center->x))
		+ (dir->z * (origin->z - cylinder->center->z)));
	c = (origin->x - cylinder->center->x) * (origin->x - cylinder->center->x)
		+ (origin->z - cylinder->center->z) * (origin->z - cylinder->center->z)
		- (cylinder->radius) * (cylinder->radius);
	det = b * b - 4 * a * c;
	if (det < 0)
		return (-1);
	return (ft_getmin((-b + sqrt(det)) / (2 * a),
				(-b - sqrt(det)) / (2 * a)));
}

t_vect			*ft_normecylinder(void *ptr_cylinder, t_point *origin,
								t_vect *dir)
{
	t_vect		*vect;
	t_cylinder	*cylinder;
	t_vect		*rot;

	cylinder = (t_cylinder*)ptr_cylinder;
	dir->x = dir->x;
	origin = ft_rotate_point(origin, cylinder->center, cylinder->rot);
	if ((vect = ft_vectornew(origin->x - cylinder->center->x, 0,
							origin->z - cylinder->center->z)) == NULL)
		return (NULL);
	rot = ft_rotate_vect(dir, cylinder->rot);
	dir->x = rot->x;
	dir->y = rot->y;
	dir->z = rot->z;
	return (vect);
}
