/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventmouse.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 14:27:21 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 13:33:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	manupilate(int mousecode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (mousecode == MOUSE_SCROLLDOWN)
		ft_zoomset(fdf, (FDF_CAM_ZOOM) / 1.1);
	else if (mousecode == MOUSE_SCROLLUP)
		ft_zoomset(fdf, (FDF_CAM_ZOOM) * 1.1);
	if ((mousecode == MOUSE_SCROLLDOWN) || (mousecode == MOUSE_SCROLLUP))
		ft_drawmap(fdf);
	return (0);
}

int			ft_eventmousedown(int mousecode, int x, int y, t_fdf *fdf)
{
	if (y > 1 && mousecode == MOUSE_LEFT)
		FDF_LEFTMOUSE = TRUE;
	else if (y > 1 && mousecode == MOUSE_RIGHT)
		FDF_RIGHTMOUSE = TRUE;
	manupilate(mousecode, x, y, fdf);
	return (0);
}
