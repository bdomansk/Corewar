/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:40:05 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/01 12:40:07 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Если для конкретной операции нужен код типов аргументов, то находим его
** и записываем в каретку, проверяем подходит ли полученный код к операции.
** Проверяем все существующее регистры (T_REG) на валидность.
** Eсли где-то произошла ошибка возвращаем 0, иначе в конце вернем 1.
*/

extern const t_operations g_operations[16];

static int	find_type(unsigned char code)
{
	if (code == REG_CODE)
		return (T_REG);
	else if (code == DIR_CODE)
		return (T_DIR);
	else if (code == IND_CODE)
		return (T_IND);
	return (0);
}

static void	read_code_type(t_vm *vm, t_carriage *carriage)
{
	unsigned char	code_type;
	int				number_of_arguments;

	code_type = get_arg_from_map(vm->map, carriage->position, 1);
	number_of_arguments = NUMBER_ARGS(carriage->opcode);
	carriage->arg_type[0] = find_type((code_type >> 6) & 3);
	if (number_of_arguments > 1)
		carriage->arg_type[1] = find_type((code_type >> 4) & 3);
	if (number_of_arguments > 2)
		carriage->arg_type[2] = find_type((code_type >> 2) & 3);
}

int			check_code_type(t_vm *vm, t_carriage *carriage)
{
	(void)vm;
	if (CODE_TYPE(carriage->opcode))
	{
		carriage->position = (carriage->position + 1) % MEM_SIZE;
		read_code_type(vm, carriage);
	}
	//else
	//	fill_arguments(carriage);
	return (1);
}
