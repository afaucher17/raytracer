/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:36:58 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/20 15:38:05 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_plane			*ft_planenew(t_vect *vect, t_point *point)
{
	t_plane		*new;

	if ((new = (t_plane*)malloc(sizeof(t_plane))) == NULL)
		return (NULL);
	new->vect = vect;
	new->point = point;
	new->d = -(vect->x * point->x + vect->y * point->y
			+ vect->z * point->z);
	return (new);
}

void			ft_clearplane(void **ptr_plane)
{
	t_plane		*plane;

	plane = (t_plane*)*ptr_plane;
	free(plane->vect);
	free(plane->point);
	*ptr_plane = NULL;
}

double			ft_interplane(void *ptr_plane, t_point *origin, t_vect *dir)
{
	double		r1;
	double		r2;
	t_plane		*plane;

	plane = (t_plane*)ptr_plane;
	r1 = plane->vect->x * origin->x
		+ plane->vect->y * origin->y
		+ plane->vect->z * origin->z
		+ plane->d;
	r2 = plane->vect->x * dir->x + plane->vect->y * dir->y
		+ plane->vect->z * dir->z;
	return (-(r1 / r2));
}

t_vect			*ft_normeplane(void *ptr_plane, t_point *origin, t_vect *dir)
{
	t_plane		*plane;

	plane = (t_plane*)ptr_plane;
	(void)origin;
	(void)dir;
	return (plane->vect);
}
