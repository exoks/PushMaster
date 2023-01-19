# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzaou <oezzaou@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 16:46:00 by oezzaou           #+#    #+#              #
#    Updated: 2023/01/19 21:46:10 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME := push_swap
CHECKER := checker
SRCM := push_swap push_swap_process push_swap_instructions push_swap_algorithm push_swap_utils
SRCB := checker push_swap_instructions push_swap_process push_swap_utils
LIB := libft/
INC := include/
SRCDIR := src/
OBJDIR := obj/

##################### COMPILER ###################
CC := gcc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

###################### SRCS ######################
OBJM := $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCM)))
SRCM := $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCM)))

OBJB := $(addprefix $(OBJDIR), $(addsuffix .o, $(SRCB)))
SRCB := $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCB)))

##################################################
#     				COLORS     					 #
##################################################
GREEN := \033[1;32m
RED := \033[1;31m
CYAN := \033[1;36m
NOCLR := \033[1;0m

all: $(OBJDIR) $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -I $(INC) -I $(LIB) -c $^ -o $@
	@echo "Compling $^ ..."

$(OBJDIR): 
	@mkdir -p $@

$(NAME): | $(OBJM)
	@echo "*.o ==========> obj/."
	@make -C $(LIB)
	@$(CC) $(CFLAGS) -I $(INC) -I $(LIB) $| $(LIB)*.o -o $@
	@echo "\n$(GREEN)<<<<<<<<<< PUSH_SWAP >>>>>>>>>>\n"

bonus: $(OBJDIR) $(CHECKER)

$(CHECKER): | $(OBJB)
	@echo "*.o ===========> obj/."
	@make -s -C $(LIB) all
	@$(CC) $(CFLAGS) -I $(INC) -I $(LIB) $| $(LIB)*.o -o $@
	@echo "\n$(GREEN)<<<<<<<<<< CHECKER >>>>>>>>>>\n"

clean:
	@make -C $(LIB) clean
	@$(RM) $(OBJDIR)*.o
	@echo "Cleaning done\n"

fclean: clean
	@make -C $(LIB) fclean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@$(RM) -rf $(OBJDIR)
	@echo "Full Cleaning done\n"

re : fclean all

show:
	./push_swap_visualizer/build/bin/visualizer

test:
	@./run.sh 0 10 3

tester:
	./push_swap_tester/loop.sh 100 100

PHONEY: all clean fclean re bonus show test tester
