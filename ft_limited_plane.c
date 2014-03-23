/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:36:58 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/23 20:45:00 by frale-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_plane			*ft_planenew(t_vect *vect, t_point *point)
{
	t_plane		*new;
	t_point		*pt1;
	t_point		*pt2;
	t_point		*pt3;
	t_vect		*v1;
	t_vect		*v2;
	t_vect		*norm;

	(void)vect;
	(void)point;
	pt1 = ft_pointnew(200, 150, 100);
	pt2 = ft_pointnew(180, 120, 100);
	pt3 = ft_pointnew(220, 120, 100);
	v1 = ft_vectornew(pt1->x - pt2->x, pt1->y - pt2->y, pt1->z - pt2->z);
	v2 = ft_vectornew(pt3->x - pt2->x, pt3->y - pt2->y, pt3->z - pt2->z);
	norm = ft_crossproduct(v1, v2);
	if ((new = (t_plane*)malloc(sizeof(t_plane))) == NULL)
		return (NULL);
	new->vect = norm;
	new->point = pt2;
	new->d = -(norm->x * pt2->x + norm->y * pt2->y
			   + norm->z * pt2->z);
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
	t_point		*pt1;
	t_point		*pt2;
	t_point		*pt3;
	t_point		*inter;
	t_vect		*v1;
	t_vect		*v2;
	t_vect		*v_inter;
	double		cosa;
	double		cosb;

	pt1 = ft_pointnew(200, 150, 100);
	pt2 = ft_pointnew(180, 120, 100);
	pt3 = ft_pointnew(220, 120, 100);
	v1 = ft_vectornew(pt1->x - pt2->x, pt1->y - pt2->y, pt1->z - pt2->z);
	v2 = ft_vectornew(pt3->x - pt2->x, pt3->y - pt2->y, pt3->z - pt2->z);
	plane = (t_plane*)ptr_plane;
	r1 = plane->vect->x * origin->x
		+ plane->vect->y * origin->y
		+ plane->vect->z * origin->z
		+ plane->d;
	r2 = plane->vect->x * dir->x + plane->vect->y * dir->y
		+ plane->vect->z * dir->z;
	if (-(r1 / r2) >= 0)
	{
		cosa = ft_getangle(v1, v2);
		inter = ft_getdistpoint(origin, dir, -(r1 / r2));
		v_inter = ft_vectornew(inter->x - pt2->x, inter->y - pt2->y, inter->z - pt2->z);
		cosb = ft_getangle(v1, v_inter);
		if (acos(cosb) < acos(cosa)
			&& ft_getangle(ft_crossproduct(v1, v2), ft_crossproduct(v1, v_inter)) != -1)
		{
			v1 = ft_vectornew(pt2->x - pt1->x, pt2->y - pt1->y, pt2->z - pt1->z);
			v2 = ft_vectornew(pt3->x - pt1->x, pt3->y - pt1->y, pt3->z - pt1->z);
			cosa = ft_getangle(v1, v2);
			v_inter = ft_vectornew(inter->x - pt1->x, inter->y - pt1->y, inter->z - pt1->z);
			cosb = ft_getangle(v1, v_inter);
			if (acos(cosb) < acos(cosa))
				return (-(r1 / r2));
		}
	}
	return (0);
}

t_vect			*ft_normeplane(void *ptr_plane, t_point *origin, t_vect *dir)
{
	t_plane		*plane;

	plane = (t_plane*)ptr_plane;
	(void)origin;
	(void)dir;
	return (plane->vect);
}
