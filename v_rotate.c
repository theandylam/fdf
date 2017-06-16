/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:25:38 by alam              #+#    #+#             */
/*   Updated: 2017/03/09 13:25:39 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec	rotate_x(t_vec pt, float theta)
{
	float mat[4][4];

	mat[0][0] = 1;
	mat[1][0] = 0;
	mat[2][0] = 0;
	mat[3][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = cos(theta);
	mat[2][1] = -sin(theta);
	mat[3][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = sin(theta);
	mat[2][2] = cos(theta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_mult(mat, pt));
}

t_vec	rotate_y(t_vec pt, float theta)
{
	float mat[4][4];

	mat[0][0] = cos(theta);
	mat[1][0] = 0;
	mat[2][0] = sin(theta);
	mat[3][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = 1;
	mat[2][1] = 0;
	mat[3][1] = 0;
	mat[0][2] = -sin(theta);
	mat[1][2] = 0;
	mat[2][2] = cos(theta);
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_mult(mat, pt));
}

t_vec	rotate_z(t_vec pt, float theta)
{
	float mat[4][4];

	mat[0][0] = cos(theta);
	mat[1][0] = -sin(theta);
	mat[2][0] = 0;
	mat[3][0] = 0;
	mat[0][1] = sin(theta);
	mat[1][1] = cos(theta);
	mat[2][1] = 0;
	mat[3][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = 0;
	mat[2][2] = 1;
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_mult(mat, pt));
}
