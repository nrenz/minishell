/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:10:30 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/06 20:14:10 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

//checks for quotes before lexer that takes our input from readline
//returns 1 if sintax incorrect, 0 if ok
int	input_quotes(char *input)
{
	int	num_single_inputuotes;
	int	num_double_inputuotes;
	int	i;

	num_single_inputuotes = 0;
	num_double_inputuotes = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '\'')
			num_single_inputuotes++;
		else if (input[i] == '\"')
			num_double_inputuotes++;
		i++;
	}
	if (num_single_inputuotes % 2 == 0 && num_double_inputuotes % 2 == 0)
		return (0);
	else
		return (1);
}

/* This is a function that takes a string "str" and a character "c", and 
** deletes any consecutive occurrences of "c" in the string. We use that
** function for deleting quotes inside the command string */
char	*deleting_quotes(char *str, char c)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			o = 0;
			while (str[i + o] == c)
				o++;
			ft_strlcpy(&str[i], &str[i + o], strlen(str) - i);
		}
		i++;
	}
	return (str);
}
