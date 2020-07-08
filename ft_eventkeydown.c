/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventkeydown.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 16:53:56 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/12 16:01:46 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	manupilate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE || (FDF_CTRL && keycode == KEY_C))
		exit(0);
	else if (keycode == KEY_UPARROW)
		ft_setcampos(&FDF_CAM_X, FDF_CAM_X + 0.05);
	else if (keycode == KEY_DOWNARROW)
		ft_setcampos(&FDF_CAM_X, FDF_CAM_X - 0.05);
	else if (keycode == KEY_LEFTARROW)
		ft_setcampos(&FDF_CAM_Y, FDF_CAM_Y - 0.05);
	else if (keycode == KEY_RIGHTARROW)
		ft_setcampos(&FDF_CAM_Y, FDF_CAM_Y + 0.05);
	else if (keycode == KEY_PGUP)
		ft_setcampos(&FDF_CAM_Z, FDF_CAM_Z + 0.05);
	else if (keycode == KEY_PGDN)
		ft_setcampos(&FDF_CAM_Z, FDF_CAM_Z - 0.05);
	else if (keycode == KEY_R)
	{
		ft_setcampos(&FDF_CAM_X, 0);
		ft_setcampos(&FDF_CAM_Y, 0);
		ft_setcampos(&FDF_CAM_Z, 0);
	}
	if (keycode == KEY_UPARROW || keycode == KEY_DOWNARROW ||
		keycode == KEY_LEFTARROW || keycode == KEY_RIGHTARROW ||
		keycode == KEY_PGUP || keycode == KEY_PGDN || keycode == KEY_R)
		ft_drawmap(fdf);
	return (0);
}

int			ft_eventkeydown(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_LCONTROL || keycode == KEY_RCONTROL)
		FDF_CTRL = TRUE;
	else if (keycode == KEY_LSHIFT || keycode == KEY_RSHIFT)
		FDF_SHIFT = TRUE;
	else if (keycode == KEY_LALT || keycode == KEY_RALT)
		FDF_ALT = TRUE;
	else if (keycode == KEY_LWIN || keycode == KEY_RWIN)
		FDF_WIN = TRUE;
	manupilate(keycode, fdf);
	return (0);
}
