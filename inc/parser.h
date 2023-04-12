/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:53:06 by ddzuba            #+#    #+#             */
/*   Updated: 2023/04/11 12:57:44 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../inc/minishell.h"
# include "../inc/lexer.h"
# include <stdbool.h>

typedef struct s_global
{
	struct s_simple_cmds	*simple_cmds;
	t_token					*lexer_list;
	char					*args;
	char					**paths;
	char					**envp;
	char					*pwd;
	char					*old_pwd;
	int						pipes;
	int						*pid;
	bool					heredoc;
	bool					reset;
}	t_global;

typedef struct s_simple_cmds
{
	char						**str;
	int							redirect_count;
	char						*hd_file_name;
	int							(*builtin)(t_global *, struct s_simple_cmds *);
	struct s_simple_cmds		*next;
	struct s_simple_cmds		*prev;
}		t_simple_cmds;

/* t_token = t_lexer from example */
typedef struct s_parser_list
{
	struct s_global	*global_struct;
	struct s_global	*global;
	t_token			*lexer_list;
	t_token			*redirections;
	int				num_redirections;
}	t_parser_list;

/*						Parser functions						*/

t_simple_cmds	*create_one_cmd(char **str);
t_simple_cmds	*init_one_cmd(t_parser_list *parser_list);
t_parser_list	init_parser_list(t_token *lexer_list, t_global *global);
int				count_args(t_token	*token_list);
int				parser(t_global *global_struct);
void			count_pipes(t_global *global_struct, t_token *lexer_list);

#endif