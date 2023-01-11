# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 16:46:00 by oezzaou           #+#    #+#              #
#    Updated: 2023/01/11 23:11:09 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := push_swap
SRC := push_swap.c push_swap_utils.c
LIB := libft/
INC := -Ipush_swap.h -I$(LIB)
CC := gcc
RM := rm -rf
CFLAGS := -Wall -Wextra -Werror
OBJ := $(SRC:.o=.c)
GREEN := \033[1;32m
RED := \033[1;31m
CYAN := \033[1;36m
NOCLR := \033[1;0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)COMPILING ...$(NOCLR)"
	@make -C $(LIB) all
	@$(CC) $(CFLAGS) $(INC) $^ $(LIB)*.o -o $@
	@ echo "$(GREEN)<<<<<<<<<< PUSH_SWAP >>>>>>>>>>"
	
#bonus: all
show:
	./push_swap_visualizer/build/bin/visualizer
test:
	@./run.sh -500 500 100

tester:
	./push_swap_tester/loop.sh 100 100

clean:
	make -C $(LIB) clean
	$(RM) *.o

fclean:
	make -C $(LIB) fclean
	$(RM) $(NAME)

re : fclean all

PHONEY: all clean fclean re bonus
