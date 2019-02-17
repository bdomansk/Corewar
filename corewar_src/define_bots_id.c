/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_bots_id.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 17:50:02 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/17 17:50:03 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	define_bots_id(t_vm *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->number_of_bots)
	{
		if (info->bot[i].id == 0)
		{
			j = 1;
			while (info->available_id[j])
				j++;
			info->available_id[j] = 1;
			info->bot[i].id = j;
		}
		i++;
	}
}