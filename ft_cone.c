/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 11:43:53 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/16 17:29:42 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_cone			*ft_conenew(t_point *center, t_vect *axis,
							double radius, double angle)
{
	t_cone		*new;

	if ((new = (t_cone*)malloc(sizeof(t_cone))) == NULL)
		return (NULL);
	new->center = center;
	new->axis = axis;
	new->radius = radius;
	ft_putnbr(angle);
	new->angle = 1 / (tan(angle) * tan(angle));
	ft_putnbr(angle);
	return (new);
}

void			ft_clearcone(void **ptr_cone)
{
	t_cone		*cone;

	cone = (t_cone*)*ptr_cone;
	free(cone->center);
	free(cone->axis);
	free(cone);
	*ptr_cone = NULL;
}

double			ft_intercone(void *ptr_cone, t_point *origin, t_vect *dir)
{
	double		a;
	double		b;
	double		c;
	double		det;
	t_cone		*cone;

	cone = (t_cone*)ptr_cone;
	a = pow(dir->x, 2) * cone->angle + pow(dir->z, 2) * cone->angle
		- pow(dir->y, 2);
	b = 2 * ((dir->x * (origin->x - cone->center->x) * cone->angle)
		+ (dir->z * (origin->z - cone->center->z) * cone->angle)
		- (dir->y * (origin->y - cone->center->y)));
	c = pow(origin->x - cone->center->x, 2) * cone->angle
		+ pow(origin->z - cone->center->z, 2) * cone->angle
		- pow(origin->y - cone->center->y, 2);
	det = pow(b, 2) - 4 * a * c;
	if (det < 0)
		return (-1);
	return (ft_getmin((-b + sqrt(det)) / (2 * a),
				(-b - sqrt(det)) / (2 * a)));
}

t_vect			*ft_normecone(void *ptr_cone, t_point *origin, t_vect *dir)
{
	t_vect		*vect;
	t_cone		*cone;

	(void)dir;
	cone = (t_cone*)ptr_cone;
	if ((vect = ft_vectornew(origin->x - cone->center->x,
					0, origin->z - cone->center->z)) == NULL)
		return (NULL);
	return (vect);
}
