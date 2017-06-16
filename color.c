/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:22:35 by alam              #+#    #+#             */
/*   Updated: 2017/03/08 19:22:36 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_line_color(int pt1_color, int pt2_color, float i, float limit)
{
	int				shift;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	shift = (((pt2_color & R_MSK) >> 16) - ((pt1_color & R_MSK) >> 16))
			* (i / limit);
	r = ((pt1_color & R_MSK) >> 16) + shift;
	shift = (((pt2_color & G_MSK) >> 8) - ((pt1_color & G_MSK) >> 8))
			* (i / limit);
	g = ((pt1_color & G_MSK) >> 8) + shift;
	shift = (((pt2_color & B_MSK) >> 0) - ((pt1_color & B_MSK) >> 0))
			* (i / limit);
	b = ((pt1_color & B_MSK) >> 0) + shift;
	return ((r << 16) + (g << 8) + b);
}

int		get_pt_color(t_vec pt, float zmax, int bot_c, int top_c)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				shift;

	shift = (((top_c & R_MSK) >> 16) - ((bot_c & R_MSK) >> 16)) * (pt.z / zmax);
	r = ((bot_c & R_MSK) >> 16) + shift;
	shift = (((top_c & G_MSK) >> 8) - ((bot_c & G_MSK) >> 8)) * (pt.z / zmax);
	g = ((bot_c & G_MSK) >> 8) + shift;
	shift = (((top_c & B_MSK) >> 0) - ((bot_c & B_MSK) >> 0)) * (pt.z / zmax);
	b = ((bot_c & B_MSK) >> 0) + shift;
	return ((r << 16) + (g << 8) + b);
}

void	load_colors(t_map *map)
{
	int		x;
	int		y;
	t_vec	pt;

	x = 0;
	y = 0;
	map->color = ft_memalloc(sizeof(int *) * map->xmax);
	while (x < map->xmax)
	{
		map->color[x] = ft_memalloc(sizeof(int) * map->ymax);
		x++;
	}
	while (y < map->ymax)
	{
		x = 0;
		while (x < map->xmax)
		{
			pt = map->pts[x][y];
			map->color[x][y] = get_pt_color(pt, map->zmax, map->base_color,
											map->top_color);
			x++;
		}
		y++;
	}
}
