/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_manual.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:59:44 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 10:59:46 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	put_manual(t_vm *info)
{
	info->flags->h = 1;
	if (info->error_reason)
		error(info);
	if (info->flags->c)
		ft_printf("%s", AQUAMARINE);
	ft_printf("usage:	./coreawar [-helcdm] champ1.cor champ2.cor ...\n\
	-h see the usage\n\
	-m turn on musical accompaniment\n\
	-l show leaks\n\
	-c enable colors\n\
	-v enable visualization\n");
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (info->flags->l)
		system("leaks corewar");
	exit(0);
}
