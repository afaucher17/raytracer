/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:12:13 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/26 15:12:46 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

t_color			*ft_colornew(double r, double g, double b)
{
	t_color		*new;

	if ((new = (t_color*)malloc(sizeof(t_color))) == NULL)
		return (NULL);
	new->r = r;
	new->g = g;
	new->b = b;
	return (new);
}

int				ft_colorstoi(t_color *scolor)
{
	int			icolor;

	ft_normcolor(scolor);
	icolor = 0;
	((u_char*)&icolor)[0] = scolor->r;
	((u_char*)&icolor)[1] = scolor->g;
	((u_char*)&icolor)[2] = scolor->b;
	return (icolor);
}

void			ft_addcolor(t_color *color, int colori)
{
	color->r += (((u_char*)&colori)[0]);
	color->g += (((u_char*)&colori)[1]);
	color->b += (((u_char*)&colori)[2]);
}

void			ft_normcolor(t_color *color)
{
	color->r = (color->r > 255) ? 255 : color->r;
	color->g = (color->g > 255) ? 255 : color->g;
	color->b = (color->b > 255) ? 255 : color->b;
	color->r = (color->r < 0) ? 0 : color->r;
	color->g = (color->g < 0) ? 0 : color->g;
	color->b = (color->b < 0) ? 0 : color->b;
}

int				ft_getcolor(t_obj *obj, t_color *lcolor,
							double cosa, double dot)
{
	double		r;
	double		g;
	double		b;
	int			color;
	t_color		*ocolor;

	ocolor = obj->color;
	color = 0;
	dot = (dot > 0) ? pow(dot, 20) * obj->spec * cosa : 0;
	r = (((ocolor->r / 255.0) * (lcolor->r / 255.0) * cosa)
			+ dot * (lcolor->r / 255.0)) * 255;
	g = (((ocolor->g / 255.0) * (lcolor->g / 255.0) * cosa)
			+ dot * (lcolor->g / 255.0)) * 255;
	b = (((ocolor->b / 255.0) * (lcolor->b / 255.0) * cosa)
			+ dot * (lcolor->b / 255.0)) * 255;
	r = (r > 255) ? 255 : r;
	g = (g > 255) ? 255 : g;
	b = (b > 255) ? 255 : b;
	((u_char*)&color)[0] = r;
	((u_char*)&color)[1] = g;
	((u_char*)&color)[2] = b;
	return (color);
}
