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

#include "asm.h"

int	main(int argc, char **argv)
{
	t_asm	*info;

	info = init_info(argc, argv);
	check_file_name(info);
	//тут нужно добавить выбор для флага -d
	check_name_and_comment(info);
	bonuses(info);
	return (0);
}
