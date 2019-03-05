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

/*
** в draw_info, draw_bots данные будут меняться
*/

static void	draw_bots(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->number_of_bots)
	{
		wattron(vm->info, COLOR_PAIR(vm->bot[i].id));
		mvwprintw(vm->info, 7 + (i * 5), 3, "Champ : %s\n", vm->bot[i].name);
		wattroff(vm->info, COLOR_PAIR(vm->bot[i].id));
		mvwprintw(vm->info, 7 + (i * 5) + 1, 5, "Lives\t\t%d\n", vm->bot[i].lives_current_period);
		mvwprintw(vm->info, 7 + (i * 5) + 2, 5, "Last live\t\t%d\n", vm->bot[i].cycle_last_live);
		i++;
	}
}

static void	draw_duck(t_vm *vm)
{
	wattron(vm->info, COLOR_PAIR(1));
	mvwprintw(vm->info, 62, 1, "      _\n");
	mvwprintw(vm->info, 63, 1, "  .__(.)<");
	mvwprintw(vm->info, 64, 1, "  \\___)   \n");
	wattroff(vm->info, COLOR_PAIR(1));
	mvwprintw(vm->info, 63, 10, " (MAY THE FORCE BE WHITH YOU)");
}

static void	draw_run(t_vm *vm)
{
	if (vm->running)
	{
		wattron(vm->info, COLOR_PAIR(2));
		mvwprintw(vm->info, 1, 3, "RUNING\n");
		if (vm->music_init == 1)
			mvwprintw(vm->info, 1, 30, "MUSIC: Play\n");
		wattroff(vm->info, COLOR_PAIR(2));
		if (vm->music == NULL)
			mvwprintw(vm->info, 1, 30, "MUSIC: OFF\n");
		wattron(vm->info, COLOR_PAIR(4));
		wattron(vm->info, A_BLINK);
		if (!vm->music_init && vm->music)
			mvwprintw(vm->info, 1, 30, "MUSIC: Stoped\n");
		wattroff(vm->info, COLOR_PAIR(4));
		wattroff(vm->info, A_BLINK);
	}
}

static void	draw_info(t_vm *vm)
{
	int n;

	n = (vm->number_of_bots * 6) + 2;
	draw_run(vm);
	mvwprintw(vm->info, 3, 3, "Cycles/second : %d\n", vm->cycles_in_second);
	mvwprintw(vm->info, 5, 3, "Current cycle : %d\n", vm->current_cycle);
	mvwprintw(vm->info, 58, 3, "Q : +100\tW : +10\t\tE : +1\n");
	mvwprintw(vm->info, 59, 3, "R : -1\tT : -10\t\tY : -100\n");
	mvwprintw(vm->info, n + 15, 3, "CYCLE_TO_DIE\t\t%d\n", vm->cycle_to_die);
	mvwprintw(vm->info, n + 2 + 15, 3, "CYCLE_DELTA\t\t%d\n", CYCLE_DELTA);
	mvwprintw(vm->info, n + 4 + 15, 3, "NBR_LIVE\t\t%d\n", NBR_LIVE);
	mvwprintw(vm->info, n + 6 + 15, 3, "MAX_CHECKS\t\t%d\n", MAX_CHECKS);
	mvwprintw(vm->info, n + 2, 4, "Current period :");
	mvwprintw(vm->info, n + 5, 4, "Last period :");
	wattron(vm->info, COLOR_PAIR(40));
	mvwprintw(vm->info, n + 3, 4, "==================================================");
	mvwprintw(vm->info, n + 6, 4, "==================================================");
	wattroff(vm->info, COLOR_PAIR(40));
}

int find_max(t_vm *vm)
{
	int i = -1;
	int max;

	max = 0;
	while (++i < vm->number_of_bots)
	{
		if (vm->bot[max].lives_current_period < vm->bot[i].lives_current_period)
			max = i;
	}
	return (max);
}

void	draw_draw_period(t_vm *vm, float percent[], int n)
{
	int percent_sum;
	int max;
	int i;
	int j;

	percent_sum = percent[0] + percent[1] + percent[2] + percent[3];
	max = find_max(vm);
	percent[max] += 50 - percent_sum;
	i = -1;
	j = 0;
	while (++i < vm->number_of_bots)
	{
		while (percent[i]--)
  		{
   			wattron(vm->info, COLOR_PAIR(vm->bot[i].id + 30));
   			mvwprintw(vm->info, n + 3, 4 + j, " ");
   			wattroff(vm->info, COLOR_PAIR(vm->bot[i].id + 30));
   			j++;
  		}
	}
}

void	draw_period(t_vm *vm)
{
	int n = (vm->number_of_bots * 6) + 2;
	int i = -1;
	int sum = vm->number_of_lives;
	float percent[4];
	
	if (sum)
	{
		while (++i < vm->number_of_bots)
		{
			percent[i] = (vm->bot[i].lives_current_period * 100) / sum;
			percent[i] = (int)((50 * percent[i]) / 100);
			if (!(int)percent[i] && vm->bot[i].lives_current_period)
				percent[i] = 1;
		}
		draw_draw_period(vm, percent, n);
	}
}

void		draw_info_table(t_vm *vm)
{
	draw_info(vm);
	draw_bots(vm);
	draw_duck(vm);
	draw_period(vm);
	wattron(vm->w, COLOR_PAIR(10));
	wattron(vm->info, COLOR_PAIR(10));
	box(vm->w, 0, 0);
	box(vm->info, 0, 0);
	mvwhline(vm->info, 5 + (vm->number_of_bots * 6) + 8, 1, ACS_HLINE, 58);
	wattroff(vm->w, COLOR_PAIR(10));
	wattroff(vm->info, COLOR_PAIR(10));
}