/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:14:23 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/08 16:14:26 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error(t_asm *info)
{
	if (info->flags->m)
		system("afplay music/fail-trombone.mp3&");
	if (info->flags->c)
		ft_printf("%s", RED);
	if (info->flags->e)
		ft_printf("ERROR: %s\n", info->error_reason);
	else
		ft_printf("ERROR\n");
	if (info->flags->c)
		ft_printf("%s", DEF);
	if (!info->flags->h)
	{
		if (info->flags->l)
			system("leaks asm");
		exit(1);
	}
}
