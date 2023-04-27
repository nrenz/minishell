/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:18:07 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/27 10:30:49 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//start programm with loop
void	run_minishell_loop(t_global *minishell)
{	
	while (1)
	{
		minishell->args = readline("\nrenz_prompt: ");
		if (minishell->args)
			add_history(minishell->args);
		if (!minishell->args)
			clean_up(CTRL_D_PRESSED);
		lexer(minishell);
		parser(minishell);
		//expander
		//executor
		//reset?
	}
}

//init for global struct
void	init_global_struct(char **envp)
{
	t_global	*minishell;

	minishell = (t_global *)ft_calloc(1, sizeof(t_global));
	minishell->lexer_list = NULL;
	minishell->pipes = 2;
	minishell->envp = init_envp(envp);
	find_pwd(minishell);
	minishell->pid = NULL;
	printf("Welcome to our own Minishell!");
	run_minishell_loop(minishell);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1 || argv[1])
		init_global_struct(envp);
	else
	{
		printf("Minishell doesn't need arguments!");
		exit(0);
	}
	return (0);
}
