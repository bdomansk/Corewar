/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_carriage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:03:08 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/03 15:03:09 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

extern const t_operations g_operations[16];

void	move_carriage(t_carriage *carriage)
{
	int	new_position;
	int i;

	new_position = carriage->position + 1;
	i = 0;
	while (i < carriage->number_of_arguments)
	{
		new_position = new_position + get_size_by_type(carriage, i);
		i++;
	}
	carriage->position = new_position % MEM_SIZE;
}
