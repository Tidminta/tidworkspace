/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:26:48 by loamar            #+#    #+#             */
/*   Updated: 2021/01/18 19:20:57 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	ft_fill_empty_env(t_env_lair *env_lair, char *content)
{
	t_env_list	*new_block;

	if (!(new_block = (t_env_list *)malloc(sizeof(t_env_list))))
		return (-1);
	new_block->content = content;
	new_block->previous = env_lair->start;
	new_block->next = env_lair->end;
	env_lair->end = new_block;
	env_lair->start = new_block;
	env_lair->size++;
	return (0);
}

int 	ft_fill_end_env(t_env_lair *env_lair, char *content)
{
	t_env_list	*new_block;

	if (!(new_block = (t_env_list *)malloc(sizeof(t_env_list))))
		return (-1);
	new_block->content = content;
	new_block->next = NULL;
	new_block->previous = env_lair->end;
	env_lair->end->next = new_block;
	env_lair->end = new_block;
	env_lair->size++;
	return (0);
}

static	int 	is_empty_env(t_env_lair *env_lair)
{
	if (env_lair == NULL)
		return (1);
	return (-1);
}

t_env_lair		*clear_env(t_env_lair *env_lair)
{
	while (!is_empty_env(env_lair))
		env_lair = pop_back_env(env_lair);
	return (NULL);
}

t_env_lair 		*pop_back_env(t_env_lair *env_lair)
{
	t_env_list 		*temp;

	if (is_empty_env(env_lair))
		return (NULL);
	if (env_lair->start == env_lair->end)
	{
		free (env_lair);
		env_lair = NULL;
		return (NULL);
	}
	temp = env_lair->end;
	env_lair->end->next = NULL;
	temp->next = NULL;
	temp->previous = NULL;
	free(temp);
	temp = NULL;
	env_lair->size--;
	return (env_lair);
}
