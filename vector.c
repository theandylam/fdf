/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alam <theandylam@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:04:30 by alam              #+#    #+#             */
/*   Updated: 2016/10/31 11:04:32 by alam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec	v_mult(float mat[4][4], t_vec pt)
{
	t_vec out;

	out.x = (mat[0][0] * pt.x) + (mat[1][0] * pt.y) +
			(mat[2][0] * pt.z) + (mat[3][0] * 1);
	out.y = (mat[0][1] * pt.x) + (mat[1][1] * pt.y) +
			(mat[2][1] * pt.z) + (mat[3][1] * 1);
	out.z = (mat[0][2] * pt.x) + (mat[1][2] * pt.y) +
			(mat[2][2] * pt.z) + (mat[3][2] * 1);
	return (out);
}

t_vec	scale_v(t_vec pt, float scale_x, float scale_y, float scale_z)
{
	float mat[4][4];

	mat[0][0] = scale_x;
	mat[1][0] = 0;
	mat[2][0] = 0;
	mat[3][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = scale_y;
	mat[2][1] = 0;
	mat[3][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = 0;
	mat[2][2] = scale_z;
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_mult(mat, pt));
}

t_vec	trans_v(t_vec pt, float trans_x, float trans_y, float trans_z)
{
	float mat[4][4];

	mat[0][0] = 1;
	mat[1][0] = 0;
	mat[2][0] = 0;
	mat[3][0] = trans_x;
	mat[0][1] = 0;
	mat[1][1] = 1;
	mat[2][1] = 0;
	mat[3][1] = trans_y;
	mat[0][2] = 0;
	mat[1][2] = 0;
	mat[2][2] = 1;
	mat[3][2] = trans_z;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 0;
	mat[3][3] = 1;
	return (v_mult(mat, pt));
}

t_vec	project(t_vec pt, float f)
{
	float mat[4][4];

	mat[0][0] = f;
	mat[1][0] = 0;
	mat[2][0] = 0;
	mat[3][0] = 0;
	mat[0][1] = 0;
	mat[1][1] = f;
	mat[2][1] = 0;
	mat[3][1] = 0;
	mat[0][2] = 0;
	mat[1][2] = 0;
	mat[2][2] = f;
	mat[3][2] = 0;
	mat[0][3] = 0;
	mat[1][3] = 0;
	mat[2][3] = 1;
	mat[3][3] = 0;
	return (v_mult(mat, pt));
}
