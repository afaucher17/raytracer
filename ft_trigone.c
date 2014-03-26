/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 18:36:58 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/26 12:47:11 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_trigone		*ft_trigonenew(t_point *p1, t_point *p2, t_point *p3)
{
	t_trigone	*new;

	if ((new = (t_trigone*)malloc(sizeof(t_trigone))) == NULL)
		return (NULL);
	new->pt1 = p1;
	new->pt2 = p2;
	new->pt3 = p3;
	new->v1_2 = ft_vectornew(p2->x - p1->x, p2->y - p1->y, p2->z - p1->z);
	new->v1_3 = ft_vectornew(p3->x - p1->x, p3->y - p1->y, p3->z - p1->z);
	new->alpha = acos(ft_getangle(new->v1_2, new->v1_3));
	new->v2_1 = ft_vectornew(p1->x - p2->x, p1->y - p2->y, p1->z - p2->z);
	new->v2_3 = ft_vectornew(p3->x - p2->x, p3->y - p2->y, p3->z - p2->z);
	new->beta = acos(ft_getangle(new->v2_1, new->v2_3));
	new->dir = ft_crossproduct(v1_2, v1_3);
	new->d = -(new->dir->x * p1->x + new->dir->y * p1->y
			   + new->dir->z * p1->z);
	return (new);
}

void			ft_cleartrigone(void **ptr_trigone)
{
	t_trigone	*trigone;

	trigone = (t_trigone*)*ptr_trigone;
	free(trigone->pt1);
	free(trigone->pt2);
	free(trigone->pt3);
	free(trigone->v1_2);
	free(trigone->v1_3);
	free(trigone->v2_1);
	free(trigone->v2_3);
	free(trigone->dir);
	free(trigone);
	*ptr_trigone = NULL;
}

int				ft_is_inside(t_trigone *tri, t_point *inter)
{
	t_vect		*v_inter;
	double		angle;
	vect		*v_dir;
	int			ret;

	ret = 0;
	v_inter = ft_vectornew(inter->x - tri->pt1->x,
						   inter->y - tri->pt1->y, inter->z - tri->pt1->z);
	v_dir = ft_crossproduct(v1_2, v_inter);
	angle = acos(ft_getangle(tri->v1_2, v_inter));
	if (angle < tri->alpha && ft_getangle(tri->dir, v_dir != -1))
	{
		free(v_inter);
		v_inter = ft_vectornew(inter->x - tri->pt2->x,
							   inter->y - tri->pt2->y, inter->z - tri->pt2->z);
		angle = acos(ft_getangle(v2_1, v_inter));
		if (angle < tri->beta)
			ret = 1;
	}
	free(v_inter);
	free(inter);
	free(v_dir);
	return (ret);
}

double			ft_intertrigone(void *ptr_trigone, t_point *origin, t_vect *dir)
{
	double		r1;
	double		r2;
	t_trigone	*trigone;
	double		ret;

	trigone = (t_trigone*)ptr_trigone;
	r1 = trigone->dir->x * origin->x
		+ trigone->dir->y * origin->y
		+ trigone->dir->z * origin->z
		+ trigone->d;
	r2 = trigone->dir->x * dir->x + trigone->dir->y * dir->y
		+ trigone->dir->z * dir->z;
	ret = -(r1 / r2)
	if (ret >= 0)
	{
		if (ft_is_inside(trigone, ft_getdistpoint(origin, dir, ret)))
			return (ret);
	}
	return (0);
}

t_vect			*ft_normetrigone(void *ptr_trigone, t_point *origin, t_vect *dir)
{
	t_trigone	*trigone;

	trigone = (t_trigone*)ptr_trigone;
	(void)origin;
	(void)dir;
	return (trigone->dir);
}
