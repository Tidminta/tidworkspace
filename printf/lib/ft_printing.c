/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:05:24 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/18 18:33:34 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** 1. Fonction qui check si le char est un affichage implicite. Ex '\n'
*/

static int		ft_specific_print(char c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == 'f' || c == '\b')
		return (1);
	return (0);
}

/*
** 2. Fonction qui affiche la string jusqu'au premier '%'
*/

void	ft_print_loop(const char *str, t_params_ *p)
{
	while (str[p->index] && str[p->index] != '%' &&
		(ft_isprint(str[p->index]) || ft_specific_print(str[p->index])))
	{
		ft_putchar_fd(str[p->index], 1, p);
		p->index += 1;
	}
}

/*
** 3. Fonction qui affiche l'argument
*/

void	ft_print_arg(t_infos_ *stct_, va_list *lst, const char *s, t_params_ *p)
{
	if (s[p->index] == '%')
	{
		ft_fill_struct(stct_, lst, s, &p->index);
		if (stct_->conv_spe == 'd' || stct_->conv_spe == 'i')
			ft_printf_digits(stct_, p);
		else if (stct_->conv_spe == 'c')
			ft_printf_char(stct_, p);
		else if (stct_->conv_spe == 's')
			ft_printf_string(stct_, p);
		else if (stct_->conv_spe == 'u')
			ft_printf_unsigned(stct_, p);
		else if (stct_->conv_spe == 'x' || stct_->conv_spe == 'X')
			ft_printf_hexa(stct_, p);
		else if (stct_->conv_spe == 'p')
		{
			ft_putstr_fd("0x", 1, p);
			ft_putnbr_base(stct_->arg_addr, "0123456789abcdef", p);
		}
	}
}
