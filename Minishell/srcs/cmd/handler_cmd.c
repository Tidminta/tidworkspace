/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 22:57:33 by loamar            #+#    #+#             */
/*   Updated: 2021/02/12 00:15:35 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	handler_cmd(t_msh *msh, char **env)
{
	int ret;
	t_list 	*element;

	element = msh->lair_list->start;
	while (element->next != NULL)
	{
		if (element->token == CMD)
		{
			if (ft_handler_built_in(msh, element, env) != SUCCESS)
				exec_cmd(msh, element, env);
			element = element->next;
			while (element->token == OPTION || element->token == ARGS)
				element = element->next;
		}
		else
			element = element->next;
	}
	return (0);
}