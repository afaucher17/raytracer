/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:20:13 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/25 20:45:17 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"raytracer.h"

static void		ft_fillcamera(t_list **list, t_camera **camera)
{
	t_point		*point;
	t_vect		*dir;
	t_vect		*up;

	point = ft_pointnew(ft_get_value(list), ft_get_value(list),
						ft_get_value(list));
	dir = ft_vectornew(ft_get_value(list), ft_get_value(list),
						ft_get_value(list));
	up = ft_vectornew(ft_get_value(list), ft_get_value(list),
						ft_get_value(list));
	*camera = ft_cameranew(point, dir, up);
}

static void		ft_fill(t_list **list, t_light **llist)
{
	t_point		*point;
	t_color		*color;

	point = ft_pointnew(ft_get_value(list), ft_get_value(list),
							ft_get_value(list));
	color = ft_colornew(ft_get_value(list), ft_get_value(list),
						ft_get_value(list));
	ft_lightpushfront(llist, point, L_OMNI, color);
}

void			ft_parser(int fd, t_light **llist,
							t_obj **olist, t_camera **camera)
{
	int			i;
	t_list		*list;
	char		*line;

	line = NULL;
	while (ft_get_next_line(fd, &line) > 0)
	{
		list = ft_strsplit(line, " \t\n,{};()[]./\\");
		while (list)
		{
			i = 0;
			while (i < OBJ_SIZE)
			{
				if (ft_strequ(g_objtab[i].name, list->content))
					g_objtab[i].f_fill(&(list->next), olist);
				i++;
			}
			if (ft_strequ("light", list->content))
				ft_fill(&list->next, llist);
			if (ft_strequ("camera", list->content))
				ft_fillcamera(&list->next, camera);
			list = list->next;
		}
		free(line);
	}
}
