/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:12:13 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/14 12:37:00 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_color				*ft_colornew(double r, double g, double b)
{
	t_color			*new;

	if ((new = (t_color*)malloc(sizeof(t_color))) == NULL)
		return (NULL);
	new->r = r;
	new->g = g;
	new->b = b;
	return (new);
}

int					ft_colorstoi(t_color *scolor)
{
	int				icolor;

	icolor = 0;
	((u_char*)&icolor)[0] = scolor->r;
	((u_char*)&icolor)[1] = scolor->g;
	((u_char*)&icolor)[2] = scolor->b;
	return (icolor);
}

int					ft_getcolor(t_color *ocolor, t_color *lcolor, double cosa)
{
	double			r;
	double			g;
	double			b;
	int				color;

	color = 0;
	r = ((ocolor->r / 255.0) * (lcolor->r / 255.0) * cosa) * 255;
	g = ((ocolor->g / 255.0) * (lcolor->g / 255.0) * cosa) * 255;
	b = ((ocolor->b / 255.0) * (lcolor->b / 255.0) * cosa) * 255;
	((u_char*)&color)[0] = r;
	((u_char*)&color)[1] = g;
	((u_char*)&color)[2] = b;
	return (color);
}
