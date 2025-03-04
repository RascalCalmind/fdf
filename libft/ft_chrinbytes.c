/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrinbytes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 01:47:24 by pholster       #+#    #+#                */
/*   Updated: 2019/03/29 12:37:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrinbytes(long long *bytes, char c)
{
	if (bytes == NULL)
		return (FALSE);
	if (c >= 64 && bytes[1] & (1LL << (c - 64)))
		return (TRUE);
	if (c < 64 && c >= 0 && bytes[0] & (1LL << c))
		return (TRUE);
	return (FALSE);
}
