/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ellipsoid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frale-co <frale-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 18:43:59 by frale-co          #+#    #+#             */
/*   Updated: 2014/03/21 19:13:36 by frale-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "raytracer.h"

t_ellipse		*ft_ellispenew(t_point *center, t_vect *axis,
							   t_vect *ray, double radius)
{
	t_ellipse	*new;

	if ((new = (t_ellispe*)malloc(sizeof(t_ellipse))) == NULL)
		return (NULL);
	new->center = center;
	ray->x = ray->x * ray->x;
	ray->y = ray->y * ray->y;
	ray->z = ray->z * ray->z;
	new->ray = ray;
	new->axis = axis;
	new->radius = radius;
	ft_get_rotate_matrix(axis->x, axis->y, axis->z, new->rot);
	return (new);
}

void			ft_clearsphere(void **ptr_ellispse)
{
	t_ellispe	*ellipse;

	ellipse = (t_ellipse*)*ptr_ellipse;
	free(ellipse->center);
	free(ellipse->axis);
	free(ellipse->ray);
	free(ellipse);
	*ptr_ellipse = NULL;
}

double			ft_interellipse(void *ptr_ellipse, t_point *origin, t_vect *dir)
{
	double		a;
	double		b;
	double		c;
	double		det;
	t_ellipse	*ell;

	ell = (t_ellipse*)ptr_ellipse;
	dir = ft_rotate_vect(dir, ell->rot);
	origin = ft_rotate_point(origin, ell->center, ell->rot);
	a = ell->ray->y * ell->ray->z * pow(dir->x, 2)
		+ ell->ray->x * ell->ray->z * pow(dir->y, 2)
		+ ell->ray->x * ell->ray->y * pow(dir->z, 2);
	b = 2 * (dir->x * ell->ray->y * ell->ray->z * (origin->x - ell->center->x)
		+ dir->y * ell->ray->x * ell->ray->z * (origin->y - ell->center->y)
		+ dir->z * ell->ray->x * ell->ray->y * (origin->z - ell->center->z));
	c = (pow(origin->x - ell->center->x, 2) * ell->ray->y * ell->ray->z
		+ pow(origin->y - ell->center->y, 2) * ell->ray->x * ell->ray->z
		+ pow(origin->z - ell->center->z, 2) * ell->ray->x * ell->ray->y)
		- pow(ell->radius, 2) * ell->ray->x * ell->ray->y * ell->ray->z;
	det = pow(b, 2) - 4 * a * c;
	if (det < 0)
		return (-1);
	return (ft_getmin(((-b + sqrt(det)) / (2 * a)),
			((-b - sqrt(det)) / (2 * a))));
}

t_vect			*ft_normeellipse(void *ptr_ellipse,
								 t_point *origin, t_vect *dir)
{
	t_vect		*vect;
	t_ellipse	*ellipse;
	t_vect		*rot;

	ellipse = (t_ellipse*)ptr_ellipse;
	origin = ft_rotate_point(origin, cone->center, cone->rot);
	if ((vect = ft_vectornew(origin->x - ellipse->center->x,
		origin->y - ellipse->center->y,
		origin->z - ellipse->center->z)) == NULL)
		return (NULL);
	rot = ft_rotate_vect(dir, cone->rot);
	dir->x = rot->x;
	dir->y = rot->y;
	dir->z = rot->z;
	return (vect);
}
