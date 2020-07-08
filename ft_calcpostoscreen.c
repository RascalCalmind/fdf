/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calcpostoscreen.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 17:11:21 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/12 16:01:48 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_calcpostoscreen(t_fdf *fdf, t_pos *pos, int *x, int *y)
{
	ft_calcpos(fdf, pos, x, y);
	*x += FDF_OFFSET_X;
	*y += FDF_OFFSET_Y;
}
