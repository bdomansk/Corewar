/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:40:27 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 10:40:29 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->h = 0;
	flags->l = 0;
	flags->c = 0;
	flags->v = 0;
	flags->m = 0;
	flags->s = 0;
	flags->dump = 0;
	flags->dump_value = 0;
	return (flags);
}

static void		init_available_ids(t_vm *info)
{
	int i;

	i = 0;
	while (i < 5)
	{
		info->available_id[i] = 0;
		i++;
	}
}

t_vm			*init_info(int argc, char **argv)
{
	t_vm	*info;

	info = (t_vm*)malloc(sizeof(t_vm));
	info->flags = init_flags();
	init_available_ids(info);
	info->number_of_bots = 0;
	info->error_reason = NULL;
	info->detalization_level = 0;
	info->i = 0;
	info->argc = argc;
	info->argv = argv;
	return (info);
}
