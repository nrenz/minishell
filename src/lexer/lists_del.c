/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:17:38 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/17 11:00:18 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_token	*clear_one_list(t_token **lst)
{
	if ((*lst)->str)
	{
		free((*lst)->str);
		(*lst)->str = NULL;
	}
	free(*lst);
	*lst = NULL;
	return (NULL);
}

void	delete_front_list(t_token **stack)
{
	t_token	*temp;

	temp = (*stack);
	if ((*stack) == NULL)
		return ;
	else if ((*stack) != NULL)
	{
		if ((*stack)->next == NULL)
		{
			(*stack) = NULL;
			free(temp);
			return ;
		}
		else
		{
			(*stack) = temp->next;
			(*stack)->prev = NULL;
			free(temp);
		}
	}
}

/* delete one node with index */
void	delete_one_node(t_token **token_list, int index)
{
	t_token	*node;
	t_token	*prev;
	t_token	*start;

	start = *token_list;
	node = start;
	if ((*token_list)->index == index)
	{
		delete_front_list(token_list);
		return ;
	}
	while (node && node->index != index)
	{
		prev = node;
		node = node->next;
	}
	if (node)
		prev->next = node->next;
	else
		prev->next = NULL;
	if (prev->next)
		prev->next->prev = prev;
	clear_one_list(&node);
	*token_list = start;
}
