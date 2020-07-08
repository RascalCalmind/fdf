/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_eventkeyup.c                                    :+:    :+:            */
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
	if (keycode == KEY_SPACE)
	{
		if (FDF_CAM_PROJECTION + 1 > 3)
			FDF_CAM_PROJECTION = 0;
		else
			FDF_CAM_PROJECTION++;
		ft_calcoffset(fdf);
		ft_drawmap(fdf);
	}
	return (0);
}

int			ft_eventkeyup(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_LCONTROL || keycode == KEY_RCONTROL)
		FDF_CTRL = FALSE;
	else if (keycode == KEY_LSHIFT || keycode == KEY_RSHIFT)
		FDF_SHIFT = FALSE;
	else if (keycode == KEY_LALT || keycode == KEY_RALT)
		FDF_ALT = FALSE;
	else if (keycode == KEY_LWIN || keycode == KEY_RWIN)
		FDF_WIN = FALSE;
	manupilate(keycode, fdf);
	return (0);
}
