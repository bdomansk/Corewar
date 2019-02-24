/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_carriages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 14:02:54 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/24 14:02:56 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Если в каретке еще не сохраненна команда, а место на котором стоит каретка 
** содержит не коректную команду, то каретка передвигается на 1 шаг вперед.
** Иначе, если команда еще не записана, то записываев в каретку команду и
** количество циклов, которое картке нужно ожидать выполения команды.
** Уменьшаем количество циклов ожидания.
** Если количесвто циклов ожидания равно 0, то мы выполняем команду,
** передвигаем каретку, и убираем записаную команду из каретки.
** В этом коментарии команда употреблялась в значении opcode.  
*/

/*
** Нужно будет убрать первый иф в отдельную функцию для нормирования.
*/

void	perform_carriages(t_vm *vm)
{
	t_carriage	*start;
	int			pos;

	start = vm->carriage;
	while (vm->carriage)
	{
		pos = vm->carriage->position;
		if (!vm->carriage->exec_cmd && (vm->map[pos].cell > 16 ||
			!vm->map[pos].cell))
			vm->carriage->position = (pos + 1) % MEM_SIZE;
		else
		{
			if (!vm->carriage->exec_cmd)
			{
				vm->carriage->exec_cmd = OPCODE(vm->map[pos].cell);
				vm->carriage->cycles_left = CYCLES(vm->carriage->exec_cmd);
			}
			if (vm->carriage->cycles_left > 0)
				vm->carriage->cycles_left--;
			if (vm->carriage->cycles_left == 0)
			{
				ft_printf("Выполняем команду %d, и передвигаем каретку", vm->carriage->exec_cmd);
				vm->carriage->exec_cmd = 0;
			}
		}
		vm->carriage = vm->carriage->next;
	}
	vm->carriage = start;
}
