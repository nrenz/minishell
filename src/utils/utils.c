/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:23:42 by ddzuba            #+#    #+#             */
/*   Updated: 2023/02/25 14:49:20 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

/* Checks string for digits */
int	ft_strdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* Duplicates an array. Same shit as strdup */
char	**ft_arrdup(char **arr)
{
	char	**dup;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	dup = ft_calloc(sizeof(char *), i + 1);
	if (!dup)
		return (0);
	while (arr[i] != NULL)
	{
		dup[i] = ft_strdup(arr[i]);
		if (dup[i] == NULL)
		{
			free_arr(dup);
			return (dup);
		}
		i++;
	}
	return (dup);
}
