/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:11:59 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/19 15:46:59 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../inc/parser.h"
# include "lexer.h"
# include "built.h"
# include "utils.h"
# include "errors.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

/*		SIGNALS				*/


/*		INIT FUNCTIONS		*/

void	init_global_struct(char **envp);
void	run_minishell_loop(t_global *minishell);
int		find_pwd(t_global *minishell);
char	**init_envp(char **envp);

#endif
