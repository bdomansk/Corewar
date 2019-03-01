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
** Если в каретке еще не сохраненн код операции, а место на котором стоит
** каретка содержит некоректный код, то каретка передвигается на 1 шаг вперед.
** Иначе, если код еще не записан, то записываев в каретку новый код и
** количество циклов, которое картке нужно ожидать для выполения операции.
** Уменьшаем количество циклов ожидания.
** Если количесвто циклов ожидания равно 0, то выполняем проверку :
** если кодировка типа аргументов подходит под описание операции, а также
** если среди аргументов операции есть регистр (T_REG) и он валидный, то мы
** выполняем операцию и передвигаем каретку;
** Иначе передвигаем каретку на размер указаный в коде типов аргументов, а
** также на сам код типов аргументов и код операции.
** Убираем записанный код из каретки.
** В этом коментарии код употреблялась в значении кода операции (opcode).
*/

extern const t_operations g_operations[16];

static void	perform_carriage(t_carriage *carr, t_vm *vm)
{
	int			pos;

	pos = carr->position;
	if (!carr->opcode && (vm->map[pos].cell > 16 || !vm->map[pos].cell))
		carr->position = (pos + 1) % MEM_SIZE;
	else
	{
		if (!carr->opcode)
		{
			carr->opcode = OPCODE(vm->map[pos].cell);
			carr->cycles_left = CYCLES(carr->opcode);
		}
		if (carr->cycles_left > 0)
			carr->cycles_left--;
		if (carr->cycles_left == 0 && check_code_type(vm, carr))
		{
			if (check_code_type(vm, carr))
			{
				ft_printf("Выпол. cmd%d, двигаем каретку\n", carr->opcode);
				g_operations[carr->opcode - 1].function(vm, carr);
			}
			else
				ft_printf("Двигаем каретку на значение кодировки типов\n");
			carr->opcode = 0;
		}
	}
}

void		perform_carriages(t_vm *vm)
{
	t_carriage	*start;

	start = vm->carriage;
	while (vm->carriage)
	{
		perform_carriage(vm->carriage, vm);
		vm->carriage = vm->carriage->next;
	}
	vm->carriage = start;
}
