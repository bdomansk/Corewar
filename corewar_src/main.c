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

int			main(int argc, char **argv)
{
	t_vm	*info;

	info = init_info(argc, argv);
	parse_arguments(info);
	define_bots_id(info);
	fill_map(info);
	temp_function(info);
	bonuses(info);
	return (0);
}
