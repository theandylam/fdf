/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:27:21 by alam              #+#    #+#             */
/*   Updated: 2017/03/08 15:27:22 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		increment_direction(int p1, int p2)
{
	if (p2 > p1)
		return (1);
	else if (p1 > p2)
		return (-1);
	else
		return (0);
}

t_vec	move_pixel(t_vec pt1, t_vec pt2, int *err)
{
	int	dx;
	int	dy;

	dx = fabs(pt2.x - pt1.x);
	dy = fabs(pt2.y - pt1.y);
	if (*err >= 0)
	{
		if (dy > dx)
			pt1.x += increment_direction(pt1.x, pt2.x);
		else
			pt1.y += increment_direction(pt1.y, pt2.y);
		*err -= (dy > dx) ? dy : dx;
	}
	if (dy > dx)
		pt1.y += increment_direction(pt1.y, pt2.y);
	else
		pt1.x += increment_direction(pt1.x, pt2.x);
	*err += (dy > dx) ? dx : dy;
	return (pt1);
}

void	draw_line(t_line line, t_frame frm)
{
	int	i;
	int	dx;
	int	dy;
	int	err;
	int	limit;

	i = 0;
	dx = fabs(line.pt2.x - line.pt1.x);
	dy = fabs(line.pt2.y - line.pt1.y);
	err = (dy > dx) ? dx - dy : dy - dx;
	limit = (dy > dx) ? dy : dx;
	while (i <= limit)
	{
		img_pxl_put(frm.mlx, frm.img, line.pt1.x, line.pt1.y,
						get_line_color(line.color1, line.color2, i, limit));
		line.pt1 = move_pixel(line.pt1, line.pt2, &err);
		i++;
	}
}

t_line	make_line(t_vec pt1, t_vec pt2, int color1, int color2)
{
	t_line	out;

	out.pt1 = pt1;
	out.pt2 = pt2;
	out.color1 = color1;
	out.color2 = color2;
	return (out);
}
