/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:57:45 by pholster       #+#    #+#                */
/*   Updated: 2019/02/12 14:57:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** return (((0x40 - c) < 0) && ((c - 0x5B) < 0));
*/

int		ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
