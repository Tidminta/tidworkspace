/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 23:08:44 by tidminta          #+#    #+#             */
/*   Updated: 2020/04/04 18:46:14 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libftprintf.h"

int	main(void)
{
	// t_params_		*p;
	size_t			ret;
	size_t			ret2;
	unsigned int	ret3;

/*
**	*******************************
**			PRINTF TESTS
**	*******************************
*/
	ret3 = 198;
	ret = ft_printf("[ft_][%#-4.4X]", ret3);
	printf("[%lu]\n", ret);
	ret2 = printf("[FCT][%#-4.4X]", ret3);
	printf("[%lu]\n", ret2);
/*
**	*******************************
**			OTHERS
**	*******************************
*/
	// printf("[LEN][%lu]\n", ft_strlen("  "));
	return (0);
}
