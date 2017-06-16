/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:04:24 by alam              #+#    #+#             */
/*   Updated: 2017/03/09 14:04:25 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_key(int key)
{
	if (key == W_KEY || key == A_KEY || key == S_KEY || key == D_KEY
		|| key == Q_KEY || key == E_KEY)
		return (1);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		return (2);
	else if (key == NUM_PLUS || key == NUM_MINUS)
		return (3);
	else
		return (0);
}

void	key_rotate(int key, t_frame *frm)
{
	if (key == W_KEY)
		rotate_map(frm->map, 5 * M_PI / 180.0, 0, 0);
	else if (key == A_KEY)
		rotate_map(frm->map, 0, -5 * M_PI / 180.0, 0);
	else if (key == S_KEY)
		rotate_map(frm->map, -5 * M_PI / 180.0, 0, 0);
	else if (key == D_KEY)
		rotate_map(frm->map, 0, 5 * M_PI / 180.0, 0);
	else if (key == E_KEY)
		rotate_map(frm->map, 0, 0, 5 * M_PI / 180.0);
	else if (key == Q_KEY)
		rotate_map(frm->map, 0, 0, -5 * M_PI / 180.0);
}

void	key_translate(int key, t_frame *frm)
{
	if (key == UP)
		translate_map(frm->map, 0, -10, 0);
	else if (key == DOWN)
		translate_map(frm->map, 0, 10, 0);
	else if (key == LEFT)
		translate_map(frm->map, -10, 0, 0);
	else if (key == RIGHT)
		translate_map(frm->map, 10, 0, 0);
}

void	key_scale(int key, t_frame *frm)
{
	if (key == NUM_PLUS)
		scale_map(frm->map, 1.1, 1.1, 1.1);
	else if (key == NUM_MINUS)
		scale_map(frm->map, 0.9, 0.9, 0.9);
}
