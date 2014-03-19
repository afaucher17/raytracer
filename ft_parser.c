/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 18:20:13 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/16 18:20:16 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"raytracer.h"

static void		ft_fill(t_list *list, t_light **llist)
{
	int			i;
	t_point		*point;
	t_color		*color;

	i = 0;
	point = ft_pointnew(ft_atoi(list->content), ft_atoi(list->next->content),
							ft_atoi(list->next->next->content));
	while (i++ < 3)
		list = list->next;
	color = ft_colornew(ft_atoi(list->content), ft_atoi(list->next->content),
						ft_atoi(list->next->next->content));
	ft_lightpushfront(llist, point, L_OMNI, color);
}

void			ft_parser(int fd, t_light **llist, t_obj **olist)
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
				ft_fill(list->next, llist);
			list = list->next;
		}
		free(line);
	}
}
