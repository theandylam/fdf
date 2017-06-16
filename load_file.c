/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:29:42 by alam              #+#    #+#             */
/*   Updated: 2017/02/27 16:29:44 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_map(t_map *map, t_list **pt_list)
{
	int		x;
	int		y;
	t_list	*cur;
	t_vec	pt;

	x = map->xmax - 1;
	y = map->ymax - 1;
	cur = *pt_list;
	while (cur != NULL)
	{
		if (y < 0)
			break ;
		pt = *(t_vec *)cur->content;
		map->pts[x][y] = pt;
		cur = cur->next;
		x--;
		if (x < 0)
		{
			x = map->xmax - 1;
			y--;
		}
	}
}

t_map	generate_map(int xmax, int ymax, float zmax, t_list **pt_list)
{
	int		x;
	t_map	map;

	x = 0;
	map.pts = ft_memalloc(sizeof(t_vec *) * xmax);
	map.xmax = xmax;
	map.ymax = ymax;
	map.zmax = zmax;
	while (x < xmax)
	{
		map.pts[x] = ft_memalloc(sizeof(t_vec) * ymax);
		x++;
	}
	fill_map(&map, pt_list);
	return (map);
}

void	normalize_coords(t_map map)
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
			map.pts[i][j].x -= floor(map.xmax / 2);
			map.pts[i][j].y -= floor(map.ymax / 2);
			map.pts[i][j].z -= floor(map.zmax / 2);
			i++;
		}
		j++;
	}
}

t_list	*read_file(int fc, int *i, int *j, float *zmax)
{
	char	*in_line;
	char	**temp;
	t_vec	point;
	t_list	*pt_list;

	pt_list = NULL;
	*zmax = 0;
	while (get_next_line(fc, &in_line) > 0)
	{
		*i = 0;
		temp = ft_strsplit(in_line, ' ');
		while (temp[(*i)] != 0)
		{
			point.x = *i;
			point.y = *j;
			point.z = ft_atoi(temp[(*i)]);
			*zmax = (point.z > *zmax) ? point.z : *zmax;
			ft_lstadd(&pt_list, ft_lstnew(&point, sizeof(point)));
			*i += 1;
		}
		ft_freesplit(temp);
		free(in_line);
		*j += 1;
	}
	return (pt_list);
}
