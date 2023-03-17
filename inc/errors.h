/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 10:55:23 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/17 10:55:25 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "minishell.h"

enum	e_mini_errors
{
	QUOTE = 10,
	NDIR = 11,
	NPERM = 12,
	NCMD = 13,
	DUPERR = 14,
	FORKERR = 15,
	PIPERR = 16,
	PIPENDERR = 17,
	MEM = 18,
	IS_DIR = 19,
	NOT_DIR = 20
};

/*					Functions list					*/

void	*das_error(int error);
int		error_unset(t_simple_cmds *simple_cmd);
int		error_export(char *c);

#endif