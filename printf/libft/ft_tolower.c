/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:55:17 by tidminta          #+#    #+#             */
/*   Updated: 2020/01/17 19:48:45 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		c = c + 32;
		return (c);
	}
	return (c);
}
