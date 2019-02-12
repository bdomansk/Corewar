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
	flags->exists = 0;
	return (flags);
}

static void		check_flags(t_vm *info, char *s)
{
	int i;

	if (s[0] == '-')
	{
		i = 1;
		while (s[i])
		{
			if (!ft_strchr("hlcvm", (int)s[i]))
			{
				info->error_reason = ft_strjoin("wrong flags : ", s);
				put_manual(info);
			}
			info->flags->h = (s[i] == 'h') ? 1 : info->flags->h;
			info->flags->l = (s[i] == 'l') ? 1 : info->flags->l;
			info->flags->c = (s[i] == 'c') ? 1 : info->flags->c;
			info->flags->v = (s[i] == 'v') ? 1 : info->flags->v;
			info->flags->m = (s[i] == 'm') ? 1 : info->flags->m;
			i++;
		}
		info->flags->exists = 1;
	}
}

t_vm			*init_info(int argc, char **argv)
{
	t_vm	*info;
	int		players;

	info = (t_vm*)malloc(sizeof(t_vm));
	info->flags = init_flags();
	info->error_reason = NULL;
	if (argc > 1)
		check_flags(info, argv[1]);
	players = argc - info->flags->exists - 1;
	if (players > MAX_PLAYERS)
		info->error_reason = "The number of players is more than MAX_PLAYERS";
	if (info->flags->h || players > MAX_PLAYERS || players < 1)
		put_manual(info);
	info->prog_size = 0;
	return (info);
}
