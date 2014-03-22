/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:41:11 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/22 16:16:01 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_point				*ft_getdistpoint(t_point *origin, t_vect *dir, double dist)
{
	t_point			*new;

	if ((new = ft_pointnew(0, 0, 0)) == NULL)
		return (NULL);
	new->x = origin->x + dir->x * dist;
	new->y = origin->y + dir->y * dist;
	new->z = origin->z + dir->z * dist;
	return (new);
}

int					ft_getinter(t_scene *scene, t_vect *dir)
{
	double			min;
	double			value;
	t_obj			*minobj;
	t_obj			*list;
	int				i;

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

static void			ft_addcolor(t_env *env, t_vect *dirv, double rgb[3])
{
	int				tmp;

	tmp = ft_getinter(env->scene, dirv);
	rgb[0] += ((u_char*)&tmp)[0] / ANTIALIASING;
	rgb[1] += ((u_char*)&tmp)[1] / ANTIALIASING;
	rgb[2] += ((u_char*)&tmp)[2] / ANTIALIASING;
}

static int			ft_antialiasing(t_env *env, int x, int y, t_vect *dirv)
{
	int				i;
	int				j;
	static double	sqrta = 0;
	int				color;
	double			rgb[3] = {0, 0, 0};

	i = -1;
	if (sqrta == 0)
		sqrta = sqrt(ANTIALIASING);
	while (++i < sqrta)
	{
		j = -1;
		while (++j < sqrta)
		{
			dirv = ft_getdirvector(env->scene->vpupleft,
					env->scene->camera, x - i / sqrta, y - j / sqrta);
			ft_addcolor(env, dirv, rgb);
		}
	}
	((u_char*)&color)[0] = rgb[0];
	((u_char*)&color)[1] = rgb[1];
	((u_char*)&color)[2] = rgb[2];
	return (color);
}

void			*ft_raytracer(void *ptr_env)
{
	int			x;
	int			y;
	int			color;
	t_vect		*dirv;
	t_env		*env;

	env = (t_env*)ptr_env;
	y = 0;
	dirv = NULL;
	while (y < SIZE_Y)
	{
		x = env->xstart;
		while (x < SIZE_X)
		{
			color = ft_antialiasing(env, x, y, dirv);
			pixel_to_img(env->img, x, y, color);
			free(dirv);
			x += NB_THREAD;
		}
		y++;
	}
	printf("thread end\n");
	return (NULL);
}
