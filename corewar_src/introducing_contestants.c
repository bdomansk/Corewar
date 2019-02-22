/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introducing_contestants.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:14:35 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/22 15:14:36 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	introducing_contestants(t_vm *vm)
{
	t_bot	bot;
	int		i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < vm->number_of_bots)
	{
		bot = vm->bot[i];
		ft_printf("* Player %d, weighing %u bytes, \"%s\" (\"%s\") !\n",
		bot.id, bot.prog_size, bot.name, bot.comment);
		i++;
	}
}
