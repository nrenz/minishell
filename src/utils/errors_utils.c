/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:44:42 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/05 16:01:03 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/errors.h"

int	das_error(int error) //, t_global *global this was a second argument
{
	ft_putstr_fd("42minishell:", STDERR_FILENO);
	if (error == QUOTE)
		ft_putstr_fd("42minishell: error with matching quotes!\n", 2);
	else if (error == NDIR)
		ft_putstr_fd("42minishell: no such file or directory!\n", 2);
	else if (error == NPERM)
		ft_putstr_fd("42minishell: permission denied!\n", 2);
	else if (error == NCMD)
		ft_putstr_fd("42minishell: wrong command or command not found!\n", 2);
	else if (error == DUPERR)
		ft_putstr_fd("42minishell: duplication failed!\n", 2);
	else if (error == FORKERR)
		ft_putstr_fd("42minishell: fork creation failed!\n", 2);
	else if (error == PIPERR)
		ft_putstr_fd("42minishell: pipe creation failed!\n", 2);
	else if (error == PIPENDERR)
		ft_putstr_fd("42minishell: error near unexpected token `|'!\n", 2);
	else if (error == MEM)
		ft_putstr_fd("42minishell: no memory left on PC or memory error!\n", 2);
	else if (error == IS_DIR)
		ft_putstr_fd("42minishell: this is a directory!\n", 2);
	else if (error == NOT_DIR)
		ft_putstr_fd("42minishell: this is not a directory!\n", 2);
	// reset_global(global);
	return (EXIT_FAILURE);
}

/* Error handler for unset */
int	error_unset(t_simple_cmds *simple_cmd)
{
	int	i;

	i = 0;
	if (!simple_cmd->str[1])
	{
		ft_putendl_fd("42minishlell: unset: not enough arguments!\n", 2);
		return (EXIT_FAILURE);
	}
	while (simple_cmd->str[1][i])
	{
		if (simple_cmd->str[1][i++] == '/')
		{
			ft_putendl_fd("42minishell: unset: '", 2);
			ft_putendl_fd(simple_cmd->str[1], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			return (EXIT_FAILURE);
		}
	}
	if (if_equal_sign(simple_cmd->str[1]) != 0)
	{
		ft_putendl_fd("42minishell: unset: not a valid identifier", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/* Error handler for export */
int	error_export(char *c)
{
	ft_putstr_fd("42minishell: export: ", 2);
	if (c)
	{
		ft_putchar_fd('\'', 2);
		ft_putstr_fd(c, 2);
		ft_putstr_fd("\': is ", 2);
	}
	ft_putendl_fd("not a valid identifier!\n", 2);
	return (EXIT_FAILURE);
}

// need to continue error managment, keep writing about tokens and else