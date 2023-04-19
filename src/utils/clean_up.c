/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:30:00 by nrenz             #+#    #+#             */
/*   Updated: 2023/04/19 14:35:43 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

void	clean_up(int clean_up_code)
{
	if (clean_up_code == CTRL_D_PRESSED) 
		exit(0); //should we use rrl_clear_history here to free history? maybe we can check with valgrind? please correct me if i dont understand (nick)
}