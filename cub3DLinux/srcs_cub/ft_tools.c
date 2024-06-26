/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:57:50 by tidminta          #+#    #+#             */
/*   Updated: 2020/06/26 18:22:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_mapinfos(t_mapinfos *map)
{
	printf("************ MAP INFOS ************\n");
	printf("[res x][%zu]", map->resolution->res_x);
	printf("[res y][%zu]\n", map->resolution->res_y);
	printf("[NO][%s]\n", map->no);
	printf("[SO][%s]\n", map->so);
	printf("[WE][%s]\n", map->we);
	printf("[EA][%s]\n", map->ea);
	printf("[S][%s]\n", map->sprite);
	printf("[F][R][%zu][G][%zu][B][%zu]\n",
		map->floor->red, map->floor->green, map->floor->bleue);
	printf("[C][R][%zu][G][%zu][B][%zu]\n",
		map->ceil->red, map->ceil->green, map->ceil->bleue);
	ft_print_list(map->map);
	printf("************* END *************\n");
}

void		ft_print_list(t_list *map)
{
	printf("************ LIST ************\n");
	while (map->next)
	{
		printf("[%s]\n", (char*)map->content);
		map = map->next;
	}
	if (map->content)
		printf("[%s]\n", (char*)map->content);
	printf("************* END *************\n");
}

void		ft_print_tab(char **tab)
{
	size_t	i;
	
	i = 0;
	while (tab[i])
	{
		printf("[%zu][%s]\n", i, tab[i]);
		i++;
	}
}
