/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 11:03:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrin(const char *str, int c)
{
	return (ft_chrindex(str, c) != -1);
}
