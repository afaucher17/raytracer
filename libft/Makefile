# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaucher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 14:23:30 by afaucher          #+#    #+#              #
#    Updated: 2014/02/09 18:34:14 by afaucher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = /usr/bin/gcc

SOURCES = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
		ft_strcmp.c ft_strncmp.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c \
		ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memccpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
		ft_memalloc.c ft_memdel.c	ft_strnew.c ft_strdel.c \
		ft_strclr.c ft_striter.c ft_striteri.c ft_strmapi.c \
		ft_strmap.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_itoa.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
		ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_putendl_fd.c ft_putendl.c ft_strtrim.c ft_strsplit.c \
		ft_strjoin.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstaddlast.c ft_lstiter.c ft_lstmap.c \
		ft_lstlast.c ft_lstgetprev.c ft_lstswap.c ft_lstsort.c \
		ft_lstinv.c ft_match.c ft_nmatch.c ft_memdup.c ft_puttab.c \
		ft_puttab_fd.c ft_strintab.c ft_swap.c ft_sort_wordtab.c \
		ft_align_right.c ft_align_left.c ft_nbdigit.c ft_tostr.c \
		ft_getfilename.c ft_lstlen.c ft_get_next_line.c ft_lstpushback.c \
		ft_dlstnew.c ft_dlstpushfront.c ft_dlist_clear.c ft_list_clear.c \
		ft_clear_tab.c \
		maths/maths.c maths/maths2.c \


OBJS = $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[32m[Creating] " $(NAME) | tr -d '\n'
	@ar -rc $(NAME) $^ $(SOURCES:.c=.o)
	@echo "\033[0m"

%.o: %.c
	@echo "Building "$@
	@$(CC) -o $@ -c $^ $(FLAGS)

clean:
	@echo "\033[31m[Clean] " | tr -d '\n'
	@rm -rf $(SOURCES:.c=.o)
	@echo "\033[0m" | tr -d '\n'

fclean: clean
	@echo "\033[31m[Clear] "
	@rm -rf $(NAME)
	@echo "\033[0m" | tr -d '\n'

re: fclean all

.PHONY: clean fclean re all
