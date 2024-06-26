/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:32:20 by tidminta          #+#    #+#             */
/*   Updated: 2020/10/08 19:09:51 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

static int			ft_init_text2(t_mapinfos *map, int resx, int resy)
{
	if (!(map->text[3]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[3]->path, &resx, &resy)))
		return (-1);
	map->text[3]->data = (int*)mlx_get_data_addr(map->text[3]->img_p,
		&map->text[3]->bpp, &map->text[3]->s_l, &map->text[3]->end);
	if (!(map->text[4]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[4]->path, &resx, &resy)))
		return (-1);
	map->text[4]->data = (int*)mlx_get_data_addr(map->text[4]->img_p,
		&map->text[4]->bpp, &map->text[4]->s_l, &map->text[4]->end);
	return (0);
}

int					ft_init_text(t_mapinfos *map)
{
	int			resx;
	int			resy;

	resx = map->res->x;
	resy = map->res->y;
	if (!(map->text[0]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[0]->path, &resx, &resy)))
		return (-1);
	map->text[0]->data = (int*)mlx_get_data_addr(map->text[0]->img_p,
		&map->text[0]->bpp, &map->text[0]->s_l, &map->text[0]->end);
	if (!(map->text[1]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[1]->path, &resx, &resy)))
		return (-1);
	map->text[1]->data = (int*)mlx_get_data_addr(map->text[1]->img_p,
		&map->text[1]->bpp, &map->text[1]->s_l, &map->text[1]->end);
	if (!(map->text[2]->img_p = mlx_xpm_file_to_image(map->mlx->mlx_p,
		map->text[2]->path, &resx, &resy)))
		return (-1);
	map->text[2]->data = (int*)mlx_get_data_addr(map->text[2]->img_p,
		&map->text[2]->bpp, &map->text[2]->s_l, &map->text[2]->end);
	if (ft_init_text2(map, resx, resy) < 0)
		return (-1);
	return (0);
}

void				ft_free_text(t_mapinfos *map)
{
	int i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(map->mlx->mlx_p, map->text[i]->img_p);
}

static void			ft_drawtext2(t_mapinfos *map, t_mlx *mlx)
{
	int			y;
	int			color;
	int			nb;
	t_player	*p;

	p = map->p;
	y = p->drawstart;
	while (y++ < p->drawend)
	{
		nb = ft_get_index(map->p);
		p->texy = (int)p->texpos & (TEXHEIGHT - 1);
		color = map->text[nb]->data[TEXHEIGHT * p->texy + p->texx];
		p->texpos += p->step;
		color = (p->side == 1) ? (color >> 1) & 8355711 : color;
		mlx->img->data[(int)(y * map->res->x + p->x)] = color;
	}
}

void				ft_drawtext(t_mapinfos *map, t_mlx *mlx)
{
	char		**map2d;
	t_player	*p;

	p = map->p;
	map2d = map->map_tab;
	if (p->side == 0)
		p->wallx = p->posy + p->perpwd * p->raydy;
	else
		p->wallx = p->posx + p->perpwd * p->raydx;
	p->wallx -= floor(p->wallx);
	p->texx = (int)(p->wallx * (double)TEXWIDTH);
	if (p->side == 0 && p->raydx > 0)
		p->texx = TEXWIDTH - p->texx - 1;
	if (p->side == 1 && p->raydy < 0)
		p->texx = TEXWIDTH - p->texx - 1;
	p->step = 1.0 * TEXHEIGHT / p->lineheight;
	p->texpos = (p->drawstart - map->res->y / 2 + p->lineheight / 2) * p->step;
	ft_drawtext2(map, mlx);
}
