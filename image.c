/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:48:39 by alam              #+#    #+#             */
/*   Updated: 2017/03/24 14:48:40 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img	new_image(t_frame frm, int x, int y)
{
	t_img new_image;

	new_image.xmax = x;
	new_image.ymax = y;
	new_image.ptr = mlx_new_image(frm.mlx, x, y);
	new_image.addr = mlx_get_data_addr(new_image.ptr, &new_image.bpp,
										&new_image.line_size, &new_image.endian);
	return (new_image);
}
void	img_pxl_put(void *mlx, t_img img, int x, int y, int color)
{
	int i;
	unsigned char	c_byte;
	unsigned int	img_color;

	i = 0;
	img_color = mlx_get_color_value(mlx, color);
	if (x >= img.xmax || y >= img.ymax || x < 0 || y < 0)
		return ;
	while (i < (img.bpp / 8))
	{
		if (img.endian)
			c_byte = (img_color & (0xFF000000 >> (i * 8))) >> (((img.bpp / 8) - i - 1) * 8);
		else
			c_byte = (img_color & (0xFF << (i * 8))) >> (i * 8);
		img.addr[(x * (img.bpp / 8)) + (y * img.line_size) + i] = c_byte;
		i++;
	}
}
