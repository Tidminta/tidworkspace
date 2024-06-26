/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:19:03 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/18 16:35:30 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_printf(const char *s, ...)
{
	t_infos_	*struct_;
	t_params_	*params_;
	va_list		list_ptr;
	va_list		*list_tmp;
	int			i;

	va_start(list_ptr, s);
	list_tmp = &list_ptr;
	params_ = ft_init_params();
	while (s[params_->index])
	{
		struct_ = ft_init_struct();
		ft_print_loop(s, params_);
		ft_print_arg(struct_, list_tmp, s, params_);
		free(struct_);
	}
	i = params_->conv_len;
	va_end(list_ptr);
	free(params_);
	return (i);
}
