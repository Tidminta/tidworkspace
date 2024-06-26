/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:01:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/26 16:30:04 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void		*ft_memset(void *b, int c, size_t len);

size_t		ft_strlen(const char *s);

int			ft_atoi(const char *str);

void		ft_bzero(void *s, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

void		*ft_memccpy(void *dst, const void *src, int c, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

int			ft_isalpha(int c);

int			ft_isdigit(int c);

int			ft_isalnum(int c);

int			ft_isascii(int c);

int			ft_isprint(int c);

int			ft_toupper(int c);

int			ft_tolower(int c);

char		*ft_strchr(const char *s, int c);

char		*ft_strrchr(const char *s, int c);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

void		*ft_memchr(const void *s, int c, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_memmove(void *dst, const void *src, size_t len);

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

void		*ft_calloc(size_t count, size_t size);

char		*ft_strdup(const char *s1);

char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin(char const *s1, char const *s2);

void		ft_putchar_fd(char c, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

char		*ft_strtrim(char const *s1, char const *set);

char		*ft_itoa(int n);

char		**ft_split(char const *s, char c);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int			get_next_line(int fd, char **line);

char		*ft_where_is_nl(char *s);

void		ft_check_params(int fd, char **line, char **buff, char **str);

int			ft_check(int fd, char **line, char **str, void *buff);

char		*ft_strdup2(char *s1);

char		*ft_strjoin2(char *s1, char *s2);

/*
*************************************
**			  LISTES               **
**	 A REMETTRE MAKEFILE LIBFT	   **
*************************************
*/

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void *content);

void			ft_lstadd_back(t_list **alst, t_list *n);

void			ft_lstadd_front(t_list **alst, t_list *n);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));

#endif
