/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puttext.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 17:11:21 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/12 16:06:59 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_puttext(t_fdf *fdf, int x, int y, char *str)
{
	mlx_string_put(FDF_MLX, FDF_WINDOW, x, y, 0xFFFFFF, str);
}
