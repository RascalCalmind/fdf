/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intarrsort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 15:07:28 by pholster       #+#    #+#                */
/*   Updated: 2019/03/22 23:46:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_intarrsort(int *arr, int (*f)(int, int), size_t len)
{
	size_t	i;
	size_t	j;
	int		current;

	i = 1;
	if (arr == NULL)
		return ;
	while (i < len)
	{
		j = i;
		current = arr[i];
		while (j > 0 && f(current, arr[j - 1]))
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = current;
		i++;
	}
}
