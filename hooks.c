/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:25:58 by alam              #+#    #+#             */
/*   Updated: 2017/03/14 14:25:59 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int key, t_frame *frm)
{
	clear_map(*frm);
	if (key == ESC)
		exit(0);
	else if (check_key(key) == 1)
		key_rotate(key, frm);
	else if (check_key(key) == 2)
		key_translate(key, frm);
	else if (check_key(key) == 3)
		key_scale(key, frm);
	draw_map(*frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img.ptr, 0, 0);
	return (0);
}

int		expose_hook(t_frame *frm)
{
	clear_map(*frm);
	draw_map(*frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img.ptr, 0, 0);

	return (0);
}
