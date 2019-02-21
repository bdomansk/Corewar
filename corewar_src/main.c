/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:47:52 by bdomansk          #+#    #+#             */
/*   Updated: 2018/10/30 17:47:54 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** while (42) == while (cycle_to_die > 0)
*/

void		temp_function(t_vm *info)
{
	int i;
	int k;

	i = -1;
	k = 0;
	while (++i < MEM_SIZE)
	{
		if (info->map[i].color != 10)
			printf("\033[92m%0.2x\033[0m ", info->map[i].cell);
		else
			printf("\033[90m00\033[0m ");
		k++;
		if (k == 64)
		{
			k = 0;
			printf("\n");
		}
	}
	printf("\n");
}

void		standart_output(t_vm *info)
{
	printf("standart output %s\n", info->bot[0].name);
}

void		visulization(t_vm *vm)
{
	visualization_init(vm);
	while (42) 
	{
		check_key(getch(), vm);
		werase(vm->w);
		werase(vm->info);
		draw_map(vm);
		draw_info_table(vm);
		wrefresh(vm->w);
		wrefresh(vm->info);
		usleep(vm->delay / vm->cycles);
	}
	delwin(vm->w);
	delwin(vm->info);
	endwin();
}

int			main(int argc, char **argv)
{
	t_vm	*vm;

	vm = init_info(argc, argv);
	parse_arguments(vm);
	define_bots_id(vm);
	fill_map(vm);
	(vm->flags->v) ? visulization(vm) : standart_output(vm);
	temp_function(vm);
	bonuses(vm);
	return (0);
}
