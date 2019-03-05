/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_period.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 17:23:16 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/05 17:23:18 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	find_max(t_vm *vm)
{
	int i;
	int max;

	max = 0;
	i = -1;
	while (++i < vm->number_of_bots)
	{
		if (vm->bot[max].lives_current_period < vm->bot[i].lives_current_period)
			max = i;
	}
	return (max);
}

static void	draw_draw_period(t_vm *vm, float percent[], int n)
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

void		draw_period(t_vm *vm)
{
	int		n;
	int		i;
	int		sum;
	float	percent[4];

	n = (vm->number_of_bots * 6) + 2;
	sum = vm->number_of_lives;
	i = -1;
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
