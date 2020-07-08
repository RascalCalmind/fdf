/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawlineyplus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 13:32:42 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/15 14:16:35 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_drawlineyplus(t_fdf *fdf, t_line line, float m, t_pos *pos)
{
	int	dx;
	int	dy;
	int ycurrent;
	int	xstep;
	int x;

	dx = line.x2 - line.x1;
	dy = line.y2 - line.y1;
	ycurrent = line.y1;
	xstep = (dx < 0) ? -1 : 1;
	x = line.x1;
	ft_imagepixelput(fdf, x, ycurrent, ft_color(pos->z, pos->color));
	while (ycurrent < line.y2)
	{
		m -= (xstep == -1) ? -dx : dx;
		ycurrent += 1;
		if (m < 0)
		{
			x += xstep;
			m += dy;
		}
		ft_imagepixelput(fdf, x, ycurrent, ft_color(pos->z, pos->color));
	}
}
