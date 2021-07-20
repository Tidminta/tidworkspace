/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:59 by loamar            #+#    #+#             */
/*   Updated: 2021/06/30 14:51:08 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>

# define PATH_MAX 4096
# define SUCCESS 0
# define ERROR -1

# include "./includes/struct.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "./includes/list.h"
# include "./includes/data.h"
# include "./includes/cmd.h"
# include "./includes/built.h"
# include "./includes/global.h"

t_msh			*init_shell(t_msh *msh);
int				data_check(t_msh *msh);
int				handler_error(t_msh *msh);
t_msh			*init_msh(t_msh *msh);
t_env_lair		*init_env_lair(t_env_lair *env_lair);
void			free_error(t_msh *msh);
int				free_lair_list(t_msh *msh);
int				free_env_lair(t_msh *msh);
void			ft_free_separator_tab(t_msh *msh);
int				free_data(t_msh *msh);
t_lair_list		*init_lair_list(t_lair_list *lair_list);
int				fill_separator_tab(t_msh *msh);
t_lair_list		*clear_list(t_lair_list *lair_list);
t_lair_list		*pop_back_list(t_lair_list *lair_list);
void			set_token_list(t_msh *msh);
int				handler_env(t_msh *msh, char **env);
int				ft_fill_empty_env(t_env_lair *env_lair, char *content);
int				ft_fill_end_env(t_env_lair *env_lair, char *content);
t_env_lair		*clear_env(t_env_lair *env_lair);
t_env_lair		*pop_back_env(t_env_lair *env_lair);
int             handle_staatus(int status);

int				ft_handler_built_in(t_msh *msh, t_list *element, char **env);

#endif