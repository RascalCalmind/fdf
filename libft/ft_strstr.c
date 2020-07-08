/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:35:14 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:12:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && needle[j] != '\0')
	{
		j -= (j > 0 && str[i - j] != needle[0]);
		j -= (j > 0 && str[i] != needle[j]);
		j += (str[i] == needle[j]);
		i++;
	}
	j += (str[i - 1] == needle[j]);
	if (needle[j] == '\0')
		return ((char *)&str[i - j]);
	return (NULL);
}
