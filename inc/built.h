/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:55:11 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/17 10:55:17 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

# include <dirent.h>
# include "minishell.h"
# include "parser.h"
/* dirent.h keeps inside everything for working with DIR. As closedir,
** opendir, *readdir, etc */

/*                      Functions list                      */

int	(*built_arr(char *str))(t_global *global, t_simple_cmds *simple_cmd);
int	ft_echo(t_global *global, t_simple_cmds *simple_cmd);
int	ft_pwd(t_global *global, t_simple_cmds *simple_cmd);
int	ft_exit(t_global *global, t_simple_cmds *simple_cmd);
int	ft_env(t_global *global, t_simple_cmds *simple_cmd);
int	ft_unset(t_global *global, t_simple_cmds *simple_cmd);
int	ft_export(t_global *global, t_simple_cmds *simple_cmd);
int	ft_cd(t_global *global, t_simple_cmds *simple_cmd);

#endif