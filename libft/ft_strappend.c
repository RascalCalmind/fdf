/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 19:47:57 by pholster       #+#    #+#                */
/*   Updated: 2019/02/18 09:44:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strappend(char **dst, const char *src)
{
	ft_strreplace(dst, ft_strjoin(*dst, src));
}
