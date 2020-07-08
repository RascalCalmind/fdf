/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checkformat.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 12:59:56 by pholster       #+#    #+#                */
/*   Updated: 2019/04/15 12:41:24 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	base16check(char c)
{
	c = ft_toupper(c);
	if ((c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'))
		return (TRUE);
	return (FALSE);
}

static int	checkcolor(char *str)
{
	int i;

	i = 1;
	if (str[i] != '0')
		return (FALSE);
	i++;
	if (str[i] != 'x' && str[i] != 'X')
		return (FALSE);
	i++;
	while (i < 9)
	{
		if (base16check(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		return (TRUE);
	return (FALSE);
}

int			ft_checkformat(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			continue ;
		}
		if (str[i] == '-' && ft_isdigit(str[i + 1]) == FALSE)
			return (FALSE);
		if (str[i] == ',')
		{
			if (checkcolor(&str[i]) == FALSE)
				return (FALSE);
			i += 9;
		}
		else if (ft_isdigit(str[i]) == FALSE && str[i] != ' ' && str[i] != '-')
			return (FALSE);
		if (str[i] != '\0')
			i++;
	}
	return (TRUE);
}
