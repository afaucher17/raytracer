/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:18:31 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/16 14:25:36 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_sphere		*ft_spherenew(double x, double y, double z, double radius)
{
	t_sphere	*new;

	if ((new = (t_sphere*)malloc(sizeof(t_sphere))) == NULL)
		return (NULL);
	new->center = ft_pointnew(x, y, z);
	new->radius = radius;
	return (new);
}

void			ft_clearsphere(void **ptr_sphere)
{
	t_sphere	*sphere;

	sphere = (t_sphere*)*ptr_sphere;
	free(sphere->center);
	free(sphere);
	*ptr_sphere = NULL;
}

double	ft_getmin(double t1, double t2)
{
	if (t1 < 0 && t2 < 0)
		return (-2);
	if (t1 < 0)
		return (t2);
	if (t2 < 0)
		return (t1);
	return (fmin(t1, t2));
}

double			ft_intersphere(void *ptr_sphere, t_point *origin, t_vect *dir)
{
	double		a;
	double		b;
	double		c;
	double		det;
	t_sphere	*sphere;

	sphere = (t_sphere*)ptr_sphere;
	a = pow(dir->x, 2) + pow(dir->y, 2) + pow(dir->z, 2);
	b = 2 * (dir->x * (origin->x - sphere->center->x)
		+ dir->y * (origin->y - sphere->center->y)
		+ dir->z * (origin->z - sphere->center->z));
	c = (pow(origin->x - sphere->center->x, 2)
		+ pow(origin->y - sphere->center->y, 2)
		+ pow(origin->z - sphere->center->z, 2)) - pow(sphere->radius, 2);
	det = pow(b, 2) - 4 * a * c;
	if (det < 0)
		return (-1);
	return (ft_getmin(((-b + sqrt(det)) / (2 * a)),
			((-b - sqrt(det)) / (2 * a))));
}

t_vect			*ft_normesphere(void *ptr_sphere, t_point *origin, t_vect *dir)
{
	t_vect		*vect;
	t_sphere	*sphere;

	(void)dir;
	sphere = (t_sphere*)ptr_sphere;
	if ((vect = ft_vectornew(origin->x - sphere->center->x,
		origin->y - sphere->center->y,
		origin->z - sphere->center->z)) == NULL)
		return (NULL);
	return (vect);
}
