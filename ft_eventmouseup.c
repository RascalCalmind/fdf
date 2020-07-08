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

int		ft_eventmouseup(int mousecode, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (mousecode == MOUSE_LEFT)
		FDF_LEFTMOUSE = FALSE;
	else if (mousecode == MOUSE_RIGHT)
		FDF_RIGHTMOUSE = FALSE;
	return (0);
}
