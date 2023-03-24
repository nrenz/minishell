/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 22:16:50 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/24 14:22:00 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "parser.h"
# include "minishell.h"

/* Tokens types */
# define WORD 1		   // "Hello World"
# define PIPE 2		   // "|"
# define GREATER_THAN 3 // >
# define LESS_THAN 4	// <
# define DOUBLE_QUOTE 5	// " "
# define SINGLE_QUOTE 6	// ' '
# define HEREDOC 7	   // <<
# define EXPANSION 8	// $
# define MINI_FILE 9	// .txt
# define SPACE 10

typedef struct s_global	t_global;

typedef struct s_token
{
	int				tok_type;
	char			*str;
	int				index;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_lexer
{
	int				i;
	char			*str;
	t_token			*token;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}		t_lexer;

/*						Lexer functions						*/

void	get_type_tok(t_token *token_arr);
char	**split_arguments(char *string);
t_token	*lexer(t_global *global);
t_token	*clear_one_list(t_token **lst);
void	delete_front_list(t_token **stack);
void	delete_one_node(t_token **token_list, int index);
t_token	*create_new_list(char *data, int index);
t_token	*fill_stack_tokens(char **argv, t_token *token_list);

#endif