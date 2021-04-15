/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:06:28 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/14 15:32:47 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int				separator_check(t_msh *msh, char *s)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = msh->utils->sep_tab;
	while (tmp[i])
	{
		if (!ft_strncmp(s, tmp[i], ft_strlen(s))
			&& ft_strlen(s) == ft_strlen(tmp[i]))
			return (1); // a preciser return -1 ?
		i++;
	}
	return (0);
}

/*
** token recognition a finir, bon pour cmd separator et args
** d'autres tests sont a prevoirs, relancer l'op qd on est sur un sep
** implementer/finir option_check(s);
** lors des test
*/

static int				option_check(t_msh *msh, char *s)
{
	(void)msh;
	if (!s[0])
		return (0);
	if (s[0] == 45)
		return (OPT);
	else if (s[1] && (s[0] == DQUOTE && s[1] == 45))
		return (OPT);
	else if (s[1] && (s[0] == SQUOTE && s[1] == 45))
		return (OPT);
	else return (0);
}

static int		token_recognition(t_msh *msh, char *s, int indice)
{
	if (indice == 0)
		return (CMD);
	else if (((indice == 1 && option_check(msh, s)) || (indice > 1 && option_check(msh, s)))
			&& (msh->utils->check_arg == 0))
		return (OPT);
	else if (indice != 0 && separator_check(msh, s))
		return (SEPARATOR);
	else
	{
		msh->utils->check_arg = 1;
		return (ARGS);
	}
	return (0);
}

void		set_token_list(t_msh *msh)
{
	t_list	*lst;
	int		i;
	int		args;

	lst = msh->lair_list->start;
	i = 0;
	args = 0;
	while (lst->content != NULL)
	{
		lst->token = token_recognition(msh, lst->content, i);
		// printf("token[%s] = %i\n", lst->content, lst->token);
		i++;
		i = (lst->token == SEPARATOR) ? 0 : i;
		msh->utils->size_opt_arg = (lst->token == ARGS || lst->token == OPT) ?
			msh->utils->size_opt_arg + 1 : msh->utils->size_opt_arg;
		lst = lst->next;
	}
}
