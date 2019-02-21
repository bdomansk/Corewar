/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 12:50:50 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/21 12:50:52 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	draw_info_table(t_vm *vm)
{
	//draw_info(vm);
	//draw_bots();
	//draw_duck();
	wattron(vm->w, COLOR_PAIR(10));
	wattron(vm->info, COLOR_PAIR(10));
	box(vm->w, 0, 0);
	box(vm->info, 0, 0);
	mvwhline(vm->info, 5 + (vm->number_of_bots * 6), 1, ACS_HLINE, 48);
	wattroff(vm->w, COLOR_PAIR(10));
	wattroff(vm->info, COLOR_PAIR(10));
}
