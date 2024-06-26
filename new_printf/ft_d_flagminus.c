/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_flagminus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 18:43:28 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:37:40 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_d_precis_hundle(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (st_->arg_int < 0)
		ft_putchar_fd2('-', 1, p);
	if (((st_->width && st_->precis) || (!st_->width && st_->precis)))
	{
		if (st_->arg_int >= 0)
			len = len;
		else
			len = len - 1;
		while (len++ < (size_t)st_->precis)
			ft_putchar_fd2('0', 1, p);
	}
	if (!st_->arg_int && (!st_->precis && st_->is_precis))
		;
	else
		ft_putnbr_fd2(st_->arg_int, 1, p);
}

static void	ft_d_width_hundle(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	len2;

	if (st_->width && !st_->precis)
	{
		if (!st_->arg_int && !st_->precis && st_->is_precis)
			len = len - 1;
		else
			len = len;
		while ((len++ < (size_t)st_->width))
			ft_putchar_fd2(' ', 1, p);
	}
	else if (st_->width && st_->precis)
	{
		if ((st_->width) && (st_->is_precis) && (size_t)st_->precis >= len)
		{
			if (st_->arg_int >= 0)
				len2 = st_->width;
			else
				len2 = (st_->width - 1);
			while (len2-- > (size_t)st_->precis)
				ft_putchar_fd2(' ', 1, p);
		}
		else if ((st_->width) && (st_->is_precis) && (size_t)st_->precis < len)
		{
			while (len++ < (size_t)st_->width)
				ft_putchar_fd2(' ', 1, p);
		}
	}
}

void	ft_d_flagminus(t_infos_ *st_, t_params_ *p, size_t len)
{
	ft_d_precis_hundle(st_, p, len);
	ft_d_width_hundle(st_, p, len);
}
