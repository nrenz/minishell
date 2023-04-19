/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:54:54 by nrenz             #+#    #+#             */
/*   Updated: 2023/04/19 14:33:52 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H
# include "minishell.h"

/*						Flags				*/
# define CTRL_D_PRESSED 1

/*						Built-in utils, unset				*/

size_t	if_equal_sign(char *str);
char	**deleting_loop(char **arr, char **out, char *str);
char	**var_deleting(char **arr, char *str);

/*						Built-in utils, echo				*/

void	lines_print(int i, char **str, int out);

/*						Built-in utils, cd				*/

char	*get_path(char *str, t_global *global);
int		get_special_path(t_global *global, char *str);
void	update_env_path(t_global *global);
void	new_path(t_global *global);

/*						Built-in utils, export				*/

int		check_variable(t_global *global, char *str);
int		check_identifier(char c);
int		check_input_parameter(char *str);
char	**add_variable_loop(char **arr, char **out, char *str);

/*						Built-in utils, exit				*/

void	define_exit_code(char **str);
int		ft_strdigit(char *str);
char	**ft_arrdup(char **arr);

/*						Free utils							*/

void	ft_free_global(t_global *global);
void	ft_free_cmdlst(t_simple_cmds *simple_cmds);
void	free_arr(char **arr);

/*						Quotes utils						*/

int		input_quotes(char *input);
char	*deleting_quotes(char *str, char c);

/*						Ctrl D						*/
void	clean_up(int clean_up_code);

#endif