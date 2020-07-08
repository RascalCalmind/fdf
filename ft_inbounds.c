/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_inbounds.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 18:08:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/10 18:14:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_inbounds(t_fdf *fdf, int x, int y)
{
	return (x < FDF_WINDOW_X && x >= 0 && y < FDF_WINDOW_Y && y >= 0);
}
