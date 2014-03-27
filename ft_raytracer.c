/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 19:41:11 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/27 13:29:42 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"raytracer.h"

int					ft_getintervalue(t_obj *list, t_line *line,
										t_obj **minobj, double min)
{
	int				i;
	double			value;
	t_vect			*dir;
	t_point			*origin;

	origin = line->origin;
	dir = line->dir;
	i = -1;
	value = 0;
	while (++i < OBJ_SIZE)
		if (list->type == g_objtab[i].type)
			value = g_objtab[i].f_inter(list->obj, origin, dir);
	if (value > 0 && (value < min || min == -1) && (*minobj = list))
		min = value;
	return (min);
}

int					ft_getinter(t_point *origin, t_vect *dir,
								int depth, t_obj *obj)
{
	double			min;
	t_obj			*list;
	t_line			line;
	t_obj			*minobj;

	list = g_scene->objs;
	line.dir = dir;
	line.origin = origin;
	min = -1;
	minobj = NULL;
	while (list)
	{
		if (obj != list)
			min = ft_getintervalue(list, &line, &minobj, min);
		list = list->next;
	}
	if (min != -1)
	{
		line.origin = ft_getdistpoint(origin, dir, min);
		return (ft_getlight(minobj, &line, depth));
	}
	return (0x000000);
}

static void			ft_stackcolor(t_vect *dirv, double rgb[3])
{
	int				tmp;

	tmp = ft_getinter(g_scene->camera->origin, dirv, 5, NULL);
	rgb[0] += ((u_char*)&tmp)[0] / ANTIALIASING;
	rgb[1] += ((u_char*)&tmp)[1] / ANTIALIASING;
	rgb[2] += ((u_char*)&tmp)[2] / ANTIALIASING;
}

static int			ft_antialiasing(int x, int y, t_vect *dirv)
{
	int				idx[2];
	static double	sqrta = 0;
	int				color;
	double			rgb[3];

	idx[0] = -1;
	rgb[0] = 0.0;
	rgb[1] = 0.0;
	rgb[2] = 0.0;
	if (sqrta == 0)
		sqrta = sqrt(ANTIALIASING);
	while (++idx[0] < sqrta)
	{
		idx[1] = -1;
		while (++idx[1] < sqrta)
		{
			dirv = ft_getdirvector(g_scene->vpupleft, g_scene->camera,
					x - idx[0] / sqrta, y - idx[1] / sqrta);
			ft_stackcolor(dirv, rgb);
		}
	}
	((u_char*)&color)[0] = rgb[0];
	((u_char*)&color)[1] = rgb[1];
	((u_char*)&color)[2] = rgb[2];
	return (color);
}

void				*ft_raytracer(void *ptr_env)
{
	int				x;
	int				y;
	int				color;
	t_vect			*dirv;
	t_env			*env;

	env = (t_env*)ptr_env;
	y = 0;
	dirv = NULL;
	while (y < SIZE_Y)
	{
		x = env->xstart;
		while (x < SIZE_X)
		{
			color = ft_antialiasing(x, y, dirv);
			pixel_to_img(env->img, x, y, color);
			free(dirv);
			x += NB_THREAD;
		}
		y++;
	}
	printf("thread end\n");
	return (NULL);
}
