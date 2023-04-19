/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:18:07 by hboichuk          #+#    #+#             */
/*   Updated: 2023/04/19 11:34:44 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//start programm with loop
void	run_minishell_loop(t_global *minishell)
{
	// printf("Here is first line - %s", minishell->args);
		
	while (1)
	{
		minishell->args = readline("Hi, it's Minihell!...");
		//history?
		//quotes
		lexer(minishell);
		parser(minishell);
		//expander
		//executor
		//reset?
		
		// printf("Here is first line - %s", minishell->args);
		// printf("\n");
	}
	
	// printf("Here is first line - %s", minishell->args);
}

//init for global struct
void	init_global_struct(char **envp)
{
	t_global	*minishell;

	minishell = (t_global *)ft_calloc(1, sizeof(t_global));
	minishell->lexer_list = NULL;
	// hardcode
	minishell->pipes = 2;
	//implemantation for simple cmd?
	// paths;??
	minishell->envp = init_envp(envp);
	find_pwd(minishell);
	minishell->pid = NULL;
	run_minishell_loop(minishell);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc == 1 || argv[1])
	{
		init_global_struct(envp);
		printf("Welcome to Minishell!");
	}
	else
	{
		printf("Minishell doesn't need arguments!");
		exit(0);
	}
	return (0);
}
