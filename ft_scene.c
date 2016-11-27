/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/11 18:20:37 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/26 15:55:02 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_scene				*g_scene;

t_camera			*ft_cameranew(t_point *origin, t_vect *dir,
							t_vect *up)
{
	t_camera		*new;

	if ((new = (t_camera*)malloc(sizeof(t_camera))) == NULL)
		return (NULL);
	new->origin = origin;
	new->dir = dir;
	new->up = up;
	new->right = ft_crossproduct(up, dir);
	return (new);
}

void				ft_clearcamera(t_camera **camera)
{
	free((*camera)->origin);
	free((*camera)->dir);
	free((*camera)->up);
	free((*camera)->right);
	free(*camera);
	*camera = NULL;
}

t_scene				*ft_scenenew(int fd)
{
	t_scene			*new;

	if ((new = (t_scene*)malloc(sizeof(t_scene))) == NULL)
		return (NULL);
	new->objs = NULL;
	new->lights = NULL;
	new->camera = ft_cameranew(ft_pointnew(320, 200, -800),
					ft_vectornew(0, 0, 1), ft_vectornew(0, 1, 0));
	ft_parser(fd, &new->lights, &new->objs, &new->camera);
	new->vpupleft = ft_getvpupleft(new->camera);
	return (new);
}
