/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:13:15 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/19 14:15:55 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

/* Free everything from global structure */
void	ft_free_global(t_global *global)
{
	printf("\nfree global check\n");
	free(global->args);
	free(global->pwd);
	free(global->old_pwd);
	free_arr(global->paths);
	free_arr(global->envp);
	ft_free_cmdlst(global->simple_cmds);
}

/* I'm not sure about this, but i hope it's work :) */
void	ft_free_cmdlst(t_simple_cmds *simple_cmds)
{
	printf("\nfree cmdlst ckeck\n");
	t_simple_cmds	*current;
	t_simple_cmds	*next;

	current = simple_cmds;
	while (current != NULL)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}	
}

/* Simply free the array of data */
void	free_arr(char **arr)
{
	printf("\nfree array check\n");
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
