/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:57:18 by bdomansk          #+#    #+#             */
/*   Updated: 2018/11/08 13:57:21 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	bonuses(t_asm *info)
{
	if (info->flags->l)
		system("leaks asm");
	if (info->flags->m)
		system("killall afplay");
}
