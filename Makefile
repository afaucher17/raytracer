# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaucher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:23:30 by afaucher          #+#    #+#              #
#    Updated: 2014/03/27 12:23:59 by afaucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = /usr/bin/cc

SOURCES = raytracer.c ft_obj.c ft_point.c ft_raytracer.c ft_scene.c \
		ft_sphere.c ft_vector.c ft_vector2.c image.c main.c ft_plane.c \
		ft_light.c ft_color.c ft_cylinder.c ft_ellipsoid.c \
		ft_getlight.c ft_getdistpoint.c ft_cone.c ft_fresnel.c \
		ft_parser.c ft_parse_fun.c ft_parse_fun2.c ft_matrix.c \

OBJS = $(SOURCES:.c=.o)

LINKS = -lmlx -lXext -lX11

FLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR = libft/

LIBMLX = /usr/X11/lib

LIB = libft/libft.a

NAME = raytracer

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(FLAGS) $(SOURCES:.c=.o) -L$(LIBMLX) $(LIB) $(LINKS)

%.o: %.c
	$(CC) -o $@ -c $^ $(FLAGS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(SOURCES:.c=.o)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: $(LIBFT_DIR) clean fclean re all
