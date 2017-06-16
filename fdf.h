/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 11:52:28 by alam              #+#    #+#             */
/*   Updated: 2017/02/27 11:52:29 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

# define CYAN 0x0000FFFF
# define MAGENTA 0x00FF00FF
# define WHITE 0x00FFFFFF
# define MAX_X 1000
# define MAX_Y 1000
# define frm_X 950
# define frm_Y 950
# define R_MSK 0x00FF0000
# define G_MSK 0x0000FF00
# define B_MSK 0x000000FF

# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Q_KEY 12
# define E_KEY 14
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define NUM_PLUS 69
# define NUM_MINUS 78

typedef struct	s_vec
{
	float x;
	float y;
	float z;
}				t_vec;

typedef struct	s_line
{
	t_vec	pt1;
	t_vec	pt2;
	int		color1;
	int		color2;
}				t_line;

typedef struct	s_mlx
{
	void *mlx;
	void *win;
}				t_mlx;

typedef struct	s_sqr
{
	int x;
	int y;
	int size;
}				t_sqr;

typedef struct	s_map
{
	float	xmax;
	float	ymax;
	float	zmax;
	int		base_color;
	int		top_color;
	int		**color;
	t_vec	**pts;
}				t_map;

typedef struct	s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		xmax;
	int		ymax;
}				t_img;

typedef struct	s_frame
{
	void	*mlx;
	void	*win;

	t_img	img;

	float	scale;
	t_map	map;
}				t_frame;

void			print_controls();
int				get_scale(t_map map);
void			load_file(int fc, t_frame *frm);
void			setup_window(t_frame *frm);

int				key_hook(int key, t_frame *frm);
int				expose_hook(t_frame *frm);

int				get_line_color(int pt1_color, int pt2_color,
								float i, float limit);
int				get_pt_color(t_vec pt, float zmax, int bot_c, int top_c);
void			load_colors(t_map *map);

void			scale_map(t_map map,
							float scale_x, float scale_y, float scale_z);
void			translate_map(t_map map,
							float trans_x, float trans_y, float trans_z);
void			rotate_map(t_map map,
							float theta_x, float theta_y, float theta_z);
void			clear_map(t_frame frm);
void			draw_map(t_frame frm);


void			fill_map(t_map *map, t_list **pt_list);
t_map			generate_map(int xmax, int ymax, float zmax, t_list **pt_list);
void			normalize_coords(t_map map);
t_list			*read_file(int fc, int *i, int *j, float *zmax);

int				increment_direction(int p1, int p2);
t_vec			move_pixel(t_vec pt1, t_vec pt2, int *err);
void			draw_line(t_line line, t_frame frm);
t_line			make_line(t_vec pt1, t_vec pt2, int color1, int color2);

int				check_key(int key);
void			key_rotate(int key, t_frame *frm);
void			key_translate(int key, t_frame *frm);
void			key_scale(int key, t_frame *frm);

t_vec			v_mult(float mat[4][4], t_vec pt);
t_vec			scale_v(t_vec pt, float scale_x, float scale_y, float scale_z);
t_vec			trans_v(t_vec pt, float trans_x, float trans_y, float trans_z);
t_vec			project(t_vec pt, float f);

t_vec			rotate_x(t_vec pt, float theta);
t_vec			rotate_y(t_vec pt, float theta);
t_vec			rotate_z(t_vec pt, float theta);

t_img	new_image(t_frame frm, int x, int y);
void	img_pxl_put(void *mlx, t_img img, int x, int y, int color);

void test(t_frame frm, t_img img);

#endif
