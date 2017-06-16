/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:50:26 by alam              #+#    #+#             */
/*   Updated: 2017/02/27 11:50:28 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_map(t_map map, float scale_x, float scale_y, float scale_z)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map.ymax)
	{
		i = 0;
		while (i < map.xmax)
		{
			map.pts[i][j] = scale_v(map.pts[i][j], scale_x, scale_y, scale_z);
			i++;
		}
		j++;
	}
}

void	translate_map(t_map map, float trans_x, float trans_y, float trans_z)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map.ymax)
	{
		i = 0;
		while (i < map.xmax)
		{
			map.pts[i][j] = trans_v(map.pts[i][j], trans_x, trans_y, trans_z);
			i++;
		}
		j++;
	}
}

void	rotate_map(t_map map, float theta_x, float theta_y, float theta_z)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map.ymax)
	{
		i = 0;
		while (i < map.xmax)
		{
			map.pts[i][j] = rotate_x(map.pts[i][j], theta_x);
			map.pts[i][j] = rotate_y(map.pts[i][j], theta_y);
			map.pts[i][j] = rotate_z(map.pts[i][j], theta_z);
			i++;
		}
		j++;
	}
}

void	clear_map(t_frame frm)
{
	int		i;
	int		j;
	t_line	l;

	j = 0;
	while (j < frm.map.ymax)
	{
		i = 0;
		while (i < frm.map.xmax)
		{
			l.pt1 = trans_v(frm.map.pts[i][j], 500, 500, 500);
			img_pxl_put(frm.mlx, frm.img, l.pt1.x, l.pt1.y, 0);
			if (i < frm.map.xmax - 1)
				draw_line(make_line(l.pt1,
							trans_v(frm.map.pts[i + 1][j], 500, 500, 500),
							0, 0), frm);
			if (j < frm.map.ymax - 1)
				draw_line(make_line(l.pt1,
							trans_v(frm.map.pts[i][j + 1], 500, 500, 500),
							0, 0), frm);
			i++;
		}
		j++;
	}
}

void	draw_map(t_frame frm)
{
	int		i;
	int		j;
	t_line	l;

	j = 0;
	while (j < frm.map.ymax)
	{
		i = 0;
		while (i < frm.map.xmax)
		{
			l.pt1 = trans_v(frm.map.pts[i][j], 500, 500, 500);
			img_pxl_put(frm.mlx, frm.img, l.pt1.x, l.pt1.y, frm.map.color[i][j]);
			if (i < frm.map.xmax - 1)
				draw_line(make_line(l.pt1,
							trans_v(frm.map.pts[i + 1][j], 500, 500, 500),
							frm.map.color[i][j], frm.map.color[i + 1][j]), frm);
			if (j < frm.map.ymax - 1)
				draw_line(make_line(l.pt1,
							trans_v(frm.map.pts[i][j + 1], 500, 500, 500),
							frm.map.color[i][j], frm.map.color[i][j + 1]), frm);
			i++;
		}
		j++;
	}
}
