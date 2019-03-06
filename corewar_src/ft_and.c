/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 13:50:55 by bdomansk          #+#    #+#             */
/*   Updated: 2019/03/05 13:50:56 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_and(t_vm *vm, t_carriage *carriage)
{
	int	argument1;
	int	argument2;
	//int	argument3;

	argument1 = get_arg_by_type(vm, carriage, 0);
	argument2 = get_arg_by_type(vm, carriage, 1);
	if (!vm->flags->v)
		ft_printf("P %4d | and %d %d arg3\n",
		carriage->id, argument1, argument2);
	move_carriage(vm, carriage);
}