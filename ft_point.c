/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 12:21:23 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/24 15:50:05 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

/*
** This function creates a new point
*/
t_point				*ft_pointnew(double x, double y, double z)
{
	t_point			*point;

	point = (t_point*)malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

/*
** This function places a pixel into an image.
*/
int					pixel_to_img(t_mlx_img *img, int x, int y, int color)
{
	long			index;
	int				i;
	long			max;

	i = 0;
	index = x * (img->bpp / 8) + y * (img->size);
	max = img->width * (img->bpp / 8) + img->height * (img->size);
	while ((i < img->bpp / 8) && index < max && index > 0)
	{
		img->data[index + i] = ((char*)&color)[i];
		i++;
	}
	return (0);
}

/*
** Gets the pixel color of an image at a position
*/
size_t				get_pixel_at(t_mlx_img *img, int x, int y)
{
	long			index;
	int				i;
	long			max;
	int				color;

	i = 0;
	index = x * (img->bpp / 8) + y * (img->size);
	max = img->width * (img->bpp / 8) + img->height * (img->size);
	color = 0;
	while ((i < img->bpp / 8) && index < max && index > 0)
	{
		((char*)&color)[i] = img->data[index + i];
		i++;
	}
	return (color);
}

/*
** Calculates the distance between two points.
*/
double				point_distance(t_point *p1, t_point *p2, double rad)
{
	double			dist;

	if ((rad > PI / 4 && rad < 3 * PI / 4)
		|| (rad > 5 * PI / 4 && rad < 7 * PI / 4))
		dist = ft_abs(ft_abs(p1->y - p2->y) / sin(rad));
	else
		dist = ft_abs(ft_abs(p1->x - p2->x) / cos(rad));
	free(p2);
	return (dist);
}

t_point			*ft_getvpupleft(t_camera *camera)
{
	t_point		*new;

	if ((new = ft_pointnew(0, 0, 0)) == NULL)
		return (NULL);
	new->x = camera->origin->x + ((camera->dir->x * VP_DIST)
			+ (camera->up->x * (VP_HEIGHT / 2.0)))
			- (camera->right->x * (VP_WIDTH / 2.0));
	new->y = camera->origin->y + ((camera->dir->y * VP_DIST)
			+ (camera->up->y * (VP_HEIGHT / 2.0)))
			- (camera->right->y * (VP_WIDTH / 2.0));
	new->z = camera->origin->z + ((camera->dir->z * VP_DIST)
			+ (camera->up->z * (VP_HEIGHT / 2.0)))
			- (camera->right->z * (VP_WIDTH / 2.0));
	return (new);
}
