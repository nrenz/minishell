/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:56:10 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/13 12:01:31 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* counting pipes for parser - check it again! */
void	count_pipes(t_global *global_struct, t_token *lexer_list)
{
	t_token	*tmp;

	tmp = lexer_list;
	while (tmp)
	{
		if (tmp->tok_type == PIPE)
			global_struct->pipes++;
		tmp = tmp->next;
	}
	printf("%d", global_struct->pipes);
}

/* main for testing */
int	main(int argc, char **argv, char **envp)
{
	t_global	*global_struct;
	t_token		*lexer_list;
	t_parser_list	*parser_list;
	(void) argc;
	(void) argv;

	global_struct = (t_global *)malloc(sizeof(t_global));
	if (!global_struct)
		return (0);
	global_struct->pipes = 0;
	global_struct->envp = envp;
	lexer_list = lexer(global_struct);
	parser_list = (t_parser_list *)malloc(sizeof(t_parser_list));
	if (!parser_list)
		return (0);
	parser_list->lexer_list = lexer_list;
	parser_list->global_struct = global_struct;
	count_pipes(global_struct, lexer_list);
	return (0);
}
