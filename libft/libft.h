/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:37:27 by afaucher          #+#    #+#             */
/*   Updated: 2014/02/16 13:16:10 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "maths/maths.h"
# define BUFF_SIZE 4096

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int		ft_strequ(const char *s1, const char *s2);
int		ft_strnequ(char const *s1, const char *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
t_list	*ft_strsplit(char const *s, char *str);
char	*ft_itoa(int n);
int		ft_atoi(const char *str);
void	ft_putstr(const char *s);
int		ft_putstr_fd(const char *s, int fd);
void	ft_putendl(const char *s);
int		ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
t_list	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstpushback(t_list **alst, void *content, size_t size);
void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void	ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void	ft_lstadd(t_list **alst, t_list *lnew);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstaddlast(t_list **alst, t_list *lnew);
void	ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstgetprev(t_list **begin_list, t_list *elem);
void	ft_lstswap(t_list *elem1, t_list *elem2);
void	ft_lstsort(t_list *lst, int (*cmp)());
void	ft_lstinv(t_list **begin_list);
int		ft_match(char *s1, char *s2);
int		ft_nmatch(char *s1, char *s2);
void	*ft_memdup(void *s, size_t n);
void	ft_puttab(char *s);
void	ft_puttab_fd(char *s, int fd);
int		ft_strintab(char *str, char **tab, int size);
void	ft_swap(char **str1_tr, char **str1_ptr);
void	ft_memswap(void **ptr1, void **ptr2);
void	ft_sort_wordtab(char **tab);
char	*ft_align_right(const char *str, size_t size);
char	*ft_align_left(const char *str, size_t size);
size_t	ft_nbdigit(int nb);
char	*ft_tostr(char c);
char	*ft_getfilename(char *path);
int		ft_lstlen(t_list *list);
int		ft_get_next_line(int fd, char **line);
t_dlist	*ft_dlstnew(void *content, size_t content_size);
void	ft_dlstpushfront(t_dlist **lst, void *content, size_t content_size);
int		ft_dlist_clear(t_dlist **list);
int		ft_list_clear(t_list **list);
int		ft_clear_tab(char **tab);
#endif /* !__LIBFT_H__ */
