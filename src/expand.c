/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:59:53 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/17 12:01:37 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//this function separetes our variable from $ sign
//getenv takes input only as a key without a sign, so this is needed
//returns new allocated string without a dollar sign 
char	*separ_from_dollar(char *key)
{
	int		i;
	int		j;
	char	*new_key;

	i = 0;
	j = 1;
	new_key = malloc(sizeof(char) * strlen(key));
	if (!new_key)
		return (NULL);
	while (key[j])
	{
		new_key[i] = key[j];
		i++;
		j++;
	}
	return (new_key);
}

//expands environment variables that start with $ sign
//to their values and returns it, otherwise returns NULL
char	*ft_expand(char *key)
{
	char	*temp;
	char	*no_sign;

	no_sign = separ_from_dollar(key);
	temp = getenv(no_sign);
	free(no_sign);
	if (temp == NULL)
		return (NULL);
		return (temp);
}

// int main(void)
// {
//     char *a = malloc(sizeof(char) * 100);
//     a = "$HOME";
//     printf("%s\n", ft_expand(a));
//     return(0); 
// }