/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:11:19 by hboichuk          #+#    #+#             */
/*   Updated: 2023/03/17 11:01:10 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_simple_cmds	*create_one_cmd(char **str)
{
	t_simple_cmds	*cmd;

	cmd = (t_simple_cmds *)malloc(sizeof(t_simple_cmds));
	if (!cmd)
		return (0);
	cmd->str = str;
	cmd->builtin = NULL;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

/* count args before PIPE */
int	count_args(t_token	*token_list)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = token_list;
	while (tmp && tmp->tok_type != PIPE)
	{
		if (tmp->index >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

/* allocate and create one simple cmd */
t_simple_cmds	*init_one_cmd(t_parser_list *parser_list)
{
	char	**str;
	int		i;
	int		size;
	t_token	*tmp;

	i = 0;
	size = count_args(parser_list->lexer_list);
	str = ft_calloc(size + 1, sizeof(char *));
	if (!str)
		printf("Can't allocate cmd!");
	tmp = parser_list->lexer_list;
	while (size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			delete_one_node(&parser_list->lexer_list, tmp->index);
			tmp = parser_list->lexer_list;
		}
		size--;
	}
	return (create_one_cmd(str));
}

/* just init for parser struct */
t_parser_list	init_parser_list(t_token *lexer_list, t_global *global)
{
	t_parser_list	parser_list;

	parser_list.lexer_list = lexer_list;
	//redirections
	parser_list.global = global;
	return (parser_list);
}

/* main func for parser */
int	parser(t_global *global_struct)
{
	t_simple_cmds	*one_cmd;
	t_parser_list	parser_list;

	global_struct->simple_cmds = NULL;
	count_pipes(global_struct, global_struct->lexer_list); //why i don't see result?
	while (global_struct->lexer_list)
	{
		//do we need delete one node before creating?
		//we should handle quote and pipe errors
		parser_list = init_parser_list(global_struct->lexer_list, global_struct);
		one_cmd = init_one_cmd(&parser_list);
		if (!one_cmd)
			printf("Error! Can't init 1 cmd!");
		global_struct->lexer_list = parser_list.lexer_list;
	}
	return (0);
}
