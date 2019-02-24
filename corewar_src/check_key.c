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
** Нужно будет поменять как работает пауза в музыке
** Чтобы при паузе было коректное отображение и песня не начинала играть
** заново , а с того же места. если музыка включенна, то vm->musice != NULL
** если нажата m нужно делать отденьную функцию, потому что уже > 25  строк
** нужно на esc сразу выходить, потому что на паузе ретурн 0 не сработает
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
	else if (vm->music_init && ch == 'm')
	{
		vm->music_init = 0;
		Mix_FreeMusic(vm->music);
		Mix_CloseAudio();
	}
	if (ch == 27)
		return (0);
	return (ch);
}
