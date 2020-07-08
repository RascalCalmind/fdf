/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ_nocase.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:54:47 by pholster       #+#    #+#                */
/*   Updated: 2019/03/18 15:37:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ_nocase(const char *str1, const char *str2, size_t n)
{
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	return (ft_strncmp_nocase(str1, str2, n) == 0);
}
