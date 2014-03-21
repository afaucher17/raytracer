/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:41:11 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/21 14:02:20 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_point			*ft_getdistpoint(t_point *origin, t_vect *dir, double dist)
{
	t_point		*new;

	if ((new = ft_pointnew(0, 0, 0)) == NULL)
		return (NULL);
	new->x = origin->x + dir->x * dist;
	new->y = origin->y + dir->y * dist;
	new->z = origin->z + dir->z * dist;
	return (new);
}

int				ft_getinter(t_scene *scene, t_vect *dir)
{
	double		min;
	double		value;
	t_obj		*minobj;
	t_obj		*list;
	int			i;

	list = scene->objs;
	min = -1;
	minobj = NULL;
	while (list)
	{
		value = 0;
		i = -1;
		while (++i < OBJ_SIZE)
			if (list->type == g_objtab[i].type)
				value = g_objtab[i].f_inter(list->obj, scene->camera->origin, dir);
		if (value > 0 && (value < min || min == -1) && (minobj = list))
			min = value;
		list = list->next;
	}
	if (min != -1)
		return (ft_getlight(minobj, scene,
							ft_getdistpoint(scene->camera->origin, dir, min), dir));
	return (0x000000);
}

void			*ft_raytracer(void *ptr_env)
{
	int			x;
	int			y;
	int			color;
	t_vect		*dirv;
	t_env		*env;

	env = (t_env*)ptr_env;
	y = env->ystart;
	while (y < env->yend)
	{
		x = env->xstart;
		while (x < env->xend)
		{
			dirv = ft_getdirvector(env->scene->vpupleft, env->scene->camera, x, y);
			color = ft_getinter(env->scene, dirv);
			pixel_to_img(env->img, x, y, color);
			free(dirv);
			x++;
		}
		y++;
	}
	printf("finished %d %d %d %d\n", env->xstart, env->xend, env->ystart, env->yend);
	return (NULL);
}
