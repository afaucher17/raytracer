/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 12:46:05 by afaucher          #+#    #+#             */
/*   Updated: 2014/03/19 13:44:03 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytracer.h"

int				main(int argc, char **argv)
{
	int			fd;

	if (argc < 2)
		ft_putendl_fd("usage: ./raytracer file1", 2);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror(ft_strjoin("raytracer: ", argv[1]));
			return (1);
		}
		raytracer(fd);
	}
	return (0);
}
