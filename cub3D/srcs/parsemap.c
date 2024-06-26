/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 13:00:34 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/28 14:10:45 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int			ft_check_rgb(char **tab)
{
	int i;

	i = 0;
	while (i < 3 && tab[i])
	{
		if ((ft_atoi(tab[i]) <= 0 || ft_atoi(tab[i]) > 255))
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int					ft_get_rgb(char *to_find, t_list *lst, int *rgb)
{
	char	**tab;
	char	*str;

	while (lst->next || lst->content)
	{
		str = lst->content;
		if (ft_strncmp((char *)lst->content, to_find, 2) == 0)
		{
			while (ft_isalpha(*str) || *str == ' ')
				str++;
			if ((!(tab = ft_split(str, ','))) || (!(ft_check_rgb(tab))))
			{
				ft_free_split(tab);
				return (-1);
			}
			*rgb = ft_create_trgb(0, ft_atoi(tab[0]),
				ft_atoi(tab[1]), ft_atoi(tab[2]));
			ft_free_split(tab);
		}
		if (!lst->next)
			return (1);
		lst = lst->next;
	}
	return (-1);
}

size_t				ft_is_map_char(char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = " 012NSEW";
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t				ft_is_map_line(char *s)
{
	size_t	i;
	size_t	len;
	int		ret;

	i = 0;
	len = ft_strlen(s);
	ret = 0;
	while (s[i])
	{
		if (!(ft_is_map_char(s[i])))
			return (0);
		i++;
	}
	return (1);
}

char				**ft_lst_to_tab(t_list *lst, t_mapinfos *map, size_t i)
{
	char	**tab;
	char	*tmp;
	size_t	len;

	if (!(len = ft_lstsize(lst)) || !lst || !map)
		return (NULL);
	map->line_max = len;
	if (!(tab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	tab[len] = 0;
	while (lst->next)
	{
		tmp = lst->content;
		if (tmp[0])
		{
			if ((len = ft_strlen(tmp)) > map->col_max)
				map->col_max = len;
			tab[i++] = tmp;
		}
		lst = lst->next;
	}
	if (lst->content)
		tab[i] = lst->content;
	return (tab);
}
