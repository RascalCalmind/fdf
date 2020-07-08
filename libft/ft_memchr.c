/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster       #+#    #+#                */
/*   Updated: 2019/03/16 23:06:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*temp_str;
	size_t			i;

	i = 0;
	temp_str = (unsigned char *)str;
	while (i < len)
	{
		if (temp_str[i] == (unsigned char)c)
			return (&temp_str[i]);
		i++;
	}
	return (NULL);
}
