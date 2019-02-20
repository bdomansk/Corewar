/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_carriage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:57:09 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/19 15:57:10 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	new_carriage(t_vm *info, t_bot parent, int position)
{
	t_carriage *new;

	if (!(new = malloc(sizeof(t_carriage))))
		error_reason(info, "Memory was not allocated");
	info->num_of_carriages++;
	new->id = info->num_of_carriages;
	new->position = position;
	new->carry = 0;
	new->alive = 0;
	new->exec_command = 0;
	new->number_cycle = 0;
	new->parent = parent;
	new->register_id[1] = -parent.id;
	new->next = NULL;
	if (info->carriage)
		new->next = info->carriage;
	info->carriage = new;
}
