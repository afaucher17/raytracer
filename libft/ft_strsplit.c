/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:30:28 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/16 17:10:22 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include			"libft.h"

t_list				*ft_strsplit(char const *s, char *str)
{
	t_list			*list;
	char			*buff;
	int				i;

	list = NULL;
	buff = ft_strnew(ft_strlen(s));
	i = 0;
	while (s && *s)
		if (ft_strchr(str, *s) != NULL)
		{
			if (i != 0)
				ft_lstpushback(&list, buff, ft_strlen(buff));
			ft_bzero(buff, i);
			i = 0;
			s++;
		}
		else if (ft_strchr(str, *s) == NULL)
		{
			buff[i] = *s;
			i++;
			s++;
		}
	free(buff);
	return (list);
}
