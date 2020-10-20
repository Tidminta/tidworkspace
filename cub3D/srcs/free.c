/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:50:53 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/20 19:01:03 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void			ft_free_split(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/*
**************************************
**		DONT FORGET TO FREE			**
**		zbuff (init.c | l123)		**
**************************************
*/

void			*ft_garbage_collector(t_list **garbage,
				unsigned int size, int fd)
{
	t_list	*new;
	void	*tmp;

	if (!(tmp = (void*)malloc(size)))
		ft_error(garbage, "Error\nIt's may be a malloc error.\n", 0, fd);
	if (!(new = ft_lstnew(tmp)))
		ft_error(garbage, "Error\nIt's may be a malloc error.\n", 0, fd);
	ft_lstadd_front(garbage, new);
	return (tmp);
}

static void		ft_clear(void *content)
{
	if (content)
		free(content);
}

void			ft_freelst(t_list *l)
{
	t_list	*tmp;
	int		lst_size;
	void	(*clear)(void*);
	int		i;

	clear = &ft_clear;
	i = 0;
	lst_size = ft_lstsize(l);
	while (l && i < lst_size)
	{
		tmp = l->next;
		if (l->content)
		{
			ft_lstdelone(l, clear);
			l = tmp;
		}
		i++;
	}
}

int				ft_error(t_list **garbage, char *s, int indice, int fd)
{
	int		list_size;
	void	(*clear)(void*);

	clear = &ft_clear;
	list_size = ft_lstsize(*garbage);
	if (indice == 0)
		ft_freelst(*garbage);
	if (s)
		ft_putstr_fd(s, 1);
	if (fd)
		close(fd);
	system("leaks Cub3D");
	exit(EXIT_SUCCESS);
}
