/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:02:35 by alam              #+#    #+#             */
/*   Updated: 2017/02/22 19:02:36 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_controls(void)
{
	ft_printf("KEYBOARD CONTROLS\n");
	ft_printf("      WASD : Rotate around x/y axis\n");
	ft_printf("        QE : Rotate around z axis\n");
	ft_printf("Arrow keys : Move wireframe\n");
	ft_printf("Numpad +/- : Change size of wireframe\n");
	ft_printf("       ESC : Quit\n");
}

int		get_scale(t_map map)
{
	int	scale;

	scale = (map.xmax >= map.ymax) ? (MAX_X / map.xmax) : (MAX_Y / map.ymax);
	if (scale > 1)
		scale--;
	return (scale);
}

void	load_file(int fc, t_frame *frm)
{
	int		xmax;
	int		ymax;
	float	zmax;
	t_list	*pt_list;

	xmax = 0;
	ymax = 0;
	ft_printf("Reading file\n");
	pt_list = read_file(fc, &xmax, &ymax, &zmax);
	ft_printf("Map size: %d x %d\n", xmax, ymax);
	frm->map = generate_map(xmax, ymax, zmax, &pt_list);
	frm->map.base_color = CYAN;
	frm->map.top_color = MAGENTA;
	load_colors(&frm->map);
	normalize_coords(frm->map);
	ft_printf("Loaded file\n");
}

void	setup_window(t_frame *frm)
{
	frm->mlx = mlx_init();
	frm->win = mlx_new_window(frm->mlx, MAX_X, MAX_Y, "FDF");
	frm->img = new_image(*frm, 1000, 1000);
	ft_printf("Created window\n");
	frm->scale = get_scale(frm->map);
	scale_map(frm->map, frm->scale, frm->scale, frm->scale / 2);
	ft_printf("Drawing map\n");
	draw_map(*frm);
	mlx_put_image_to_window(frm->mlx, frm->win, frm->img.ptr, 0, 0);
	ft_printf("Initial draw complete\n");
	print_controls();
}

int		main(int argc, char **argv)
{
	int		fc;
	t_frame	frm;

	if (argc != 2)
	{
		ft_printf("Usage: ./fdf [file]\n");
		return (0);
	}
	fc = open(argv[1], O_RDONLY);
	if (fc < 0)
	{
		ft_printf("Error opening file\n");
		return (0);
	}
	load_file(fc, &frm);
	setup_window(&frm);
	mlx_key_hook(frm.win, &key_hook, &frm);
	mlx_expose_hook(frm.win, &expose_hook, &frm);
	mlx_loop(frm.mlx);
	return (0);
}
