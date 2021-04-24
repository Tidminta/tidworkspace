/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2021/04/24 17:32:53 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void		free_split(char **str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str[index]);
	free(str);
}

int			free_data(t_msh *msh)
{
	if (msh->data)
	{
		if (msh->data->prompt_data)
			free_split(msh->data->prompt_data);
		free(msh->data);
		return (1);
	}
	return (0);
}

int			free_lair_list(t_msh *msh)
{
	if (msh->lair_list)
	{
		msh->lair_list = clear_list(msh->lair_list);
		free(msh->lair_list);
		return (1);
	}
	return (0);
}

int			free_env_lair(t_msh *msh)
{
	if (msh->env_lair)
	{
		msh->env_lair = clear_env(msh->env_lair);
		free(msh->env_lair);
		return (1);
	}
	return (0);
}
