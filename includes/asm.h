/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:45:25 by bdomansk          #+#    #+#             */
/*   Updated: 2018/10/30 17:45:36 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "op.h"

typedef struct	s_flags
{
	int	h;
	int l;
	int	c;
	int d;
	int	m;
	int exists;
}				t_flags;

typedef struct	s_lines
{
	char			*line;
	struct s_lines	*next;
}				t_lines;

typedef struct	s_asm
{
	t_flags		*flags;
	t_lines		*lines;
	char		*error_reason;
	char		*file_name;
	char		*new_file_name;
	int			fd;
}				t_asm;

t_asm			*init_info(int argc, char **argv);
void			put_manual(t_asm *info);
void			error(t_asm *info);

void			check_file_name(t_asm *info);

void			bonuses(t_asm *info);

#endif
