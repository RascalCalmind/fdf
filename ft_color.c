/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_color.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 19:52:23 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/15 18:13:01 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(int z, int color)
{
	if (color != -1)
		return (color);
	if (z <= -5)
		return (0xFF9AA2);
	if (z > -5 && z <= 0)
		return (0xFFB7B2);
	if (z > 0 && z <= 1)
		return (0xFFDAC1);
	if (z > 1 && z < 2)
		return (0xE2F0CB);
	if (z >= 3 && z <= 6)
		return (0xB5EAD7);
	if (z > 6 && z <= 10)
		return (0xC7CEEA);
	else
		return (0xFFFFFF);
	return (0xFFFFFF);
}
