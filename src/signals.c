/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:49:09 by nrenz             #+#    #+#             */
/*   Updated: 2023/04/19 15:53:34 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*	SIGQUIT should do nothing */
void	signal_handler(int sig, t_global *global, void *context)
{
	if (sig == SIGINT)
		printf("Upps, did you hit Ctrl-C?\n");
	(void) context;
	(void) *global;
	exit(0);
}
