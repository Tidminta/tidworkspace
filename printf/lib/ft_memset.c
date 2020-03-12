/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:00:11 by tidminta          #+#    #+#             */
/*   Updated: 2020/03/06 17:26:00 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *dst;

	dst = b;
	if (len == 0)
		return (b);
	while (len > 0)
	{
		*dst = (unsigned char)c;
		dst++;
		len--;
	}
	return (b);
}
