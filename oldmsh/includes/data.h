/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:16:18 by loamar            #+#    #+#             */
/*   Updated: 2021/05/17 17:33:38 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define PIPE 1
# define SEMICOLON 2
# define CHEVRONL 3
# define CHEVRONR 4
# define CHEVROND 5
# define AND 6
# define OR 7
# define VARIABLE 8
# define CMD 9
# define OPT 10
# define ARG 11
# define SQUOTE 39
# define DQUOTE 34
# define SEPARATOR 35
# define SEP 35
# define ARGS 36

int				handler_data(t_msh **msh, char *buf);
int				check_data_separator(t_data *data);
int				check_prompt(t_data *data);
t_lair_list		*init_data_lair_list(t_lair_list *lair_list);

char			**ft_split_data(char *s, char c);
int				ft_count_separator(char *s, int pos);
void			ft_count_word_noquote(char *s, char c, t_split_data *data);
void			ft_count_word_quote(char *s, char c, t_split_data *data);
int				ft_get_len_word_quote(char *s, char c,
				t_split_data *data, int index);
void			check_quote(char *s, t_split_data *data);

#endif