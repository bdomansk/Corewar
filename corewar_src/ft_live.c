/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:10:59 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/25 17:11:00 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Следующие 50 циклов ячейка, которая содержит код данной операции
** будет выделена следующим способом: фон — цвет от каретки, которая выполнила
** данную операцию; содержимое ячейки будет окрашено в белый цвет
** и выделено жирным.
** https://github.com/VBrazhnik/Corewar/wiki
*/

extern const t_operations g_operations[16];

static void	live_bot(t_vm *vm, int i)
{
	vm->last_live_bot = &vm->bot[i];
	vm->bot[i].lives_current_period++;
	vm->bot[i].cycle_last_live = vm->current_cycle;
	if (vm->flags->lives && !vm->flags->v)
		ft_printf("Вывести информацию про live бота\n");
}

void		ft_live(t_vm *vm, t_carriage *carriage)
{
	int	argument;
	int	i;
	int	size;

	carriage->alive = 1;
	vm->number_of_lives++;
	size = SIZE_DIR(carriage->opcode);
	argument = (int)get_arg_from_map(vm->map, carriage->position + 1, size);
	i = 0;
	while (i < vm->number_of_bots)
	{
		if (argument == -vm->bot[i].id)
		{
			live_bot(vm, i);
			break ;
		}
		i++;
	}
	if (vm->flags->v)
		ft_printf("Визуализация для live, смотри коммент\n");
	move_carriage(carriage);
}
