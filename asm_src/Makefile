# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 11:55:49 by bdomansk          #+#    #+#              #
#    Updated: 2018/04/23 11:55:51 by bdomansk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm
LIB = ../libft/libft.a
LIBDIR = ../libft
FLAGS = -Wall -Wextra -Werror
ASM_SRC = main.c bonuses.c init_info.c put_manual.c error.c
ASM_OBJ = $(ASM_SRC:.c=.o)
HEADER = -I ../includes
DEL = /bin/rm -f

.PHONY : all clean n fclean re

all : $(NAME)

$(NAME) : $(LIB) $(ASM_OBJ) 
	@echo "Compiling asm"
	@gcc $(FLAGS) $(ASM_OBJ) -o $(NAME) $(LIB)

$(ASM_OBJ): $(ASM_SRC)
	@echo "Asm objects creating"
	@gcc $(FLAGS) -c $(ASM_SRC) $(HEADER)

$(LIB) :
	@make -C $(LIBDIR)

clean:
	@$(DEL) $(ASM_OBJ)

n :
	@norminette $(ASM_SRC) 

fclean:
	@$(DEL) $(ASM_OBJ)
	@$(DEL) $(NAME)
	
re: fclean all
