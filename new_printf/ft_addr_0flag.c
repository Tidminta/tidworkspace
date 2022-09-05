/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr_0flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 20:24:19 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/20 20:33:38 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_addr_w_p(t_infos_ *st_, t_params_ *p, size_t len)
{
	size_t	width_len;
	size_t	precis_len;

	width_len = st_->width;
	if ((size_t)st_->precis < len)
		precis_len = len + 2;
	else
		precis_len = st_->precis + 2;
	while (width_len-- > precis_len)
		ft_putchar_fd2(' ', 1, p);
	ft_putstr_fd2("0x", 1, p);
	while (len++ < (size_t)st_->precis)
		ft_putchar_fd2('0', 1, p);
	if (st_->precis != 0)
		ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
}

static void	ft_addr_only_width(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (st_->arg_addr == 0 && st_->is_precis)
		len = 2;
	else
		len = len + 2;
	while (len++ < (size_t)st_->width)
		ft_putchar_fd2(' ', 1, p);
	ft_putstr_fd2("0x", 1, p);
	if (st_->arg_addr == 0 && !st_->is_precis)
		ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
	else if (st_->arg_addr != 0)
		ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
}

static void	ft_addr_only_precis(t_infos_ *st_, t_params_ *p, size_t len)
{
	ft_putstr_fd2("0x", 1, p);
	while (len++ < (size_t)st_->precis)
		ft_putchar_fd2('0', 1, p);
	if (st_->precis != 0)
		ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
}

void	ft_addr_0flag(t_infos_ *st_, t_params_ *p, size_t len)
{
	if (st_->width && st_->precis)
		ft_addr_w_p(st_, p, len);
	else if (st_->width && !st_->precis)
		ft_addr_only_width(st_, p, len);
	else if (!st_->width && st_->precis)
		ft_addr_only_precis(st_, p, len);
	else
	{
		ft_putstr_fd2("0x", 1, p);
		if ((st_->arg_addr == 0 && st_->is_precis == 1))
			;
		else
			ft_putnbr_base(st_->arg_addr, "0123456789abcdef", p);
	}
}
