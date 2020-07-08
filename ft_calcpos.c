/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calcpos.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 17:11:21 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/12 16:04:27 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	rotatex(t_fdf *fdf, int *y, int *z)
{
	int tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(FDF_CAM_X) + *z * -sin(FDF_CAM_X);
	*z = tmp_y * sin(FDF_CAM_X) + *z * cos(FDF_CAM_X);
}

static void	rotatey(t_fdf *fdf, int *x, int *z)
{
	int tmp_x;

	tmp_x = *x;
	*x = tmp_x * cos(FDF_CAM_Y) + *z * sin(FDF_CAM_Y);
	*z = tmp_x * -sin(FDF_CAM_Y) + *z * cos(FDF_CAM_Y);
}

static void	rotatez(t_fdf *fdf, int *x, int *y)
{
	int tmp_x;
	int tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(FDF_CAM_Z) + tmp_y * -sin(FDF_CAM_Z);
	*y = tmp_x * sin(FDF_CAM_Z) + tmp_y * cos(FDF_CAM_Z);
}

static void	iso(int *x, int *y, int z, enum e_prj projection)
{
	double	angle;
	int		tmp_x;
	int		tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	if (projection == false_iso)
		angle = 0.46373398;
	else
		angle = 0.523599;
	*x = (tmp_x + tmp_y) * cos(angle);
	*y = ((tmp_x - tmp_y) * -sin(angle)) - z;
}

void		ft_calcpos(t_fdf *fdf, t_pos *pos, int *x, int *y)
{
	int		z;
	int		zoom;

	zoom = SPACING * FDF_CAM_ZOOM;
	*x = (pos->x * zoom);
	*y = (pos->y * zoom);
	z = (pos->z * zoom);
	if (FDF_CAM_PROJECTION == parrallel)
		*x += *y;
	else if (FDF_CAM_PROJECTION == false_iso || FDF_CAM_PROJECTION == true_iso)
	{
		z /= 2;
		iso(x, y, z, FDF_CAM_PROJECTION);
	}
	rotatex(fdf, y, &z);
	rotatey(fdf, x, &z);
	rotatez(fdf, x, y);
	*y = (*y - z);
}
