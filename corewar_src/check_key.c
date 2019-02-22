/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:43:09 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/21 11:43:10 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Нужно добавить выключение музыки на vm->music_init && ch == 'm'
*/

int		check_key(int ch, t_vm *vm)
{
	int cycles;

	cycles = vm->cycles;
	if (ch == 'q')
		vm->cycles = ((cycles + 100) > 1000) ? 1000 : cycles + 100;
	if (ch == 'w')
		vm->cycles = ((cycles + 10) > 1000) ? 1000 : cycles + 10;
	if (ch == 'e')
		vm->cycles = ((cycles + 1) > 1000) ? 1000 : cycles + 1;
	if (ch == 'y')
		vm->cycles = ((cycles - 100) < 1) ? 1 : cycles - 100;
	if (ch == 't')
		vm->cycles = ((cycles - 10) < 1) ? 1 : cycles - 10;
	if (ch == 'r')
		vm->cycles = ((cycles - 1) < 1) ? 1 : cycles - 1;
	if (ch == 'd')
		vm->cycles = 10;
	if (vm->running && ch == ' ')
		npause(vm);
	if (!vm->music_init && ch == 'm')
		sdl_mixer_init(vm);
	return (ch);
}
