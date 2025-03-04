/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:02 by pholster       #+#    #+#                */
/*   Updated: 2019/03/16 23:05:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t len)
{
	unsigned const char	*temp_str1;
	unsigned const char	*temp_str2;
	size_t				i;

	i = 0;
	temp_str1 = str1;
	temp_str2 = str2;
	while (i < len)
	{
		if (temp_str1[i] != temp_str2[i])
			return (temp_str1[i] - temp_str2[i]);
		i++;
	}
	return (0);
}
