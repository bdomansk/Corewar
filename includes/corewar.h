/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:32:46 by bdomansk          #+#    #+#             */
/*   Updated: 2019/02/12 10:32:57 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "op.h"
# include <stdio.h> //потом убрать

typedef struct	s_flags
{
	int	h;
	int l;
	int	c;
	int v;
	int	m;
	int exists;
}				t_flags;

typedef struct	s_vm
{
	t_flags			*flags;
	unsigned int	prog_size;
	char			*error_reason;
}				t_vm;

t_vm			*init_info(int argc, char **argv);
void			put_manual(t_vm *info);
void			error(t_vm *info);
void			error_reason(t_vm *info, char *reason);
void			bonuses(t_vm *info);



#endif
