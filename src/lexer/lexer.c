/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:20:18 by hboichuk          #+#    #+#             */
/*   Updated: 2023/03/17 11:45:45 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
#include "../inc/parser.h"

/* give type of token */
void	get_type_tok(t_token *token_arr)
{
	while (token_arr->next != NULL)
	{
		if (token_arr->str[0] == '|' && ft_strlen(token_arr->str) == 1)
			token_arr->tok_type = PIPE;
		else if (token_arr->str[0] == '>' && ft_strlen(token_arr->str) == 1)
			token_arr->tok_type = LESS_THAN;
		else if (token_arr->str[0] == '<' && ft_strlen(token_arr->str) == 1)
			token_arr->tok_type = GREATER_THAN;
		else if (token_arr->str[0] == '>' && ft_strlen(token_arr->str) == 1)
			token_arr->tok_type = LESS_THAN;
		else if ((token_arr->str[0] >= 33 && token_arr->str[0] <= 59) ||
		token_arr->str[0] == 61 ||
				(token_arr->str[0] >= 63 && token_arr->str[0] <= 126))
			token_arr->tok_type = WORD;
		else
			token_arr->tok_type = SPACE;
		token_arr = token_arr->next;
	}
}

/* split of line with arguments */
char	**split_arguments(char *string)
{
	char	*cutted_str;
	char	**tok_arr;

	cutted_str = ft_strtrim(string, " ");
	free(string);
	string = cutted_str;
	if (!string)
	{
		printf("nothing in line!");
		exit(0);
	}
	tok_arr = ft_split(cutted_str, ' ');
	return (tok_arr);
}

/* we needs error_handler for lexer and so on
   main func for lexer
*/
t_token	*lexer(t_global *global)
{
	char	**arguments;
	// int	i;
	t_token *token_list;

	// i = 0;
	token_list = global->lexer_list;
	arguments = split_arguments(global->args);
	//test
	// while (arguments[i])
	// {
	// 	printf("%s", arguments[i]);
	// 	printf("\n");
	// 	i++;
	// }
	if (!arguments)
	{
		printf("can't split arguments");
	}
	token_list = fill_stack_tokens(arguments, token_list);
	get_type_tok(token_list);
	//test
	// while (token_list->next != NULL)
	// {
	// 	printf("%s, %d, %d", token_list->str, token_list->index, token_list->tok_type);
	// 	printf("\n");
	// 	token_list = token_list->next;
	// 	i++;
	// }
	return (token_list);
}
