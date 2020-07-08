/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventmousemove.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 14:27:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 13:33:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	manupilate(int x, int y, t_fdf *fdf)
{
	int	dx;
	int	dy;

	dx = FDF_MOUSEPOS_X - x;
	dy = FDF_MOUSEPOS_Y - y;
	if (y > 1 && FDF_LEFTMOUSE && dx != 0)
	{
		if (dx < 0)
			ft_setcampos(&FDF_CAM_Y, FDF_CAM_Y + 0.025);
		else
			ft_setcampos(&FDF_CAM_Y, FDF_CAM_Y - 0.025);
	}
	if (y > 1 && FDF_LEFTMOUSE && dy != 0)
	{
		if (dy < 0)
			ft_setcampos(&FDF_CAM_X, FDF_CAM_X + 0.025);
		else
			ft_setcampos(&FDF_CAM_X, FDF_CAM_X - 0.025);
	}
	if (y > 1 && FDF_LEFTMOUSE && (dx != 0 || dy != 0))
		ft_drawmap(fdf);
	return (0);
}

int			ft_eventmousemove(int x, int y, t_fdf *fdf)
{
	manupilate(x, y, fdf);
	FDF_MOUSEPOS_X = x;
	FDF_MOUSEPOS_Y = y;
	return (0);
}
