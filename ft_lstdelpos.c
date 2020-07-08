/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelpos.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 12:59:56 by pholster       #+#    #+#                */
/*   Updated: 2019/04/03 14:35:51 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lsstdelpos(void *pos, size_t size)
{
	(void)size;
	ft_memdel(&pos);
}
