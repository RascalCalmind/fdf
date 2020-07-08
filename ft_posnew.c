/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_posnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 13:16:18 by lhageman       #+#    #+#                */
/*   Updated: 2019/04/15 14:27:46 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	*ft_posnew(int x, int y, int z, char *color)
{
	t_pos	*pos;

	pos = (t_pos *)ft_memalloc(sizeof(t_pos));
	if (pos == NULL)
		return (NULL);
	pos->x = x;
	pos->y = y;
	pos->z = z;
	if (color == NULL)
		pos->color = -1;
	else
	{
		color = ft_toupperstr(color);
		pos->color = ft_atoi_base(color, 16);
	}
	return (pos);
}
